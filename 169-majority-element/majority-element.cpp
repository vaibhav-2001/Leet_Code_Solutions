class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 0;
        int element = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(count == 0)
            {
                count = 1;
                element = nums[i]; 
            }
            else if(nums[i] == element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        int count2 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == element)
            {
                count2++;
            }
        }
        if(count2 > n/2)
        {
            return element;
        }

        return -1;
    }
};