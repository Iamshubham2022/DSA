

// find just greater element form the array and exchange smaller element  with the greater element 
// like 7 2 4 6 3
// 7 > 2 swap 
// 2 7 4 6 3
// 7>4 swap 
// 2 4 7 6 3
// 7> 6 swap 
// 2 4 6 7 3
// 7>3 swap 
// 2 4 6 3 7 
// 6>3 swap
// 2 4 3 6 7 
// 4>3 swap
// 2 3 4 6 7


#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0 ;i< n ;i++){
            bool flag = true;
            for(int j=0 ;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    flag =false;
                    
                }
            }
            if(flag){
                break;
            }
        }
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends