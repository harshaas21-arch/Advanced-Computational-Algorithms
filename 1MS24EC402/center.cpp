#include <iostream>
#include <unordered_map>

struct Node {
    int id;
    Node* next;
    Node(int val) : id(val), next(nullptr) {}
};

// Floyd's Cycle Check to ensure list is linear before finding middle
bool hasCycle(Node* head) {
    if (!head || !head->next) return false;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Two-Pointer Middle Node Finder
// Time: O(n) | Space: O(1)
Node* findMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Fast advances two nodes; slow advances one node
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Safe heap cleanup
void freeGraph(const std::unordered_map<int, Node*>& nodeMap) {
    for (const auto& pair : nodeMap) {
        delete pair.second;
    }
}

int main() {
    std::unordered_map<int, Node*> nodeMap;

    std::cout << "=== Interactive Linked List Middle Finder ===\n";
    std::cout << "Define connections as: <from_id> <to_id>\n";
    std::cout << "Use -1 for <to_id> to indicate nullptr (end of list).\n";
    std::cout << "Enter -1 -1 when you are finished.\n\n";

    int startId = -1;
    bool isFirstEdge = true;

    while (true) {
        int from, to;
        std::cout << "Enter connection (from to): ";
        if (!(std::cin >> from >> to)) break;

        if (from == -1 && to == -1) break;

        // The source of the first connection is treated as the head
        if (isFirstEdge) {
            startId = from;
            isFirstEdge = false;
        }

        // Allocate or fetch 'from' node
        if (nodeMap.find(from) == nodeMap.end()) {
            nodeMap[from] = new Node(from);
        }

        // Wire pointer
        if (to == -1) {
            nodeMap[from]->next = nullptr;
        } else {
            if (nodeMap.find(to) == nodeMap.end()) {
                nodeMap[to] = new Node(to);
            }
            nodeMap[from]->next = nodeMap[to];
        }
    }

    if (startId == -1 || nodeMap.find(startId) == nodeMap.end()) {
        std::cout << "\nError: No valid linked list entered.\n";
        freeGraph(nodeMap);
        return 0;
    }

    Node* head = nodeMap[startId];

    // Check if the list contains a cycle (middle is undefined on cyclical structures)
    if (hasCycle(head)) {
        std::cout << "\nError: Cycle detected in the linked list!\n";
        std::cout << "A cyclic list has no end, so a middle node cannot be determined.\n";
        freeGraph(nodeMap);
        return 0;
    }

    // Print path traversal
    std::cout << "\nList Traversal: ";
    Node* curr = head;
    int count = 0;
    while (curr) {
        std::cout << curr->id;
        if (curr->next) std::cout << " -> ";
        curr = curr->next;
        count++;
    }
    std::cout << " -> nullptr (" << count << " nodes)\n";

    // Locate the middle node
    Node* middle = findMiddle(head);

    std::cout << "\n---------------- Result ----------------\n";
    std::cout << "Middle Node ID: " << middle->id << "\n";
    if (count % 2 == 0) {
        std::cout << "Note: Even length list; returned the second middle node.\n";
    } else {
        std::cout << "Note: Odd length list; returned the exact center node.\n";
    }
    std::cout << "----------------------------------------\n";

    freeGraph(nodeMap);
    return 0;
}