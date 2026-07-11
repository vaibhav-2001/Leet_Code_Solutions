class Solution 
{
private:
    void letterCombinationsHelper(int index , string digits , vector<string> &asnwer , string combos[] , string s)
    {
        if(index == digits.size())
        {
            asnwer.push_back(s);
            return;
        }
        int number = digits[index] - '0';
        for(int i=0;i<combos[number].size();i++)
        {
            letterCombinationsHelper(index + 1 , digits , asnwer , combos , s + combos[number][i]);
        }
    }    
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> asnwer;
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string s = "";
        letterCombinationsHelper(0 , digits , asnwer , combos , s);
        return asnwer;
    }
};