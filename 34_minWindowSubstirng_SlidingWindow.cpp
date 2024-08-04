class Solution {
public:
//i tried using two hashmap but not solved


//this is uing one hashmap but got TLE as time complexity is of O(n^2);
//find some optimized solution 
    // string minWindow(string s, string t) {
    //     //corner cases 
    //     if(s.size()<t.size()){return "";}
    //     //answers
    //     int mini=INT_MAX,minl=-1,n=s.size();

    //     //check all substring starting from 0 to n-1
    //     for(int i=0;i<n;i++){
    //         vector<int> tmp(256,0);
    //         int curr=0;
    //         //initialize the hash map 
    //         for(int i=0;i<t.size();i++){tmp[t[i]]++;}     

    //         //now checking for all the substring from i to j where j is (i, n);   
    //         for(int j=i;j<n;j++){
    //             if(tmp[s[j]]>0){curr++;}
    //             tmp[s[j]]--;
    //             if(curr==t.size()){
    //                 //checking for minimum values
    //                 if(mini>j-i+1){mini=j-i+1;minl=i;}
    //             }
    //         }
    //     }
    //     //again checking conrner cases
    //     if(minl==-1) return "";


    //     //returning the final ans
    //     return s.substr(minl,mini);
    // }


    //we have to use sliding window to optimize this
    //i have done it using sliding window + hashmap but , 266 /268 runs, only two test case remains
    //due to TLE
        string minWindow(string s, string t) {
        if(s.size()<t.size()){return "";}
        int mini=INT_MAX,minl=-1,n=s.size();

        vector<int> tmp(256,0);
        int curr=0;
        for(int i=0;i<t.size();i++){tmp[t[i]]++;}  

        int i=0,j=0;
        while(j<n){
            if(tmp[s[j]]-->0){curr++;}
            while(curr==t.size()){
                if(mini>j-i+1){mini=j-i+1;minl=i;}
                tmp[s[i]]++;
                if(tmp[s[i]]>0){curr--;}
                i++;
            }
            j++;
        }
        if(minl==-1) return "";
        return s.substr(minl,mini);
    }

};
