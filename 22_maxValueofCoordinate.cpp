// class Solution {
// public:
//     int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//         int maxi=INT_MIN;
//         int n=points.size();
//         int i=0,j=1;
//         while(i<n-1){
//             if(j==n){i++;j=i+1;continue;}
//             int val=abs(points[i][0]-points[j][0]);
//             if(val<=k){maxi=max(maxi,val+points[i][1]+points[j][1]);j++;}
//             else{i++;j=i+1;}

//         }
//         return maxi;
//     }
//      this solution is not optimized and time limit exceeded;
// };






//this solution is uing maxheap , whenever finding min or max , always consider or think of min heap and maxheap or priority queue;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>p;
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++){
			// if  xj - xi > k then we have to remove that from the queue as it can not longer 
			// contribute to the answer which is given in the question itself
            while(!p.empty() && (points[i][0]-p.top().second)>k){
                p.pop();
            }
			
			// now if the queue is not empty then the top of the queue is having 
			// maximum value of  ( yi-xi) so we update our answer with  (top of the queue) + currvalue
            if(!p.empty()){
                ans=max(ans,points[i][0]+points[i][1]+p.top().first);
            }
			
			// inserting ( yi-xi ) into the queue 
            p.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }
};
