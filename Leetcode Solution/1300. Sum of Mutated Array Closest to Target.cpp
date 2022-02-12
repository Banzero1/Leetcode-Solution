class Solution {
public:
        int findBestValue(vector<int>& arr, int target) {
        int lo=0, hi=100000, mid=lo+(hi-lo)/2, sum1=0, sum2=0,mx=0,c=0,i;
            for(i=0;i<arr.size();i++)
            {
                mx=max(mx,arr[i]);
                c+=arr[i];
            }
            
            if(c<=target)
            {
                return mx;
            }
            hi=mx;
            
            //binary search
        while(lo<hi) {
            int sum=0;
            for(int i=0;i<arr.size();i++) sum+=min(arr[i], mid);
            if(sum>=target) hi=mid;
            else lo=mid+1;
            mid=lo+(hi-lo)/2;
        }
            
           // answer can be mid or mid-1 
        for(int i=0;i<arr.size();i++) sum1+=min(arr[i], mid-1);
        for(int i=0;i<arr.size();i++) sum2+=min(arr[i], mid);
        if(abs(sum1-target)<=abs(sum2-target)) return mid-1;
        else return mid;
    }
};

//TC - O(Nlog(1e5))
//SC - O(1)
