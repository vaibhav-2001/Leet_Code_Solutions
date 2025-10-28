class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        int last_smallest = INT_MIN;
        int largest = 1;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] - 1 == last_smallest)
            {
                count += 1;
                last_smallest = nums[i];
            }
            else if(nums[i] != last_smallest)
            {
                count = 1;
                last_smallest = nums[i];
            }
            largest = max(largest,count);
        }
        return largest;
    }
};