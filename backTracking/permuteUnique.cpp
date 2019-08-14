/**************************************************
回溯法-例题2 求数组全排列
leetcode46

Input: [1,1,2]
Output:
[
[1,1,2],
[1,2,1],
[2,1,1]
]

相对于不含重复数据的全排列，添加访问标志位
***************************************************/
#define DEBUG true
#if DEBUG
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//回溯函数
	void backtracking(std::vector<int>& nums, std::vector<bool>& visited,
		std::vector<int>& permute,
		std::vector<std::vector<int>>& result) {
		//goal
		if (permute.size() == nums.size()) {
			result.push_back(permute);
			return;
		}

		else {
			//choice
			for (int i = 0; i < nums.size(); i++) {
				//constraints
				if (visited[i])
					continue;
				//number is the same as the previous one, avoid reusing it
				if (i > 0 && visited[i - 1] == false && nums[i] == nums[i - 1])
					continue;

				permute.push_back(nums[i]);
				visited[i] = true;
				backtracking(nums, visited, permute, result);
				//backtracking
				permute.pop_back();
				visited[i] = false;

			}

		}

	}


	vector<vector<int>> permuteUnique(vector<int>& nums) {
		std::vector<bool> visited(nums.size(),false);
		std::vector<int> permute;
		std::vector<std::vector<int>> result;
		sort(nums.begin(), nums.end());

		backtracking(nums, visited, permute, result);

		return result;
	}
};


int main(int argc, char* argv[]) {
	std::vector<int> nums = { 3, 3, 0, 3 };
	Solution obj;

	std::vector<std::vector<int>> result;
	result = obj.permuteUnique(nums);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++)
			std::cout << result[i][j];
		std::cout << std::endl;
	}

	return 0;
}


#endif
