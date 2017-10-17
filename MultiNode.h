#pragma once

#include <vector>

using namespace std;

class MultiNode {
private:
	int count;  //count of keys. Branching factor = count +1
	int min, max;
	vector<int> keys;
	vector<vector<int>*> branch;

public:
	MultiNode(int key);  //construtor
	MultiNode(vector<int> arrayOfKeys);
	void insertNode(int k);
};

inline MultiNode::MultiNode(int key)
{
	count = 1;
	keys.push_back(key);
	int i = 0;
	while (i != count + 1)
		branch.push_back(NULL);
	min = (count + 1) / 2;
	max = 
}

inline MultiNode::MultiNode(vector<int> arrayOfKeys)
{
	count = arrayOfKeys.size();
	keys = arrayOfKeys;
	int i = 0;
	while (i != count + 1)
		branch.push_back(NULL);
}

void MultiNode::insertNode(int k)
{
	//not done. Only insert keys, need to change branch.
	auto it = keys.begin();
	if (k < keys[0]) keys.insert(keys.begin(), k);
	else if (keys[count - 1] < k) keys.push_back(k);
	else{
		for (int i = 0; i < count - 1; i++) {
			if ((keys[i] < k) && (k < keys[i + 1]))
				keys.insert(it + i + 1, k);
		}
	}
}