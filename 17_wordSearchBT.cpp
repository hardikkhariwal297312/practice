// class Solution {
// public:
//     // bool possible(vector<vector<bool>> visited,vector<vector<char>> board,int x,int y,string word,int index,int n,int m){
//     //     if(x<0 or y<0 or x>=n or y>=m){return 0;}
//     //     else if(visited[x][y]){return 0;}
//     //     else if(word[index]!=board[x][y]){return 0;}
//     //     return 1;
//     // }
//     // void solve(vector<vector<char>> board,string word,int n,int m,bool& solved,vector<vector<bool>>& visited,int index,int x,int y)
//     // {   if(index==word.size()-1){solved=1;return ;}
//     //     if(x==n or y==m){return ;}
//     //     for(int i=0;i<4;i++){
//     //         int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
//     //         if(possible(visited,board,x+dx[i],y+dy[i],word,index,n,m)){
//     //             visited[x+dx[i]][y+dy[i]]=1;
//     //             solve(board,word,n,m,solved,visited,index+1,x+dx[i],y+dy[i]);
//     //             visited[x+dx[i]][y+dy[i]]=0;
//     //             if(solved)return;
//     //         }
//     //     }
//     // }
//     // bool exist(vector<vector<char>>& board, string word) {
//     //     int n=board.size(),m=board[0].size();
//     //     vector<vector<bool>> visited(n,vector<bool> (m,0));
//     //     bool solved=0;
//     //     for(int i=0;i<n;i++){
//     //         for(int j=0;j<m;j++){
//     //             if(word[0]==board[i][j]){
//     //                 visited[i][j]=1;
//     //                 solve(board,word,n,m,solved,visited,1,i,j);
//     //                 visited[i][j]=0;
//     //                 if(solved) return 1;
//     //             }
//     //         }
//     //     }
//     //     return 0;
//     // }
//     //above is my solution and time limit exceeded





//     //using dfs
//         bool dfs(vector<vector<char>> &board,int i,int j, int count,string word){
//         if(count==word.size()-1){return 1;}
//         if(i<0 or i>=board.size() or j<0 or j>=board[0].size()){return 0;}
//         else if (board[i][j]!=word[count]){return 0;}
//         char temp=board[i][j];
//         board[i][j]='*';
//         if(dfs(board,i+1,j,count+1,word) or dfs(board,i-1,j,count+1,word) or dfs(board,i,j+1,count+1,word) or dfs(board,i,j-1,count+1,word)) return 1;;
//         board[i][j]=temp;
//         return 0;
//     }

//     bool exist(vector<vector<char>> &board,string word){
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j>board[0].size();j++){
//                 if(board[i][j]==word[0] and dfs(board,i,j,0,word)){
//                     return 1;
//                 }
//             }
//         }
//         return 0;
//     }


// };


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        //learned how to write the function inside the function in c++
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
