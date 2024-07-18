class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        // int count=0;
        // int n=a.size();
        // for(int i=1;i<n;i++){
        //     a[i]+=a[i-1];
        //     if(a[i-1]==k){count++;}
        // }
        // if(a[n-1]==k){count++;}
        // // for(int i=0;i<n;i++){
        // //     if(a[i]==k){count++;}
        // // }
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(a[j]-a[i]==k){count++;}
        //     }
        // }
        //return count;
        //above is my solution using basic intution 



        //most optimized using hasmap to count the prefix ocuured before 
        int n =a.size(),ans=0;
        // vector<int> prefix(n);
        // prefix[0]=a[0];
        // for(int i=1;i<n;i++){
        //     prefix[i]=a[i]+prefix[i-1];
        // }
        for(int i=1;i<n;i++){
            a[i]+=a[i-1];
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            // if(prefix[i]==k){ans++;}
            // if(mp.find(prefix[i]-k)!=mp.end()){
            //     ans+=mp[prefix[i]-k];
            // }
            // mp[prefix[i]]++;
                if(a[i]==k){ans++;}
            if(mp.find(a[i]-k)!=mp.end()){
                ans+=mp[a[i]-k];
            }
            mp[a[i]]++;
            
        }
        return ans;
    }
};

// 2 1 - 1 0 -2 3 -3
// 2 3  2  2  0 5  0 
