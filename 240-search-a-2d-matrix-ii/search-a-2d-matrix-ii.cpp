class Solution
{
    private:
    int Binary_Search(vector<int> &matrix , int target)
    {
        int n = matrix.size();
        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(matrix[mid] == target)
            {
                return mid;
            }
            else if(matrix[mid] > target)
            {
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        return -1;
    }
    public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        // 1) Better:-
        // for(int i=0;i<n;i++)
        // {
        //     int index = Binary_Search(matrix[i] , target);
        //     if(index != -1)
        //     {
        //         return true;
        //     }
        // }
        // return false;

        // 2) Optimal:-

        int row = 0;
        int column = m - 1;

        while(row < n && column >= 0)
        {
            if(matrix[row][column] == target)
            {
                return true;
            }
            else if(matrix[row][column] > target)
            {
                column--;
            }
            else
            {
                row++;
            }
        }
        return false;
}
};