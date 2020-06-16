#include"Sudoku.h"
#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

Sudoku::Sudoku() {

};
//產生新的數獨
void Sudoku::generateSudoku() {

};
//清除答案
void Sudoku::Clear() {

};
//更改分數
void Sudoku::changePoint(int marks, int point) {
	switch (marks)
	{
	case 1:
		this->point += point;
		break;
	case 2:
		this->point -= point;
		break;
	case 0:
		this->point = 0;
		break;
	default:
		this->point = 0;
		break;
	}
};
//顯示分數
int Sudoku::printPoint() const{
	return point;
};
//顯示錯誤
void Sudoku::printWrong() {

};
//顯示正確
void Sudoku::printCorrect() {

};
//顯示答案
void Sudoku::printAnswer() {

};
//顯示數獨
void Sudoku::printSudoku() {

};
