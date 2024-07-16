class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     int n=nums.size();
    //     if(n<3){return {};}
    //     sort(nums.begin(),nums.end());
    //     if(nums[0]>0){return {};}
    //     map<vector<int>,bool> mp;
    //     for(int i=0;i<n-2;i++){
    //         if(nums[i]>0){break;}
    //         int l=i+1,r=n-1;
    //         while(l<r){
    //             int sum=nums[i]+nums[l]+nums[r];
    //             if(sum>0){r--;}
    //             else if(sum<0){l++;}
    //             else{
    //                 vector<int> twosum={nums[i],nums[l],nums[r]};
    //                 if(!mp[twosum])
    //                     {ans.push_back(twosum);mp[twosum]=1;}
    //                 r--;l++;}
    //         }
    //     }
    //     return ans;
    // }
    //the above is my solution using hash map 

    //the below is most optimized solution without using any hashmap
    vector<vector<int>> threeSum(vector<int>& nums){
        int n=nums.size();
        if(n<3){return {};}
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]){continue;}
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    ans.push_back({nums[i],nums[r],nums[l]});
                    l++;
                    while(l<r and nums[l]==nums[l-1]){l++;}
                    r--;
                    while(l<r and nums[r]==nums[r+1]){r--;}
                }
                else if(sum>0){r--;}
                else{l++;}
            }
        }
        return ans;
    }
};
