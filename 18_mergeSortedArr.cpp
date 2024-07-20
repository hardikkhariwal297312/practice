class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i=0,j=0;
        vector<int> ans;
        while(i<m and j<n){
            if(a[i]>b[j]){
                ans.push_back(b[j]);j++;
            }
            else{ans.push_back(a[i]);i++;}
        }
        while(i<m){
            ans.push_back(a[i]);i++;
        }
        while(j<n){
            ans.push_back(b[j]);j++;
        }
        a.clear();
        for(int i=0;i<ans.size();i++){
            a.push_back(ans[i]);
        }
    }
};
