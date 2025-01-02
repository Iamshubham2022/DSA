class Solution {
public:
    void check(vector<vector<int>>& matrix, int& top, int& bottom, int& left,
               int& right, vector<int>& ans) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--; // Move the right boundary left

        // Traverse from right to left along the bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--; // Move the bottom boundary up
        }

        // Traverse from bottom to top along the left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++; // Move the left boundary right
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {}; // Handle empty matrix case

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            check(matrix, top, bottom, left, right, ans);
        }

        return ans;
    }
};
