class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     map<int,int> mp;
    //     int ans=0;
    //     for(int i:nums){
    //         mp[i]++;
    //         if(mp[i]>nums.size()/2){ans= i;}
    //     }
    //     return ans;
    // }


    //using moore voting algorithm 
    int majorityElement(vector<int>& a){
        int major=a[0],votes=1;
        for(int i=1;i<a.size();i++){
            if(a[i]==major){votes++;}
            else{votes--;}

            if(votes==0){major=a[i];votes++;}
        }
        return major;
    }
};
