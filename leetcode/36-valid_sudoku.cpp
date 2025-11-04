// tag
// tag dynamic programming

// diff: medium

// url: https://leetcode.com/problems/valid-sudoku/

#include "utils/vec.hpp"
#include <iostream>
#include <unordered_map>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
	std::unordered_map<int, vector<char>> rows;
	std::unordered_map<int, vector<char>> cols;
	// std::unordered_map<std::pair<int, int>, vector<vector<char>>> blocks;

  public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		int size = board.size();

		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				char cell = board[y][x];
				if (cell == '.')
					continue;

				vector<char> row = getRow(y, board);
				vector<char> col = getCol(x, board);
				vector<vector<char>> block = getBlock(x, y, board);

				for (int i = 0; i < size; i++)
				{
					if (i != x && board[y][i] == cell)
						return false; // row check
					if (i != y && board[i][x] == cell)
						return false; // column check
				}

				int blockRowStart = (y / 3) * 3;
				int blockColStart = (x / 3) * 3;

				for (int i = blockRowStart; i < blockRowStart + 3; i++)
				{
					for (int j = blockColStart; j < blockColStart + 3; j++)
					{
						if (i == y && j == x)
							continue; // skip current cell
						if (board[i][j] == cell)
							return false; // duplicate in 3x3 block
					}
				}
			}
		}

		return true;
	}

	vector<char> getRow(int x, vector<vector<char>> &board)
	{
		if (rows.find(x) != rows.end())
			return rows[x];

		vector<char> row;

		for (const char &num : board[x])
			row.push_back(num);

		rows.insert({x, row});
		return rows[x];
	}

	vector<char> getCol(int y, vector<vector<char>> &board)
	{
		if (cols.find(y) != cols.end())
			return cols[y];

		vector<char> col;

		for (int i = 0; i < board.size(); i++)
			col.push_back(board[i][y]);

		cols.insert({y, col});
		return cols[y];
	}

	vector<vector<char>> getBlock(int x, int y, vector<vector<char>> &board)
	{

		// if (blocks.find({x, y}) != blocks.end())
		// 	return blocks[{x, y}];

		int xOffset = x / 3;
		int yOffset = y / 3;

		vector<vector<char>> block;

		for (int i = xOffset * 3; i < xOffset * 3 + 3; i++)
		{
			vector<char> temp;
			for (int j = yOffset * 3; j < yOffset * 3 + 3; j++)
				temp.push_back(board[i][j]);

			block.push_back(temp);
		}

		return block;
		// blocks[{x, y}] = block;
		// return blocks[{x, y}];
	}
};

int main()
{
	Solution soln;
	return 0;
}
