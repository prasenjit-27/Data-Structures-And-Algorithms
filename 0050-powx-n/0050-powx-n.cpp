class Solution {
public:
    double myPow(double x, int n) {

        if (n == 1)
            return x;
        if (n == 0)
            return 1;

        double ans = 1;
        long long exp = n;

        if (n < 0) {

            x = 1 / x;
            exp = -exp;
        }

        while (exp > 0) {

            if (exp % 2 != 0)
                ans *= x;

            x *= x;

            exp /= 2;
        }

        return ans;
    }
};