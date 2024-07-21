class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int ind=0;
        if(strs.size()==1){return strs[0];}
        while(true){
            if(strs[0].size()<=ind){break;}
            char c=strs[0][ind];
            bool cond=1;
            for(int i=0;i<strs.size();i++){
                if(strs[i].size()<ind or strs[i][ind]!=c){cond=0;}
            }
            if(cond){ans+=c;ind++;}
            else{break;}
        }
        return ans;
    }
};
