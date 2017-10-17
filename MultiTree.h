#pragma once

#include "MultiNode.h"
class MultiTree {
private:
	MultiNode root;
	int height;
	int size;
public:
	MultiNode returnRoot() { return root; }
	bool insert(int key);
};