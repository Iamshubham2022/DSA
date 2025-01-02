The intuition of the algorithm is not to consider the
 subarray as a part of the answer if its sum is less than 0.
 A subarray with a sum less than 0 will always reduce our 
 answer and so this type of subarray cannot be a part of the 
 subarray with maximum sum.

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        
        for(int i= 0;i< n ;i++){
            sum += nums[i];
            ans = max(ans,sum); 
            if(sum<0){ //jab bhi sum negative ho to use zero kar do coz ohh next time value ko decrease hi kare ga 
                sum=0;
            }
        }
        return ans;
    }