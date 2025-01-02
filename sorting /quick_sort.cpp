#include<bits/stdc++.h>
using namespace std;

// pick a pivat ,it can be mid ,first,last,or any random 
// place it at its correct position.
// smaller in the left ,larger in the right  
// apply this step again and again 

// its kind of recursion

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends
class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
           int p = partition(arr,low,high);
           quickSort(arr,low,p-1);
           quickSort(arr,p+1,high);
        }
        return ;
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        int pivat = arr[low];
        int i = low;
        int j = high;
        while(i<j){
           while(arr[i]<=pivat && i<=j){
               i++;
           }
           while(arr[j]>pivat && i<=j){
               j--;
           }
           if(i<j){
            swap(arr[i],arr[j]);
           }
        }
        swap(arr[low],arr[j]);
        return j;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends

