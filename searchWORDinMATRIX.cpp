class Solution {

private:
int path=1;

public:


    bool existUtil(vector<vector<char> >& board, int x, int y, int index, string word, vector<vector<int> >& vec){
        
        if( x<0 || x>= board.size() || y<0 || y>=board[0].size() || board[x][y]!=word[index] || vec[x][y] !=0 )
            return false;
            
        if(index == word.size()-1)
            {
                vec[x][y] = path++;
                return true;
                
            }
            
            
            vec[x][y] = path++;
            
            if(existUtil(board,x+1,y,index+1,word,vec))
                return true;
                
            if(existUtil(board,x,y+1,index+1,word,vec))
                return true;
                
            if(existUtil(board,x-1,y,index+1,word,vec))
                return true;
        
            if(existUtil(board,x,y-1,index+1,word,vec))
                return true;
                
            vec[x][y] = 0;
            path--;
            return false;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<int> > vec;
        int m = board.size();
        int n=board[0].size();
        
        vec.resize(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(existUtil(board,i,j,0,word,vec))
                    return true;
            }
        }
        
        return false;
        
    }
};