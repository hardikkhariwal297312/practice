#include<queue>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
      //thinking of this data structure is key 
        unordered_map<string,vector<string>> mp;


      //thinking that sorting of strings make them the same if they are anagrams
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }

        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
