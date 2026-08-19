class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rowMasks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }
        
        int totalGroups = 2 * n;
        
        int leftMask = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
        int rightMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int middleMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        
        for (const auto& pair : rowMasks) {
            int mask = pair.second;
            bool canPlaceLeft = (mask & leftMask) == 0;
            bool canPlaceRight = (mask & rightMask) == 0;
            bool canPlaceMiddle = (mask & middleMask) == 0;
            
            if (canPlaceLeft && canPlaceRight) {
                continue;
            } else if (canPlaceLeft || canPlaceRight || canPlaceMiddle) {
                totalGroups -= 1;
            } else {
                totalGroups -= 2;
            }
        }
        
        return totalGroups;
        
    }
};