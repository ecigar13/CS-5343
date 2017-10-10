#pragma once

class Heap{
public:
int child;
int* children;

Heap(int keys);

};

Heap::Heap(int keys){ child=keys;}

