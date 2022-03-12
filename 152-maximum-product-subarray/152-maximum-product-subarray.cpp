class Solution {
public:
   int maxProduct(vector<int>& nums) {
       
       int curr_product = 1, res = INT_MIN;
       
       for (auto i: nums) {
           curr_product = curr_product * i;
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }
       }
       
       curr_product = 1;
       
       for (int i = nums.size()-1; i>=0; i--) {
           curr_product = curr_product * nums[i];
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }      
       }
       return res;
   }
};


//TC - O(N)
//SC - O(1)

// 2 pass solution





/*class Solution {
public:
     int maxProduct(vector<int> A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
            r =  (r ? r : 1) * A[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
};
// 1 pass

*/