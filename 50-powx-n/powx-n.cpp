class Solution 
{
private:
    double power_help(double x , long long n)
    {
        if(n == 0) return 1.0;
        if(n == 1) return x;

        if(n % 2 == 1) return x * power_help(x , n-1);
        else
        return power_help(x * x , n/2);
    }
public:
    double myPow(double x, int n)
    {
        // 1) brute:-

        // if(1.0 == x) return 1.0;
        // if(0 == n) return 1.0;

        // double answer = 1.0;
        // long long temp = n;
        // if(n < 0)
        // {
        //     x = 1/x;
        //     temp = -1*1LL*n;
        // }

        // for(long long i=1;i<=temp;i++)
        // {
        //     answer *= x;
        // }
        // return answer;

        // 2) Optimal:-
        long long num = n;
        if(num < 0)
        {
            return(1/power_help(x , -num));
        }
        return power_help(x , num);
    }
};