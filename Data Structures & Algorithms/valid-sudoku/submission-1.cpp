class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<9;row++){
            vector<bool>a(9,false);
            for(int col=0;col<9;col++){
                if(board[row][col]=='.')continue;
                if(a[board[row][col]-'0'])return  false;
                a[board[row][col]-'0']=true;
            }   
        }
        for(int col=0;col<9;col++){
            vector<bool>a(9,false);
            for(int row=0;row<9;row++){
                if(board[row][col]=='.')continue;
                if(a[board[row][col]-'0'])return  false;
                a[board[row][col]-'0']=true;
            }
        }
        for(int i=0;i<=24;i+=3){
            int sr=i/9;
            if(sr==1)sr=3;
            if(sr==2)sr=6;
            int sc=i%9;
            vector<bool>a(9,false);
            for(int row=sr;row<=sr+2;row++){
                for(int col=sc;col<=sc+2;col++){
                    if(board[row][col]=='.')continue;
                    if(a[board[row][col]-'0'])return  false;
                    a[board[row][col]-'0']=true;
                }
            }
        }
        return true;
    }
};
