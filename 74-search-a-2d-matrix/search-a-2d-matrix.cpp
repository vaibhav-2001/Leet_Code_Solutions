class Solution
{
    private:
        bool Binary_Search(vector<int> &mat , int target)
        {
            int n = mat.size();

            int low = 0;
            int high = n - 1;
            while(low <= high)
            {
                int mid = low + (high - low) / 2;
                if(mat[mid] == target)
                {
                    return true;
                }
                else if (mat[mid] > target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return false;
        }
    public:
        bool searchMatrix(vector<vector<int>> &mat, int target)
        {
            // 1) Brute:-
            // bool search = false;

            // int n = mat.size();
            // int m = mat[0].size();

            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<m;j++)
            //     {
            //         if(target == mat[i][j])
            //         {
            //             search = true;
            //         }
            //     }
            // }
            // return search;

            // 2) Better:-

            // int n = mat.size();
            // int m = mat[0].size();

            // for(int i=0;i<n;i++)
            // {
            //     if(mat[i][0] <= target && mat[i][m-1] >= target)
            //     {
            //         return Binary_Search(mat[i] , target);
            //     }
            // }
            // return false;

            // 3) Optimal:-

            // int n = mat.size();
            // int m = mat[0].size();

            int low = 0;
            int high = mat.size() * mat[0].size() - 1;

            while(low <= high)
            {
                int mid = low + (high - low) / 2;
                if(mat[mid / mat[0].size()][mid % mat[0].size()] == target) return true;
                else if(mat[mid / mat[0].size()][mid % mat[0].size()] > target) 
                {
                    high = mid - 1;
                }
                else 
                {
                    low = mid + 1;
                }
            }
            return false;
        }    
    
};