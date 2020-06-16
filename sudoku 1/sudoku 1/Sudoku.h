#ifndef SUDOKU_H
#define SUDOKU_H
#include<vector>
using namespace std;
class Sudoku {
private:
	int point;//����
	vector<vector<int>> sudoku; //�ƿW�榡
public:
	Sudoku();
	void generateSudoku();//���ͷs���ƿW
	void Clear();//�M������
	void changePoint(int,int);//������
	int printPoint() const;//��ܤ���
	void printWrong();//��ܿ��~
	void printCorrect();//��ܥ��T
	void printAnswer();//��ܵ���
	void printSudoku();//��ܼƿW	
};
#endif // !SUDOKU_H
