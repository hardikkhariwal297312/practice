class Solution {
public:
    int strStr(string haystack, string needle) {
        //we always find lps of needle 
        int n=needle.size();
        vector<int> lps(n,0);
        int pre=0,suff=1;
        while(suff<n){
            if(needle[pre]==needle[suff]){lps[suff]=pre+1;pre++;suff++;}
            else if(pre==0){lps[suff]=0;suff++;}
            else{pre=lps[pre-1];}
        }
        for(int i:lps){cout<<i<<' ';}cout<<endl;
        int f=0,s=0;
        int ans=-1;
        while(f<haystack.size()){
            if(haystack[f]==needle[s]){f++;s++;}
            else if(s!=0){s=lps[s-1];}
            else{f++;}
            if(s==n){ans=f-n;break;}
        }
        return ans;
    }
};
