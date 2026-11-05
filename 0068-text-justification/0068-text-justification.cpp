class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            int j = i;
            int len = 0;
            
            while (j < n && len + words[j].length() + (j - i) <= maxWidth) {
                len += words[j].length();
                j++;
            }
            
            string line = "";
            int numWords = j - i;
            int spacesNeeded = maxWidth - len;
            
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } else {
                int spacesBetween = spacesNeeded / (numWords - 1);
                int extraSpaces = spacesNeeded % (numWords - 1);
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = spacesBetween + (k - i < extraSpaces ? 1 : 0);
                        line += string(spacesToAdd, ' ');
                    }
                }
            }
            
            res.push_back(line);
            i = j;
        }
        
        return res;
    }
};