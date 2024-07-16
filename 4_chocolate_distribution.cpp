class Solution {
public:
    int chocolateDistribution(vector<int> arr,int m){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0,j=m-1;
        int minDiff=INT_MAX;
        while(j<n){
            minDiff=min(minDiff,arr[j]-arr[i]);
            i++;j++;
        }
        return minDiff;
    }
};