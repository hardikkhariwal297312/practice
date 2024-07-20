class Solution {
public:
    // int countReversePairs(vector<int>a,vector<int> b){
        int count=0;
        int i=0,j=0;
        while(i<a.size() and j<b.size()){
            if(a[i]>(long long )2*b[j]){count+=(a.size()-i);j++;}
            else{i++;}
        }
        return count;
    }
    void merge(vector<int> a,vector<int> b,vector<int>& v){
        int i=0,j=0,k=0;
        vector<int> ans;
        while(i<a.size() and j<b.size()){
            if(a[i]>b[j]){v[k++]=b[j++];}
            else{v[k++]=a[i++];}
        }
        while(i<a.size()){v[k++]=a[i++];}
        while(j<b.size()){v[k++]=b[j++];}
    }
    void mergeSort(vector<int>&nums,int& count){
        int n=nums.size();
        if(n==1){return ;}
        int n1=n/2,n2=n-n/2;
        vector<int> a(n1),b(n2);
        for(int i=0;i<n1;i++){a[i]=nums[i];}
        for(int i=0;i<n2;i++){b[i]=nums[i+n1];}
        mergeSort(a,count);
        mergeSort(b,count);
        count+=countReversePairs(a,b);
        merge(a,b,nums);
        a.clear();b.clear();
    }
    int reversePairs(vector<int>& nums) {
        //1st approach brute force
        // int count=0;
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if((long long )nums[i]>(long long)2*nums[j]){count++;}
        //     }
        // }   
        // return count;



        //most optimized approach using mergesort
        int count=0;
        mergeSort(nums,count);
        return count;
    }








    
};
