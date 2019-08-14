/**************************************************
回溯法-例题2 求数组全排列
leetcode46

Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
***************************************************/
#define DEBUG false
#if DEBUG
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool hasItem(std::vector<int> current, int item) {
		if (current.empty())
			return false;
		for (int i = 0; i < current.size(); i++) {
			if (current[i] == item)
				return true;
		}
		return false;
	}
	//回溯函数
	void backtracking(std::vector<std::vector<int>>& result,
						std::vector<int> &current,
						std::vector<int> nums) {
		//Goal
		if (current.size() == nums.size())
			result.push_back(current);
		else {
			for (int i = 0; i < nums.size(); i++) {
				//约束条件
				if (hasItem(current, nums[i]))
					continue;
				current.push_back(nums[i]);
				backtracking(result, current, nums);
				current.pop_back();
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		std::vector<std::vector<int> > result;
		std::vector<int> current;
		backtracking(result, current, nums);
		return result;

	}
};


int main(int argc, char* argv[]) {
	std::vector<int> nums = { 1, 2, 3 };
	Solution obj;
	
	std::vector<std::vector<int>> result;

	result = obj.permute(nums);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++)
			std::cout << result[i][j];
		std::cout << std::endl;
	}



	return 0;
}


#endif
