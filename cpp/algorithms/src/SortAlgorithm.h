#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include "Algorithm.h"

template <class T>
class SortAlgorithm : public Algorithm<T>
{
public:
	virtual void Sort() = 0;
};

#endif