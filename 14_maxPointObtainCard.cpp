class Solution {
public:
    // int maxScore(vector<int>& a, int k) {
    //     int l=0,r=a.size()-1;
    //     int sum=0;
    //     if(k==r+1){
    //         for(int i:a){sum+=i;}
    //         return sum;
    //     }
    //     while(k-- and l<r){
    //         if(a[l]>a[r]){sum+=a[l];l++;}
    //         else if(a[l]<a[r]){sum+=a[r];r--;}
    //         else{
    //             sum+=a[l];
    //             int nextl=l+1,nextr=r-1;
    //             while(nextl<nextr){
    //                 if(a[nextl]>a[nextr]){l++;break;}
    //                 else if(a[nextl]<a[nextr]){r--;break;}
    //                 else{nextl++;nextr--;}
    //             }
    //             if(nextl>=nextr){l++;}
    //         }
    //     }
    //     return sum;
    // }




    //this is correct but time complexity and space complexiuty is very high , not optimal 
    // void solve(vector<int> a,int k, int l,int r,int& maxi,int ans){
    //     if(k<=0){maxi=max(maxi,ans);return ;}
    //     ans+=a[l];
    //     solve(a,k-1,l+1,r,maxi,ans);
    //     ans-=a[l];

    //     ans+=a[r];
    //     solve(a,k-1, l,r-1,maxi,ans);
    //     ans-=a[r];
    // }
    // int maxScore(vector<int> a,int k){
    //     int maxi=0;
    //     solve(a,k,0,a.size()-1,maxi,0);
    //     return maxi;
    // }





    //we can think this problem as an finding minimum sum of subarray of length n-k;
    int maxScore(vector<int> a,int k){
        int n=a.size();
        int lsum=0;
        // int totalsum=0;
        // for(int i:a){totalsum+=i;}
        for(int i=0;i<k;i++){
            lsum+=a[i];
        }
        // cout<<"ksum: "<<ksum<<endl;
        // int minsum=ksum;
        int maxsum=lsum;
        int rsum=0;
        for(int i=n-1;i>=n-k;i--){
            lsum-=a[k-(n-i)];rsum+=a[i];
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};
