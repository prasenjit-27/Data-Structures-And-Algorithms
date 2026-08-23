class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1 = 0, sum2 = 0;
        int count1 = 0, count2 = 0;
        
        int mid = n / 2;
        for (int i = 0; i < mid; ++i) {
            if (num[i] == '?') {
                count1++;
            } else {
                sum1 += num[i] - '0';
            }
        }
        
        for (int i = mid; i < n; ++i) {
            if (num[i] == '?') {
                count2++;
            } else {
                sum2 += num[i] - '0';
            }
        }
        
        if ((count1 + count2) % 2 != 0) {
            return true;
        }
        
        return (sum1 - sum2) != 9 * (count2 - count1) / 2;
    }
};