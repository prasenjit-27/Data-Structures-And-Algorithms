class Solution {
public:
    int isPossible(int n) {

        int sum = 0;

        while (n != 0) {

            sum += pow(n % 10, 2);
            n /= 10;
        }

        return sum;
    }
    bool isHappy(int n) {

        bool flag = true;

        unordered_set<int> set;

        while (flag) {

            n = isPossible(n);

            if (n == 1)
                return true;
            else {

                if (set.find(n) != set.end())
                    return false;

                set.insert(n);
            }
        }

        return false;
    }
};