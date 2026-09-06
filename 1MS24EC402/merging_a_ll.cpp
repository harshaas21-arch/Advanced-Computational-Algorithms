#include <iostream>
using namespace std;


struct Node
{
       int data;
       Node *next;


       Node(int val) : data(val), next(NULL) {}
};


int main()
{
       Node *f1 = new Node(10);
       Node *f2 = new Node(20);
       Node *f3 = new Node(30);
       Node *f4 = new Node(40);


       f1->next = f2;
       f2->next = f3;
       f3->next = f4;


       Node *s1 = new Node(5);
       Node *s2 = new Node(15);
       Node *s3 = new Node(25);


       s1->next = s2;
       s2->next = s3;


       Node *head1 = f1;
       Node *head2 = s1;


       Node *dummy = new Node(0);
       Node *curr = dummy;


       while (head1 != NULL && head2 != NULL)
       {
              if (head1->data <= head2->data)
              {
                     curr->next = new Node(head1->data);
                     head1 = head1->next;
              }
              else
              {
                     curr->next = new Node(head2->data);
                     head2 = head2->next;
              }
              curr = curr->next;
       }


       while (head1 != NULL)
       {
              curr->next = new Node(head1->data);
              head1 = head1->next;
              curr = curr->next;
       }


       while (head2 != NULL)
       {
              curr->next = new Node(head2->data);
              head2 = head2->next;
              curr = curr->next;
       }


       Node *result = dummy->next;
       while (result != NULL)
       {
              cout << "Node value: " << result->data << endl;
              result = result->next;
       }
       delete f1, f2, f3, f4, s1, s2, s3;
       return 0;
}
