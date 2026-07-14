class Solution 
{
    private:
        bool existhlper(vector<vector<char>> &board , string word , int i , int j , int index)
        {
            if(index == word.size()) return true;

            if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[index] != board[i][j] || board[i][j] == ' ') return false;

            bool answer = false;
            char x = board[i][j];
            board[i][j] = ' ';

            answer |= existhlper(board , word , i - 1 , j , index + 1);
            answer |= existhlper(board , word , i + 1 , j , index + 1);
            answer |= existhlper(board , word , i , j - 1 , index + 1);
            answer |= existhlper(board , word , i , j + 1 , index + 1);

            board[i][j] = x;
            return answer;
        }
    public:
        bool exist(vector<vector<char> >& board, string word)
        {
            int n = board.size();
            int m = board[0].size();

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(word[0] == board[i][j])
                    {
                        if(existhlper(board , word , i , j , 0))
                        return true;
                    }
                }
            }
            return false;
        }
};