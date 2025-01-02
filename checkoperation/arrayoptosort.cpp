#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

// Function to find the minimum number of swaps required to sort the array
int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> paired(n);
        for (int i = 0; i < n; i++) {
            paired[i] = {arr[i], i};
        }
        sort(paired.begin(), paired.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ( paired[i].second == i) {
                continue;
            }
            else{
                cnt++;
                swap(paired[i],paired[paired[i].second]);
                i--;
            }
        }
        return cnt;
    }

// Example usage
int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << "Minimum swaps required: " << minSwapsToSort(arr) << endl;
    return 0;
}
