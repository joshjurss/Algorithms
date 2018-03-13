#ifndef INSERTSORT_H
#define INSERTSORT_H

#include "SortAlgorithm.h"
#include "Algorithm.h"

template <class T>
class InsertSort : public SortAlgorithm<T>
{
public:
	virtual void Sort()
	{
		int x;
		T currelement;
		for(size_t i = 1; i < this->_container.size(); i++)
		{
			x = i - 1;
			currelement = this->_container[i];
			while(x >= 0 && _container[x] > currelement)
			{
				_container[x+1] = _container[x];
				x = x - 1;
				
			}
			_container[x + 1] = currelement;
		}
	}
};

#endif