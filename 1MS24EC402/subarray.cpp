#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void findSubarrayWithSum(const vector<int>& arr, int target) {
    // Maps prefix_sum to its corresponding index
    unordered_map<int, int> sum_map;
    int current_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        current_sum += arr[i];
        // Case 1: The subarray starts from index 0
        if (current_sum == target) {
            cout << "Subarray found from index 0 to " << i << endl;
            return;
        }
        // Case 2: If (current_sum - target) exists in the map, 
        // a subarray with the target sum exists between the stored index + 1 and i
        if (sum_map.find(current_sum - target) != sum_map.end()) {
            cout << "Subarray found from index " << sum_map[current_sum - target] + 1 << " to " << i << endl;
            return;
        }
        // Store the prefix sum with its index if not already present
        // (Keeping the earliest index handles edge cases if there are zeros)
        if (sum_map.find(current_sum) == sum_map.end()) {
            sum_map[current_sum] = i;
        }
    }
    cout << "No subarray with the given sum found." << endl;
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter target sum: ";
    cin >> target;
    findSubarrayWithSum(arr, target);
    return 0;
}
