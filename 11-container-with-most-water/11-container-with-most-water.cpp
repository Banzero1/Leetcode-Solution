class Solution {
public:
    int maxArea(vector<int>& height) {
        
        
        int i=0,n=height.size(),j,ar=0,mx=0;
        j=n-1;
        
        while(i<j)
        {
            ar=max(ar,(j-i)*min(height[j],height[i]));
            
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            
        }
        return ar;
        
        
    }
};