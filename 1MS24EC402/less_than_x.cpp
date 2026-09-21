#include <iostream>
#include <vector>
using namespace std;
void printLessThanX(const std::vector<int> &heap, int i, int x)
{
       int n = heap.size();
       if (i >= n || heap[i] >= x)
       {
              return;
       }
       std::cout << heap[i] << " ";
       printLessThanX(heap, 2 * i + 1, x);
       printLessThanX(heap, 2 * i + 2, x);
}
int main()
{
       int n;
       cout << "Enter the number of elements: " << endl;
       cin >> n;
       cout << "Enter the minheap elements: " << endl;
       vector<int> heap(n);
       for (int i = 0; i < n; i++)
       {
              cin >> heap[i];
       }
       cout << "Enter the value of x: " << endl;
       int x;
       cin >> x;
       std::cout << "Nodes less than " << x << " are: ";
       printLessThanX(heap, 0, x);
       std::cout << std::endl;
       return 0;
}
