class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        
        vector<int>rows(3,0),col(3,0);
        int i,j,dig=0,antidig=0,xwin=0,owin=0,turn=0;
        
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(board[i][j]=='X')
                {
                    rows[i]++;
                    turn++;
                    col[j]++;
                    if(i==j)
                    {dig++;}
                    if(i+j==2)
                    {antidig++;}
                }
                else if(board[i][j]=='O')
                {
                     rows[i]--;
                    turn--;
                    col[j]--;
                  if(i==j)
                    {dig--;}
                    if(i+j==2)
                    {antidig--;}
                }
            }
        }
        
         xwin = rows[0] == 3 || rows[1] == 3 || rows[2] == 3 || 
               col[0] == 3 || col[1] == 3 || col[2] == 3 || 
               dig == 3 || antidig == 3;
        owin = rows[0] == -3 || rows[1] == -3 || rows[2] == -3 || 
               col[0] == -3 || col[1] == -3 || col[2] == -3 || 
               dig == -3 || antidig == -3;
        
       
        if((xwin&&turn!=1)||(owin&&turn!=0))
        {
           
            return false;
        }
        
        return turn==1||turn==0;
        
    }
};
