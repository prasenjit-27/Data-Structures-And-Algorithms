class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;

        int row = -1;

        while (top <= bottom) {

            int mid = top + (bottom - top) / 2;

            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {

                row = mid;
                break;
            } else if (target < matrix[mid][0]) {

                bottom = mid - 1;
            } else {

                top = mid + 1;
            }
        }

        if (row == -1)
            return false;

        int left = 0;
        int right = n - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target)
                return true;
            else if (target < matrix[row][mid])
                right = mid -1;
            else
                left = mid + 1;
        }

        return false;
    }
};