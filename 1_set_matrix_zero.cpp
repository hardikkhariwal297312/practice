// #include<unorderd_map>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<pair<int,int>> zero;
        vector<int> row,col;
        // unordered_map<bool> row,col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        cout<<"row: ";for(int i:row){cout<<i<<" ";}cout<<endl;
        cout<<"col: ";for(int i:row){cout<<i<<" ";}cout<<endl;

        for(int i=0;i<row.size();i++){
            cout<<"row index: "<<row[i]<<endl;
            for(int j=0;j<m;j++){
                matrix[row[i]][j]=0;
            }
        }
        for(int j=0;j<col.size();j++){
            cout<<"col index: "<<col[j]<<endl;
          for(int i=0;i<n;i++){
                matrix[i][col[j]]=0;
            }
        }
    }
};