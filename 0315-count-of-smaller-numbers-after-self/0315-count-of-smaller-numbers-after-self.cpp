#include <vector>
#include <utility>

class Solution {
private:
    void merge(std::vector<std::pair<int, int>>& arr, int left, int mid, int right, std::vector<int>& counts) {
        int i = left;
        int j = mid + 1;
        int rightCount = 0;
        std::vector<std::pair<int, int>> temp;
        
        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                counts[arr[i].second] += rightCount;
                temp.push_back(arr[i++]);
            } else {
                rightCount++;
                temp.push_back(arr[j++]);
            }
        }
        
        while (i <= mid) {
            counts[arr[i].second] += rightCount;
            temp.push_back(arr[i++]);
        }
        
        while (j <= right) {
            temp.push_back(arr[j++]);
        }
        
        for (int k = left; k <= right; ++k) {
            arr[k] = temp[k - left];
        }
    }

    void mergeSort(std::vector<std::pair<int, int>>& arr, int left, int right, std::vector<int>& counts) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);
        merge(arr, left, mid, right, counts);
    }

public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        std::vector<int> counts(n, 0);
        mergeSort(arr, 0, n - 1, counts);
        return counts;
    }
};