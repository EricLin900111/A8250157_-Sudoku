#ifndef SUDOKU_COMMON_H
#define SUDOKU_COMMON_H
//unsigned int (½d³ò 0 ~ 4294967295)
static const unsigned int unselected = 0;

enum class Difficulty {
	easy = 1, 
	normal, 
	hard
};
enum class State {
	inited = 0, 
	erased
};
 struct point_t {
	int x;
	int y;
};
struct point_value_t {
	int value;
	State state;
};

class PointSort {
public:
	bool operator()(const point_t &l, const point_t & r) const {
		if((l.x == r.x) && (l.y == r.y))
			return false;
		else
			return true;
	}
};
#endif