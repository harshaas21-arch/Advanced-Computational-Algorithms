#include <iostream>
#include <unordered_map>
#include <unordered_set>

struct Node {
    int id;
    Node* next;
    Node(int val) : id(val), next(nullptr) {}
};

// Floyd's Cycle Detection: O(n) Time, O(1) Auxiliary Space
bool detectLoop(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    return false; // Fast reached null terminator
}

// Safely cleanup all nodes in memory
void freeGraph(const std::unordered_map<int, Node*>& nodeMap) {
    for (const auto& pair : nodeMap) {
        delete pair.second;
    }
}

int main() {
    std::unordered_map<int, Node*> nodeMap;

    std::cout << "=== Interactive Linked List Builder ===\n";
    std::cout << "Define connections as: <from_id> <to_id>\n";
    std::cout << "Use -1 for <to_id> to indicate nullptr (end of a branch).\n";
    std::cout << "Enter -1 -1 when you are done adding connections.\n\n";

    int startId = -1;
    bool isFirstEdge = true;

    while (true) {
        int from, to;
        std::cout << "Enter connection (from to): ";
        if (!(std::cin >> from >> to)) break;

        if (from == -1 && to == -1) break;

        // Track the entry/head node from the first defined connection
        if (isFirstEdge) {
            startId = from;
            isFirstEdge = false;
        }

        // Fetch or create 'from' node
        if (nodeMap.find(from) == nodeMap.end()) {
            nodeMap[from] = new Node(from);
        }

        // Connect to target or nullptr
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
        std::cout << "\nNo valid linked list created.\n";
        freeGraph(nodeMap);
        return 0;
    }

    Node* head = nodeMap[startId];

    // Evaluate using Floyd's cycle detection algorithm
    std::cout << "\nAnalyzing list starting at Head Node (" << head->id << ")...\n";
    bool hasLoop = detectLoop(head);

    std::cout << "\n---------------- Result ----------------\n";
    if (hasLoop) {
        std::cout << "Status: Loop Detected! The pointers encountered a cycle.\n";
    } else {
        std::cout << "Status: Clean list with no loops. Traversed to nullptr.\n";
    }
    std::cout << "----------------------------------------\n";

    freeGraph(nodeMap);
    return 0;
}