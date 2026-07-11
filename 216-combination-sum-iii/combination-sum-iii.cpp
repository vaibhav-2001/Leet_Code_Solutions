class Solution 
{
    private:
        void combinationSum3Helper(int last , vector<vector<int>> &answer , vector<int> &arr , int k , int sum)
        {
            if(sum == 0 && arr.size() == k)
            {
                answer.push_back(arr);
                return;
            }
            if(sum < 0 || arr.size() > k) return;
            for(int i=last ; i<=9 ; i++)
            {
                if(i <= sum)
                {
                    arr.push_back(i);
                    combinationSum3Helper(i+1 , answer , arr , k , sum - i);
                    arr.pop_back();
                } else {
                    break;
                }
            }
            
        }
    public:
        vector<vector<int> > combinationSum3(int k, int n)
        {
            vector<vector<int>> answer;
            vector<int> arr;
            combinationSum3Helper(1 , answer , arr , k , n);
            return answer;
        }
};