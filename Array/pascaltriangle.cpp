1 1 1 1 2 1 1 3 3 1 1 4 6 4 1

        // 1. find the element where row=x and col =y;
        Ans : x -1
                 c
                 y -1
              `   1.(x - 1) ! / (y - 1) !*(x - y) !find all factoral
                  and solve this this is brute force,this might take more time 
                   
    2. 
    long long funcNcR(int x-1, int y-1)
        {
            long long  res = 1;
            for (int i = 0; i < y; i++)
            {
                res = res * (x - i);
                res = res / (i + 1);
            }
            return res;
        }
    3.


// 2. print any nth row of pascal's triangle;

    1.  void printRow(int n){           // O(n*r) time complexity
            for(int c=1;c<n;c++){
                cout<<funcNcR(n-,c-1)<<" ";
            }
        }

    2.  long long printRow(int row)   // O(n) time complexity
        {
            long long  res = 1;
            for (int col = 0; col < row; col++)
            {
                res = res * (row - col);
                res = res / (col );
                cout<<res<<" ";
            }
            
        }


// 3. print pascal triangle
    1.  vector<vector<int>> generate(int n){
            vector<vector<int>> ans(n);
            for (int row = 1; row <=n; i=row++)
            {   vector<int>temp;
                long long  res = 1;
                for (int col = 0; col < row; col++)
                    {
                        res = res * (row - col);
                        res = res / (col );
                        temp.push_back(res);
                    }
                ans.push_back(temp);
            }
        }



class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans(n);
        if (n == 0)
            return ans;
        ans[0].push_back(1); // initally push 1 in vector first;
        for (int i = 1; i < n; i++)
        {
            int m = ans[i - 1].size() + 1; // find the size() for the next vector
            for (int j = 0; j < m; j++)
            {
                if (j == 0 || j == m - 1)
                { // first and last element should be the copy of the previous or same of the previous
                    ans[i].push_back(1);
                }
                else
                {
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
        }
        return ans;
    }
};