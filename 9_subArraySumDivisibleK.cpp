class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        
        unordered_map<int, int> m;
        m[0] = 1;

        for (int i : nums) {
            sum += i;
            int mod = sum % k;
          //this is to keep our remainder in range 0 to k-1;
          //if let say remainder t occur two times in the array , that means from 1st t to second t there is remainder 0 as s1=mk+t, s2=nk+t, s1-s2=(m-n)k where (s1-s2)%k=0 , this is most efficient appproach
            if (mod < 0)
                mod += k;
            if (m.find(mod) != m.end()) {
                count += m[mod];
            }
            m[mod]++;
        }

        return count;
    }
};
/*    When to use the prefix sum approach:

        Cumulative Sum Queries:
            When the problem involves querying the sum of elements between various ranges multiple times.
            Example: Finding the sum of elements in subarrays or ranges efficiently.

        Subarray Sum Conditions:
            When you need to determine subarrays that meet a specific sum condition, such as being equal to a given value or divisible by a number.
            Example: Counting subarrays whose sum is divisible by (k).
*/
