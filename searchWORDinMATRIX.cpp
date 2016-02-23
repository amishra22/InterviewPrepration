class Solution {

private:
//this variable takes care of the starting point and then corresponding path in the matrix
int path=1;

public:


    bool existUtil(vector<vector<char> >& board, int x, int y, int index, string word, vector<vector<int> >& vec){
        
        // if any of the below condition evaluates to true we do not have to go further
        if( x<0 || x>= board.size() || y<0 || y>=board[0].size() || board[x][y]!=word[index] || vec[x][y] !=0 )
            return false;
        
        // if it is the last index we have found the word .. return true    
        if(index == word.size()-1)
            {
                vec[x][y] = path++;
                return true;
                
            }
            
            
            vec[x][y] = path++;
            
            // check the sale column next row
            if(existUtil(board,x+1,y,index+1,word,vec))
                return true;
            
            //check the same row and next column    
            if(existUtil(board,x,y+1,index+1,word,vec))
                return true;
            
            // check the current column and previous row
            if(existUtil(board,x-1,y,index+1,word,vec))
                return true;
            
            // check the current row and previous column
            if(existUtil(board,x,y-1,index+1,word,vec))
                return true;
            
            // there was a character mismatch put a 0 in the output matrix, decrement path by 1 and return false   
            vec[x][y] = 0;
            path--;
            return false;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<int> > vec;
        int m = board.size();
        int n=board[0].size();
        
        // this is a solution matrix which will have a non zero value if a character is matched otherwise zero
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
