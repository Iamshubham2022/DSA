#include <bitset/stdc++.h>

// select smallest element from the array and swap it with first element 
// then do same thing for the next element 


void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        int ind = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (temp > arr[j])
            {
                temp = arr[j];
                ind = j;
            }
        }
        arr[ind] = arr[i];
        arr[i] = temp;
    }
}
