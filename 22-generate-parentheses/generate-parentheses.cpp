class Solution 
{
    private:
        void generate(int open , int close , string s , vector<string> &answer , int n)
        {
            if(open < close) return;
            if((open + close) == 2*n && open == close)
            {
                answer.push_back(s);
                return;
            }
            if(open < n)
            {
                generate(open + 1 , close , s + '(' , answer , n);
            }
            if(open > close)
            {
                generate(open , close + 1 , s + ')' , answer , n);
            }
        }
    public:
        vector<string> generateParenthesis(int n)
        {
            int open = 0;
            int close = 0;
            vector<string> answer;
            generate(open , close , "" , answer , n);

            return answer;
        }
};