/**************************************************
Program: 回溯法 求解 N皇后问题
Data: 2019/08/14
Author: fanl


***************************************************/
#define DEBUG true
#if DEBUG
#include <iostream>
#include <vector>

class Solution {
public:
	//判断设置的皇后是否在同一行，同一列，或者同一斜线上
	bool isValid(std::vector<int> colPlacement) {
		int rowId = colPlacement.size() - 1;
		for (int i = 0; i < rowId; i++) {
			int diff = abs(colPlacement[i] - colPlacement[rowId]);
			if (diff == 0 || diff == rowId - i)
				return false;
		}
		return true;
	}
    
	/*
	Parameter：
	        n: The sizeof matrix
			row: row number
			colPlacement[i]: 第i行皇后所放置的列号 
			result
	*/
	void solveNQueens(int n, int row, std::vector<int>& colPlacement, 
						std::vector<std::vector<int>>& result) {
		//Goal
		if (row == n) {
			result.push_back(colPlacement);
			//colPlacement.clear();
		}
		else {
			//Choice
			for (int col = 0; col < n; col++) {
				colPlacement.push_back(col);
				// Constraints
				if (isValid(colPlacement)) {
					solveNQueens(n, row + 1, colPlacement, result);
				}
				//undo choice / come back
				colPlacement.pop_back();
			}
		}
	}
	std::vector<std::vector<int>> nQueens(int n) {
		std::vector<std::vector<int>> result;
		std::vector<int> colPlacement;
		solveNQueens(n, 0, colPlacement, result);
		return result;
	}

};

/********************************************************
 * test sample
 *
 ********************************************************/
int main(int argc, char* argv[]) {
	Solution obj;
	std::vector<std::vector<int>> result;
	result = obj.nQueens(3);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++)
			std::cout << result[i][j];
		std::cout << std::endl;
	}

	return 0;
		
}


#endif