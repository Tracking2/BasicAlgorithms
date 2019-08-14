/**************************************************
回溯法-例题2 求数组全排列
leetcode40

Given a collection of candidate numbers (candidates) and a target 
number (target), find all unique combinations in candidates where 
the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]

***************************************************/
#define DEBUG true
#if DEBUG
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//backtracking
	void backTracking(std::vector<int>& candidates, 
						int target, std::vector<int>& temp,
						std::vector<std::vector<int>>& result,
						int start) {
		//goal
		if (target == 0) {
			result.push_back(temp);
			return;
		}	
		else {
			for (int i = start; i < candidates.size(); i++) {
				int curr = candidates[i];
				if (target - curr >= 0) {
					temp.push_back(curr);
					backTracking(candidates, target - curr, temp, result, i+1);
					temp.pop_back();
					while (i < candidates.size() - 1 && candidates[i+1] == curr)
					{
						i++;
					}
				}
				else {
					return;
				}
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		std::vector<std::vector<int>> result;
		std::vector<int> temp;

		sort(candidates.begin(), candidates.end());
		backTracking(candidates, target, temp, result,0);

		return result;
	}
};


int main(int argc, char* argv[]) {
	std::vector<int> nums = { 10,1,2,7,6,1,5 };
	int target = 8;
	Solution obj;

	std::vector<std::vector<int>> result;
	result = obj.combinationSum2(nums, target);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			std::cout << result[i][j];
		std::cout << std::endl;
	}

	return 0;
}


#endif
