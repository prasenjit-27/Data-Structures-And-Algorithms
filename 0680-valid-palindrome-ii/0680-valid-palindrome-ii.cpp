class Solution {
public:

    bool checker(string& s,int left, int right){


        while(left <= right){

            if(s[left] != s[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
    bool validPalindrome(string s) {

        int n = s.size();
        int i = 0, j = n-1;

        while(i <= j){

            if(s[i] != s[j]){

                bool a = checker(s,i+1,j);
                bool b = checker(s,i,j-1);

                if(a || b) return true;
                else return false;


            }

            i++;
            j--;
        }

        return true;
        
    }
};