class Solution {
public:
    int countLive(vector<vector<int>> board,int i,int j,int n,int m){
        int count=0;
        // for(int i=0;i<8;i++){
        //     int dx[]={-1,-1,-1,0,0,1,1,1};
        //     int dy[]={-1,0,1,-1,1,-1,0,1};
        //     int nx=x+dx[i],ny=y+dy[i];
        //     if(nx>=n or ny>=m or nx<0 or ny<0 or board[nx][ny]==0){continue;}
        //     else{count++;}
        // }
        if(i-1>=0 and j-1>=0 and board[i-1][j-1]==1) count++;
        if(i-1>=0 and board[i-1][j]==1) count++;
        if(i-1>=0 and j+1<m and board[i-1][j+1]==1) count++;
        if(j+1<m and board[i][j+1]==1) count++;
        if(j-1>=0 and board[i][j-1]==1) count++;
        if(i+1<n and j-1>=0 and board[i+1][j-1]==1) count++;
        if(i+1<n and board[i+1][j]==1) count++;
        if(i+1<n and j+1<m and board[i+1][j+1]==1) count++;
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans=board;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count=countLive(board,i,j,n,m);
                if(count==3){ans[i][j]=1;}
                else if(count >3){ans[i][j]=0;}
                else if(count<2){ans[i][j]=0;}
            }
        }
        board=ans;
    }
};
