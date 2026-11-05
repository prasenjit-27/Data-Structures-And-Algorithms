class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;
        map<long long, int> bucketMap;
        long long bucketSize = (long long)valueDiff + 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            long long bucket = nums[i] / bucketSize;
            if (nums[i] < 0) bucket--;
            
            if (bucketMap.find(bucket) != bucketMap.end()) return true;
            if (bucketMap.find(bucket - 1) != bucketMap.end() && abs(nums[i] - bucketMap[bucket - 1]) <= valueDiff) return true;
            if (bucketMap.find(bucket + 1) != bucketMap.end() && abs(nums[i] - bucketMap[bucket + 1]) <= valueDiff) return true;
            
            bucketMap[bucket] = nums[i];
            
            if (i >= indexDiff) {
                long long oldBucket = nums[i - indexDiff] / bucketSize;
                if (nums[i - indexDiff] < 0) oldBucket--;
                bucketMap.erase(oldBucket);
            }
        }
        return false;
    }
};