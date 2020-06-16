#include <iostream>
#include <cassert> // assert ������~�A�פ�{��
#include "Block.h"
#include "common.h"
#include "color.h"
using namespace std;

Block::Block() : count(0) {};

bool Block::isValid() const {
	assert(Max_count == count);

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1;j < count; j++) {
			if (unselected == numbers[i]->value || unselected == numbers[j]->value)
				continue;
			if (numbers[i]->value == numbers[j]->value)
				return false;
		}
	}
	return true;
};

bool Block::isFull() const {
	for (int i = 0; i < count; i++) {
		point_value_t *p_point_value = numbers[i];
		//nullptr ���ū���
		if (p_point_value == nullptr || unselected == p_point_value->value)
			return false;
	}
	return true;
};

void Block::print() const {
	cout << "| ";
	for (int i = 0; i < count; i++) {
		//auto�P�w�ܼƫ��O
		auto number = *(numbers[i]);
		if (number.value == 0)
			cout << ' ' << " | ";
		else
		{
			if (number.state == State::erased)
				cout << Color::Modifier(Color::FG_Green) << number.value << Color::Modifier(Color::Reset) << " | ";
			else
				cout << number.value << " | ";
		}
	}
	cout << endl;
};

void Block::push_back(point_value_t * point) {
	assert(nullptr != point);
	numbers[count++] = point;
};