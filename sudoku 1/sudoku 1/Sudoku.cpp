#include"Sudoku.h"
#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

Sudoku::Sudoku() {

};
//���ͷs���ƿW
void Sudoku::generateSudoku() {

};
//�M������
void Sudoku::Clear() {

};
//������
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
//��ܤ���
int Sudoku::printPoint() const{
	return point;
};
//��ܿ��~
void Sudoku::printWrong() {

};
//��ܥ��T
void Sudoku::printCorrect() {

};
//��ܵ���
void Sudoku::printAnswer() {

};
//��ܼƿW
void Sudoku::printSudoku() {

};
