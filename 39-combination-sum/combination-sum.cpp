class Solution 
{
    private:
        void combinationSumHelper(vector<int> &nums , vector<int> &arr , vector<vector<int>> &answer , int index , int target)
        {
            if(target == 0)
            {
                answer.push_back(arr);
                return;
            }
            if(target < 0 || index < 0) return;

            arr.push_back(nums[index]);
            combinationSumHelper(nums , arr , answer , index  , target - nums[index]);
            arr.pop_back();
            combinationSumHelper(nums , arr , answer , index - 1 , target);
        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target)
        {
            vector<vector<int>> answer;
            vector<int> arr;
            combinationSumHelper(candidates , arr , answer , candidates.size() - 1 , target);
            return answer;
        }
};