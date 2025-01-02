
1. sorted anything 
2. find something in range 

int  mid = low +(high-low)/2   //for long long  it will not overflow


int binarySearch(vector<int>& nums, int low, int high, int target) {

    if (low > high) return -1; //Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    else return binarySearch(nums, low, mid - 1, target);
}


lower bound smallest index such that (arr[i]>=target)
array = {3,5,8,13,19}
if target = 8,9,16,20
lb = 2,3,4,5 last hypothetical index or size of array 
// if there is no element possible, keep it in mind 
that always answer will be the size of array


upper bound smallest index such that (arr[i]>target)
array = {3,5,8,13,19}
if target = 8,9,16,20
lb = 3,3,4,5 last hypothetical index or size of array 
// if there is no element possible, keep it in mind 
that always answer will be the size of array

Floor of x is the largest element which is smaller than or equal to x.
Floor of x doesn’t exist if x is smaller than smallest element of arr[].    x<arr[0]
Ceil of x is the smallest element which is greater than or equal to x. 
Ceil of x doesn’t exist if x is greater than greatest element of arr[].     x>arr[n]


