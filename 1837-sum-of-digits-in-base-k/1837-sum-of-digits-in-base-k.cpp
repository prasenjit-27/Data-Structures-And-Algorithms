class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        while (n > 0) {
            sum += n % k; // Add the current last digit
            n /= k;       // Move to the next digit place
        }
        return sum;
    }
};