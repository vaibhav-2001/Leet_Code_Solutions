class Solution 
{
    private:
        void calculate(int index ,int  n , vector<int> &nums , vector<int>  &arr , vector<vector<int>> &answer)
        {
            if(index == n)
            {
                answer.push_back(arr);
                return;
            }
            arr.push_back(nums[index]);
            calculate(index + 1 , n , nums , arr , answer);
            arr.pop_back();
            calculate(index + 1 , n , nums , arr , answer);
        }
    public:	
        vector<vector<int> > subsets(vector<int>& nums)
        {
           int n = nums.size();
           vector<int> arr;
           vector<vector<int>> answer;

           calculate(0 , n , nums , arr , answer);

           return answer; 
        }
};