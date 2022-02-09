class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};

//TC : O(logn)
//SC : O(1)    

/*

Lets say you have a mid number at index x, nums[x]
if (num[x+1] > nums[x]), that means a peak element HAS to exist on the right half of that array, because (since every number is unique) 1. the numbers keep increasing on the right side, and the peak will be the last element. 2. the numbers stop increasing and there is a 'dip', or there exists somewhere a number such that nums[y] < nums[y-1], which means number[x] is a peak element.

This same logic can be applied to the left hand side (nums[x] < nums[x-1]).
*/
