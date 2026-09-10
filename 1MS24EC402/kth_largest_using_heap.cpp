#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main()
{
       int n;
       cin >> n;
       vector<int> arr(n);
       for (int i = 0; i < n; i++)
       {
              cin >> arr[i];
       }
       int k;
       cin >> k;
       priority_queue<int, vector<int>, greater<int> > min_heap;

       for (int i = 0; i < n; i++)
       {
              min_heap.push(arr[i]);

              if (min_heap.size() > k)
              {
                     min_heap.pop();
              }
       }

       cout << min_heap.top() << "\n";

       return 0;
}