#ifndef MEDIAN_SORT_H
#define MEDIAN_SORT_H

#include "SortAlgorithm.h"
#include <algorithm>
#include <vector>

template <class T>
class MedianSort : public SortAlgorithm<T>
{
public:
	virtual void Sort()
	{
		this->mediansort(0, this->_container.size());
	}

	void mediansort(size_t left, size_t right)
	{
		throw exception("Does not work!");
		if (left >= right || (right - left) == 1)
			return;
		//if (arr.size() == 0 || arr.size() == 1 || arr.size() == 2)
		//	return;
		//int midpos = arr.size() / 2;
		size_t pivot = right - left -1;
		size_t mid = right / 2;
		std::swap(this->_container[pivot], this->_container[mid]);
		for(size_t i = left; i < mid - 1; i++)
		{
			if (this->_container.at(i) > this->_container.at(mid))
			{
				for (size_t k = mid + 1; k < this->_container.size(); k++)
				{
					if (this->_container.at(k) <= this->_container.at(mid))
					{
						std::swap(this->_container[i], this->_container[k]);
					}
				}
			}
		}
		mediansort(left, left+mid-1);
		mediansort(left+mid+1, right);

	}
};

#endif