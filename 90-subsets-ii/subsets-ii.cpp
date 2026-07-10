class Solution 
{
    private:
        void subsetsWithDupHelper(vector<int> &nums , vector<vector<int>> &answer , vector<int> &arr , int index)
        {
            if(index == nums.size())
            {
                answer.push_back(arr);
                return;
            }
            arr.push_back(nums[index]);
            subsetsWithDupHelper(nums , answer , arr , index + 1);
            arr.pop_back();

            for(int i=index + 1;i<nums.size();i++)
            {
                if(nums[i] != nums[index])
                {
                    subsetsWithDupHelper(nums , answer , arr , i);
                    return;
                }
            }
            subsetsWithDupHelper(nums , answer , arr , nums.size());
        }
    public:
        vector<vector<int> > subsetsWithDup(vector<int>& nums)
        {
            vector<vector<int>> answer;
            vector<int> arr;
            sort(nums.begin() , nums.end());
            subsetsWithDupHelper(nums , answer , arr , 0);
            return answer;
        }
};