


    // 1 book allocation in k student
    // 2 partition array in two k part
    // 3 Split Array Largest Sum
    // 4 Maximum Candies Allocated to K Children



class Solution {
public:
    bool canSplit(vector<int>& nums, int mid, int k) {
        int currentSum = 0, splits = 1; 
        for (int num : nums) {
            if (currentSum + num > mid) {
                splits++; 
                currentSum = num;
                if (splits > k) return false; 
            } else {
                currentSum += num;
            }
        }
        return true; 
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0);
        int result = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canSplit(nums, mid, k)) {
                result = mid; 
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return result;
    }
};

