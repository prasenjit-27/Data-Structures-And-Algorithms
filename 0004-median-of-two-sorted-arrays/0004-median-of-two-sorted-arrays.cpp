class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        for(auto i: nums2) nums1.push_back(i);
      
      sort(nums1.begin(),nums1.end());
      
      int n = nums1.size();
      
      if(n % 2 != 0){
          
          int val = n/2;
          return nums1[val];
      }
      
      
      int val = n/2;
      int val2 = n/2 - 1;
      
      return (nums1[val] + nums1[val2])/2.0;
    }
};