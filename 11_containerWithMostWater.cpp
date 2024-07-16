class Solution {
public:
/*
The two-pointer technique starts with the widest container and moves the pointers inward based on the comparison of heights.
Increasing the width of the container can only lead to a larger area if the height of the new boundary is greater. By moving the pointers towards the center, we explore containers with the potential for greater areas.*/
/*
By making these pointer movements, we ensure that we are always exploring containers with the potential for larger areas. The approach is based on the observation that increasing the width of the container can only lead to a larger area if the height of the new boundary is greater.
By following this condition and moving the pointers accordingly, the algorithm explores all possible containers and finds the one with the maximum area*/
    int maxArea(vector<int>& arr) {
        int maxarea=0;
        int i=0,j=arr.size()-1;
        while(i<j){
            int area=min(arr[i],arr[j])*(j-i);
            if(arr[i]<arr[j]){i++;}
            else{j--;}
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};
