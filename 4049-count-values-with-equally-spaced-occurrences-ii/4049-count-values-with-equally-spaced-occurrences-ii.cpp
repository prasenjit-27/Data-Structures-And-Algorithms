#include <vector>
#include <unordered_map>

class Solution {
public:
    int countSpecialIntegers(std::vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }
        
        int count = 0;
        for (auto& pair : pos) {
            const auto& indices = pair.second;
            if (indices.size() < 3) continue;
            
            int diff = indices[1] - indices[0];
            bool special = true;
            for (size_t i = 2; i < indices.size(); ++i) {
                if (indices[i] - indices[i - 1] != diff) {
                    special = false;
                    break;
                }
            }
            if (special) {
                count++;
            }
        }
        
        return count;
    }
};