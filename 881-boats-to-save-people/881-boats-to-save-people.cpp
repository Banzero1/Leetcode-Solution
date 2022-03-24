class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n=people.size(),i,j,c=0;
        vector<int>v(n,0);
        sort(people.begin(),people.end());
        i=0;j=n-1;
        /*
        for(auto i:s)
        {
            cout<<i<<endl;
        }
        
        */
        
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
            }
            j--;
            c++;
        }
       
        return c;
        
    }
};