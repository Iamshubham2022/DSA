1. Longest subarray with sum K (Positives + Negatives)
2. Longest subarray with given sum K(positives)
3. Kadane's Algorithm, maximum subarray sum

4. Count subarrays with given sum                 //based on priffix sum

5. Count number of subarrays with given xor K	 //based on the previous one by using (x^k)^k =XR^k  based on prffix xor 
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>mp;
    int n = A.size();
    int xr =0;
    int cnt = 0;
    mp[0]++;  //this handle edge case
    for(int i=0;i<n;i++){
        xr =xr^A[i];
        if(mp.find(xr^B)!=mp.end()){
            cnt=cnt+mp[xr^B];
        }
        mp[xr]++;
        
    }
    return cnt;
}




6. Longest Consecutive Sequence in an Array


7. Maximum Product Subarray tricky
int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre =1,suff=1;
        int maxi =INT_MIN;
        for(int i= 0;i < n ;i++){
            if(pre==0) pre =1;
            if(suff==0) suff =1;
            pre =pre * nums[i];
            suff = suff * nums[n-i-1];
            maxi =max({maxi,pre ,suff});
        }
        return maxi;
    }