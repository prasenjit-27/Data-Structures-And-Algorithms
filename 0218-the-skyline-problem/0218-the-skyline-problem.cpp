#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
        std::vector<std::vector<int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2], b[1]});
            events.push_back({b[1], b[2], 0});
        }
        
        std::sort(events.begin(), events.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        std::vector<std::vector<int>> result;
        std::priority_queue<int> maxHeap;
        std::priority_queue<int> delayed;
        maxHeap.push(0);
        
        int prevMax = 0;
        
        for (const auto& event : events) {
            int x = event[0];
            int h = event[1];
            
            if (h < 0) {
                maxHeap.push(-h);
            } else {
                delayed.push(h);
            }
            
            while (!delayed.empty() && maxHeap.top() == delayed.top()) {
                maxHeap.pop();
                delayed.pop();
            }
            
            int currMax = maxHeap.top();
            if (currMax != prevMax) {
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }
        
        return result;
    }
};