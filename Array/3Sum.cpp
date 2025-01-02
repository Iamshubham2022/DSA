1.	Largest Subarray with 0 Sum
2.  4Sum
3.  3Sum




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>s;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n ;i++){
            int j =i+1;
            int k =n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        for(auto it :s){
            ans.push_back(it);
        }
        return ans;
    }
};