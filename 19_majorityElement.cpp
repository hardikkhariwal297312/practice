class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int ans=0;
        for(int i:nums){
            mp[i]++;
            if(mp[i]>nums.size()/2){ans= i;}
        }
        return ans;
    }
};
