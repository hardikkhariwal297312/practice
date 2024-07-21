// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         vector<int>rightmax(n,n);
//         vector<int> leftmax(n,-1);
//         for(int i=0;i<n;i++){
//             int x=heights[i];
//             for(int j=i+1;j<n;j++){
//                 if(heights[j]<x){rightmax[i]=j;break;}
//             }

//             int k=n-i-1;
//             int y=heights[k];
//             for(int l=k-1;l>=0;l--){
//                 if(heights[l]<y){leftmax[k]=l;break;}
//             }
//         }
//         // rightmax[n-1]=n-1;
//         // for(int i=n-1;i>=0;i--){
//         //     int x=heights[i];
//         //     for(int j=i-1;j>=0;j--){
//         //         if(heights[j]<x){leftmax[i]=j+1;break;}
//         //     }
//         // }
//         // leftmax[0]=0;
//         int maxarea=0;
//         for(int i=0;i<n;i++){
//             int area=heights[i]*(rightmax[i]-leftmax[i]-1);
//             maxarea=max(maxarea,area);
//         }
//         return maxarea;
//     }
// };
// above is my code and this is not optimized 



//this is optimized doone using stack 
class Solution {
    private:
vector<int> nextelement(vector<int>& heights, int n )
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i =n-1;i>=0;i--)
    {
        int curr= heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr)
        {
            st.pop();
        }
    ans[i]=st.top();
    st.push(i);
    }
    return ans;
}

vector<int> prevelement(vector<int>& heights, int n )
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i =0;i<n;i++)
    {
        int curr= heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr)
        {
            st.pop();
        }
    ans[i]=st.top();
    st.push(i);
    }
    return ans;
}
public:
    int largestRectangleArea(vector<int>& heights) {
       int n =heights.size();
       int area= INT_MIN;

       vector<int>next(n);
       vector<int>prev(n);

       next=nextelement(heights,n); 
       prev=prevelement(heights,n); 

       for(int i =0;i<n;i++)
       {
           int l = heights[i];
           if(next[i]==-1)
           {
               next[i]=n;
           }
           int b = next[i]-prev[i]-1;
           int newarea= l*b;
           area=max(area,newarea);
       }
       return area;
    }
};
