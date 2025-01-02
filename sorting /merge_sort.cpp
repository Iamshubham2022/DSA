class Solution {
public:
    void merge_sort(int left, int mid, int right, vector<int>& nums) {
        int l = left;
        int r = mid+1;
        vector<int>res;
        while (l <=mid && r <=right) {
            if(nums[l]>=nums[r]){
                res.push_back(nums[r]);
                r++;
            }
            else{
                res.push_back(nums[l]);
                l++;
            }
        }
        while(l<=mid){
            res.push_back(nums[l]);
            l++;
        }
        while(r<=right){
            res.push_back(nums[r]);
            r++;
        }
        for(int i = left ;i<=right ;i++){
            nums[i]=res[i-left];
        }
    }

    void split(int left, int right, vector<int>& nums) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        split(left, mid, nums);
        split(mid + 1, right, nums);
        merge_sort(left, mid, right, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        split(0, nums.size()-1, nums);
       return nums;
    }
};