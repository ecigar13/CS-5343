#pragma once

class Heap{
public:
int child;
vector<int>* heap;

Heap(int keys);
int parent(int i);
  int left(int i);
  int right(int i);
};

Heap::Heap(int keys){ child=keys;
                    heap= new vector(keys);}
int Heap::left(int i){
  return 2*i;
}

int Heap::right(int i){
  return 2*i+1;
}

int Heap::parent(int i){
  return floor(i/2);
}
