class Solution {
public:
        vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int t=0,b=n-1,l=0,r=m-1;
        vector<int> ans;
        while(t<=b and l<=r){
                if(ans.size()==n*m) break;
            //left to right in top side
            for(int i=l;i<=r;i++){
                    ans.push_back(a[t][i]);}t++;
            //top to bottom in right side;
                // if(ans.size()==n*m) break;
            for(int i=t;i<=b;i++){
                    ans.push_back(a[i][r]);}r--;
            //right to left in bottom side;
                if(ans.size()==n*m) break;
            for(int i=r;i>=l;i--){
                    ans.push_back(a[b][i]);}b--;
            //bottom to top in left side
                // if(ans.size()==n*m) break;
            for(int i=b;i>=t;i--){
                    ans.push_back(a[i][l]);}l++;
        }
        
        return ans;
    }
};
