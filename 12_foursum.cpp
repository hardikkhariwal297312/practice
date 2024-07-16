class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        //convert 4 to 3 to 2;
        vector<vector<int>> arr;
        int n=nums.size();
        for(int i=0; i<=n-4; i++){
            //these all continue for duplicate removal
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<=n-3; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int low=j+1;
                int high=n-1;
                while(low<high){
                    long long s=(long long)nums[i]+nums[j]+nums[low]+nums[high];
                    if(s==target){
                        arr.push_back({nums[i],nums[j],nums[low],nums[high]});
                        //this two whiles loops for duplicate removals 
                        low++;
                        while(low<high && nums[low]==nums[low-1]) low++;
                        high--;
                        while(low<high && nums[high]==nums[high+1]) high--;
                    }
                    else if(s<target){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        if(arr.size())
            return arr;
        return {};
    }
};
