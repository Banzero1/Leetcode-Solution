class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        if(X>=Y)
        {
            return X-Y;
        }
        int c=0;
        while(Y>X)
        {
            if(Y&1)
            {
                Y++;
            }
            else{
            Y/=2;}
            c++;
        }
        return c+X-Y;
        
    }
};