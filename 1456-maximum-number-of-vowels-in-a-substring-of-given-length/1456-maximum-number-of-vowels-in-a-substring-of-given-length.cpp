class Solution {
public:

    bool isVowel(char x){

        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;

        return false;
    }
    int maxVowels(string s, int k) {

        int n= s.size();

        int count  = 0;
        int maxi = 0;

        for(int i = 0; i<k; i++){

            if(isVowel(s[i])) count++;


        }

        maxi = max(count,maxi);

        int i = 0;

        for(int j = k; j<n; j++){

            if(isVowel(s[j])) count++;

            if(isVowel(s[i])) count--;

            i++;

            maxi = max(maxi,count);
        }

        return maxi;
        
    }
};