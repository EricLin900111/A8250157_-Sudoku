/* 解開數獨 
參考資料:https://github.com/nk910216/Algorithm_Practice/blob/master/Sudoku.cpp */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX_SIZE 9
#define DEBUG_MODE 1
#define USE_HARD_SUDOKU 1
using namespace std;

int matrix[MAX_SIZE][MAX_SIZE] = {
#if USE_HARD_SUDOKU
	8,0,0,0,0,0,0,0,0,
	0,0,3,6,0,0,0,0,0,
	0,7,0,0,9,0,2,0,0,
	0,5,0,0,0,7,0,0,0,
	0,0,0,0,4,5,7,0,0,
	0,0,0,1,0,0,0,3,0,
	0,0,1,0,0,0,0,6,8,
	0,0,8,5,0,0,0,1,0,
	0,9,0,0,0,0,4,0,0
#else
	3,9,0,6,0,7,5,1,0,
	5,0,8,9,0,2,0,4,3,
	7,0,1,0,0,8,0,0,9,
	8,1,0,4,6,0,3,9,2,
	6,3,0,1,2,9,0,7,4,
	0,2,9,0,7,0,6,5,0,
	0,5,3,0,0,0,4,8,0,
	1,0,4,0,0,6,0,0,7,
	0,0,6,0,8,4,0,2,5
#endif
};
vector<int> row_vec[MAX_SIZE];
vector<int> col_vec[MAX_SIZE];
vector<int> block_vec[MAX_SIZE];

void print_matrix()
{
	cout << "=====current====" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << "|";
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << matrix[i][j];
			if (j % 3 == 2)
				cout << "|";
		}
		cout << endl;
		if (i % 3 == 2)
			cout << "-------------" << endl;
	}
}

int get_block_num(int row, int column)
{
	// 012
	// 345
	// 678
	int r = row / 3;
	int c = column / 3;
	return r * 3 + c;
}

int check_and_generate_info()
{
	// row
	for (int i = 0; i < MAX_SIZE; i++)
	{
		bool check[MAX_SIZE] = { false };
		for (int j = 0; j < MAX_SIZE; j++)
		{
			int value = matrix[i][j] - 1;
			if (value < 0)
				continue;
			if (check[value])
				return -1;
			check[value] = true;
		}

		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (!check[j])
				row_vec[i].push_back(j + 1);
		}
	}

	// column
	for (int j = 0; j < MAX_SIZE; j++)
	{
		bool check[MAX_SIZE] = { false };
		for (int i = 0; i < MAX_SIZE; i++)
		{
			int value = matrix[i][j] - 1;
			if (value < 0)
				continue;
			if (check[value])
				return -1;
			check[value] = true;
		}

		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (!check[i])
				col_vec[j].push_back(i + 1);
		}
	}

	// block
	for (int block = 0; block < MAX_SIZE; block++)
	{
		bool check[MAX_SIZE] = { false };
		int row_start = (block / 3) * 3;
		int col_start = (block % 3) * 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int value = matrix[i + row_start][j + col_start] - 1;
				if (value < 0)
					continue;
				if (check[value])
					return -1;
				check[value] = true;
			}
		}

		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (!check[i])
				block_vec[block].push_back(i + 1);
		}
	}
	return 0;
}

int get_empty_num(vector<int>& row_list, vector<int>& col_list)
{
	int num = 0;
	row_list.clear();
	col_list.clear();
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (matrix[i][j] == 0)
			{
				num++;
				row_list.push_back(i);
				col_list.push_back(j);
			}
		}
	}
	return num;
}

vector<int> find_same_num(vector<int>& row_v,
	vector<int>& col_v,
	vector<int>& block_v)
{
	vector<int> result;

	bool r[MAX_SIZE] = { false };
	bool c[MAX_SIZE] = { false };
	bool b[MAX_SIZE] = { false };

	for (int i = 0; i < row_v.size(); i++)
		r[row_v[i] - 1] = true;
	for (int i = 0; i < col_v.size(); i++)
		c[col_v[i] - 1] = true;
	for (int i = 0; i < block_v.size(); i++)
		b[block_v[i] - 1] = true;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (r[i] && c[i] && b[i])
			result.push_back(i + 1);
	}

	return result;
}

void runKernel(int curr_n, int total_n,
	vector<int>& row_list, vector<int>& col_list)
{
	if (curr_n == total_n)
	{
		print_matrix();
		return;
	}

	int row = row_list[curr_n];
	int col = col_list[curr_n];
	int block = get_block_num(row, col);
	vector<int> candidates = find_same_num(row_vec[row], col_vec[col], block_vec[block]);

	if (candidates.size() == 0)
		return;

	for (int i = 0; i < candidates.size(); i++)
	{
		int value = candidates[i];
		vector<int>::iterator iter;
		iter = find(row_vec[row].begin(), row_vec[row].end(), value);
		row_vec[row].erase(iter);

		iter = find(col_vec[col].begin(), col_vec[col].end(), value);
		col_vec[col].erase(iter);

		iter = find(block_vec[block].begin(), block_vec[block].end(), value);
		block_vec[block].erase(iter);
		matrix[row][col] = value;
		runKernel(curr_n + 1, total_n, row_list, col_list);
		matrix[row][col] = 0;
		row_vec[row].push_back(value);
		col_vec[col].push_back(value);
		block_vec[block].push_back(value);
	}
}

int main()
{
#if !DEBUG_MODE
	cout << "Please enter the numbers : " << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		char in[10];
		cin >> in;

		if (strlen(in) != MAX_SIZE)
		{
			cout << "Error input!!!" << endl;
			return 0;
		}

		for (int j = 0; j < MAX_SIZE; j++)
		{
			int value = in[j] - '0';
			if (value > 0 && value < 9)
				matrix[i][j] = value;
			else
				matrix[i][j] = 0; // unknown
		}
	}
#endif
	print_matrix();
	if (check_and_generate_info() < 0)
	{
		cout << "Error Input Matrix" << endl;
		return 0;
	}
	vector<int> empty_row_list;
	vector<int> empty_col_list;
	int unknown_num = get_empty_num(empty_row_list, empty_col_list);
	runKernel(0, unknown_num, empty_row_list, empty_col_list);

	return 0;
}