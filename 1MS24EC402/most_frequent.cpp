#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
       int n;
       cout << "Enter n: " << endl;
       cin >> n;
       vector<int> arr(n);
       unordered_map<int, int> um;
       um.reserve(n);
       cout << "Enter the array elements: " << endl;
       int max_freq = 0;
       int most_freq = -1;
       for (int i = 0; i < n; i++)
       {
              cin >> arr[i];
              um[arr[i]]++;
              if (um[arr[i]] > max_freq)
              {
                     max_freq = um[arr[i]];
                     most_freq = arr[i];
              }
       }
       cout << "The most frequent element in the array is: " << most_freq;
       return 0;
}