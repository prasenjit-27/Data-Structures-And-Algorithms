class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        int i = 0;

        int maxi = INT_MIN;

        unordered_map<int,int> x;

        for(int j = 0; j<n;j++){

            x[fruits[j]]++;

            while(x.size() > 2){

                x[fruits[i]]--;
                if(x[fruits[i]] == 0){

                    x.erase(fruits[i]);
                    
                }
                i++;
            }

            maxi = max(maxi, j-i + 1);


        }

        return maxi;
        
    }
};