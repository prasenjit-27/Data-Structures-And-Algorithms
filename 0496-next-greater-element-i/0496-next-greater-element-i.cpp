class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n= nums1.size();
        int m= nums2.size();

        vector<int> ans;

        for(int i = 0; i<n; i++){

            for(int j = 0; j<m; j++){

                if(nums1[i] == nums2[j]){

                    int temp = nums2[j];

                    bool flag = true;

                    for(int k = j; k <m; k++){

                        if(temp < nums2[k]){

                            ans.push_back(nums2[k]);
                            flag = false;
                            break;
                        }



                    }

                    if(flag){

                        ans.push_back(-1);
                    }


                }
            }
        }

        return ans;
        
    }
};