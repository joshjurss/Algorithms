#ifndef SEARCHALGORITHM_H
#define SEARCHALGORITHM_H

#include "Algorithm.h"

template <class T>
class SearchAlgorithm : public Algorithm<T>
{
public:
	//void f() { this->
	virtual int Search(T item) = 0;
};

#endif