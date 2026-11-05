class Solution {
    int count;
    long long lower_bound, upper_bound;

    void mergeSort(vector<long long>& prefixSums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(prefixSums, left, mid);
        mergeSort(prefixSums, mid + 1, right);

        int l = mid + 1, r = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (l <= right && prefixSums[l] - prefixSums[i] < lower_bound) l++;
            while (r <= right && prefixSums[r] - prefixSums[i] <= upper_bound) r++;
            count += (r - l);
        }

        vector<long long> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (prefixSums[i] <= prefixSums[j]) temp.push_back(prefixSums[i++]);
            else temp.push_back(prefixSums[j++]);
        }
        while (i <= mid) temp.push_back(prefixSums[i++]);
        while (j <= right) temp.push_back(prefixSums[j++]);

        for (int k = 0; k < temp.size(); ++k) {
            prefixSums[left + k] = temp[k];
        }
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        count = 0;
        lower_bound = lower;
        upper_bound = upper;
        mergeSort(prefixSums, 0, n);
        return count;
    }
};