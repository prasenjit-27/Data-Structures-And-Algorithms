class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        double prev = 0;
        double curr = 0;

        int i = 0;
        int j = 0;

        for (int k = 0; k <= total / 2; k++) {

            prev = curr;

            if (i < n && j < m) {

                if (nums1[i] <= nums2[j]) {

                    curr = nums1[i++];

                } else {

                    curr = nums2[j++];
                }
            } else if (i < n) {

                curr = nums1[i++];
            } else {

                curr = nums2[j++];
            }
        }

        if (total % 2 == 1)
            return curr;
        else
            return (curr + prev) / 2.0;
    }
};