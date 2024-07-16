class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=1;
        while(j<nums.size()){
            int s=nums[i],e=nums[j];
            if(s==0 and e==0){j++;}
            if(s==0 and e!=0){swap(nums[i],nums[j]);i++;j++;}
            if(s!=0 and e!=0){i++;j++;}
            if(s!=0 and e==0){i++;j++;}
        }
    }
};