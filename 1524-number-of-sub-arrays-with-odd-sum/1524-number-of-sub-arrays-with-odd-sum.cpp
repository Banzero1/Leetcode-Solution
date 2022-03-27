class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int i,e=0,od=0,c=0,mod=1e9+7,e1=0,n=arr.size();
        for(i=0;i<n;i++)
        {
            c+=arr[i];
            
            if(c%2==0)
            {
                od=(od+e)%mod;
                e1++;
            }
            else
            {
                od=(od+e1+1)%mod;
                
                e++;
            }
            
        }
        return od;
        
    }
};

/*
If we know the number of even and odd subarrays that end at the previous element, we can figure out how many even and odd subarrays we have for element n:

If n is even, we increase the number of even subarrays; the number of odd subarrays does not change.
If n is odd, the number of odd subarrays is the previous number of even subarrays + 1. The number of even subarrays is the previous number of odd subarrays.

*/