class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int prefix = 1; 
        int suffex = 1;
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(prefix == 0) prefix = 1;
            if(suffex == 0) suffex = 1;

            prefix = prefix * nums[i];
            suffex = suffex * nums[n-i-1];

            maxi = max(maxi,max(prefix,suffex)); 
        }

        return maxi;
    }
};