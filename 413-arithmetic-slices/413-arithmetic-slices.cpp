class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2)return 0;
        int count = 0, ans = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i+1] - nums[i] == nums[i+2] - nums[i+1]){
                count++;
            }
            else{
                ans += ((count * (count+1)) / 2);
                count = 0;
            }
            
        }
        if(count) ans += ((count * (count+1)) / 2);
        return ans;
    }
};