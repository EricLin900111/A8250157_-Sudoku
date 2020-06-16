#ifndef SUDOKU_BLOCK_H
#define SUDOKU_BLOCK_H
#include"common.h"
class Block {
	static const int Max_count = 9;
public:
	Block();
	bool isValid() const;
	bool isFull() const;
	void print() const;
	void push_back(point_value_t*);
private:
	int count;
	point_value_t *numbers[Max_count];
};

#endif // !SUDOKU_BLOCK_H
