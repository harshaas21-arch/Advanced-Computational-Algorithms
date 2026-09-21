#include <iostream>
#include <vector>
using namespace std;
bool isMinHeap(const std::vector<int> &arr)
{
       int n = arr.size();
       for (int i = (n - 2) / 2; i >= 0; i--)
       {
              int leftChild = 2 * i + 1;
              if (arr[leftChild] < arr[i])
              {
                     return false;
              }
              int rightChild = 2 * i + 2;
              if (rightChild < n && arr[rightChild] < arr[i])
              {
                     return false;
              }
       }
       return true;
}
int main()
{
       int n;
       cin >> n;
       vector<int> heapArray(n);
       for (int i = 0; i < n; i++)
       {
              cin >> heapArray[i];
       }
       if (isMinHeap(heapArray))
       {
              std::cout << "True: The array is a valid min-heap!" << std::endl;
       }
       else
       {
              std::cout << "False: The array violates min-heap rules." << std::endl;
       }
       return 0;
}
