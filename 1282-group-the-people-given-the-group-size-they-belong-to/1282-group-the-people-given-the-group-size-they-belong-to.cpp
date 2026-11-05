#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
        std::unordered_map<int, std::vector<int>> groups;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            groups[size].push_back(i);
            
            if (groups[size].size() == size) {
                result.push_back(groups[size]);
                groups[size].clear();
            }
        }

        return result;
    }
};