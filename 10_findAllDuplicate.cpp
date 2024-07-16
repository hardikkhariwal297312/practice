class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //using condition that arr[i] is in range 1 to n
        vector<int> ans;
        for(int i:nums){
            if(nums[abs(i)-1]<0){
                ans.push_back(abs(i));
            }
            else{
                nums[abs(i)-1]*=-1;
            }
            for(auto j:nums){cout<<j<<' ';}cout<<endl;
        }
        return ans;
    }
    /*Approach

Step 1 : Occurence of an number can be atmost two ,While traversal for each element mark its index negative so that whenever we get that same element we get to know that element is repeating and put that element into ans vector.
Step 2 : Since elements are in range [1,n] where n is size of array. So there is no problem of array out of bound.
*/
};
