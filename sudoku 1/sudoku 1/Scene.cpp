//ผฦฟWภ๔นา
#include<iostream>
#include <vector>
#include"Scene.h"

using namespace std;

class Scene {
public:
	Scene(int);
	
	void Generater();
	void show() const;
	
	bool setCurValue(const int, int&);
	bool setPointValue();
private:
	int index;
	int max_column;
	
};