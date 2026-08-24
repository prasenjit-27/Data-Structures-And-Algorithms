class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;
        
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] >= arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] > arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }
        
        long long total = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            total = (total + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        
        return total;
    }
};