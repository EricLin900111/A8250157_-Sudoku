#ifndef SUDOKU_H
#define SUDOKU_H
#include<vector>
using namespace std;
class Sudoku {
private:
	int point;//分數
	vector<vector<int>> sudoku; //數獨格式
public:
	Sudoku();
	void generateSudoku();//產生新的數獨
	void Clear();//清除答案
	void changePoint(int,int);//更改分數
	int printPoint() const;//顯示分數
	void printWrong();//顯示錯誤
	void printCorrect();//顯示正確
	void printAnswer();//顯示答案
	void printSudoku();//顯示數獨	
};
#endif // !SUDOKU_H
