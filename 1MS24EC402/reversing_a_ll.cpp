#include <iostream>
using namespace std;


struct Node
{
       int data;
       Node *next;
};


int main()
{
       Node *first = new Node();
       Node *second = new Node();
       Node *third = new Node();
       Node *fourth = new Node();


       first->data = 10;
       second->data = 20;
       third->data = 30;
       fourth->data = 40;


       first->next = second;
       second->next = third;
       third->next = fourth;
       fourth->next = NULL;


       Node *temp = first;
       cout << "Initial list: " << endl;
       while (temp != NULL)
       {
              cout << "Node value: " << temp->data << " at address: " << temp << endl;
              temp = temp->next;
       }


       Node *curr = first;
       Node *prev = NULL;
       Node *nextNode = NULL;


       while (curr != NULL)
       {
              nextNode = curr->next;
              curr->next = prev;
              prev = curr;
              curr = nextNode;
       }


       Node *newhead = prev;
       cout << "Reversed List: " << endl;
       temp = newhead;
       while (temp != NULL)
       {
              cout << "Node value: " << temp->data << " at address: " << temp << endl;
              temp = temp->next;
       }
       delete first;
       delete second;
       delete third;
       delete fourth;
       return 0;
}
