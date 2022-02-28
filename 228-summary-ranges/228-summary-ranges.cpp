class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int start = 0;
		for(int i = 0; i < nums.size(); i++){
			if((i + 1 == nums.size()) || (nums[i + 1] > 1 + nums[i])){
				string temp = to_string(nums[start]);
				if(start != i){
					temp += "->" + to_string(nums[i]);
				}
				res.push_back(temp);
				start = i + 1;
			}
		}
		return res;
	}
};