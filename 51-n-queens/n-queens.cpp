class Solution 
{
    private:
        bool isSafe(vector<string> &board ,  int row , int col)
        {
            int r = row , c = col;
            while(r >= 0)
            {
                if(board[r--][c] == 'Q') return false;
            }
            r = row , c = col;
            while(r >= 0 && c >= 0)
            {
                if(board[r--][c--] == 'Q') return false;
            }
            r = row , c = col;
            while(r >= 0 && c < board.size())
            {
                if(board[r--][c++] == 'Q') return false;
            }

            return true;
        }
        void solveNQueensHelper(vector<vector<string>> &answer , vector<string> &board , int n , int row)
        {
            if(row == board.size())
            {
                answer.push_back(board);
                return;
            }
            for(int col = 0 ; col < board.size() ; col++)
            {
                if(isSafe(board , row , col))
                {
                    board[row][col] = 'Q';
                    solveNQueensHelper(answer , board , n , row + 1);
                    board[row][col] = '.';
                }
            }
        }
    public:
        vector<vector<string> > solveNQueens(int n)
        {
            vector<vector<string>> answer;
            vector<string> board(n , string(n , '.'));
            solveNQueensHelper(answer , board , n , 0);
            return answer;
    }
};