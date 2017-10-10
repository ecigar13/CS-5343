#pragma once

class Btree{
public:
int count;
vector<int>* key;
vector<vector<int>*> branch;
int key;

Btree(int key);
}

Btree::Btree(int key){
key=key;
}

