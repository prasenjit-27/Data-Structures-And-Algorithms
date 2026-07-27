class Solution {
public:
    double power(double x, long long exp, double ans) {

        if (exp <= 0)
            return ans;

        if (exp % 2 != 0)
            ans *= x;

        return power(x * x, exp / 2, ans);
    }

    double myPow(double x, int n) {

        long long exp = n;

        if (n < 0) {

            x = 1 / x;
            exp = -exp;
        }

        return power(x, exp, 1);
    }
};