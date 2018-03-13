#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "SearchAlgorithm.h"

template <class T>
class BinarySearch : public SearchAlgorithm<T>
{
public:
	virtual int Search(T item)
	{
		int low = 0;
		int high = this->_container.size() - 1;
		int idx;
		while (low <= high)
		{
			idx = ( low + high ) / 2;
			if ( item == this->_container.at(idx) )
				return idx;
			else if ( item < this->_container.at(idx) )
				high = idx - 1;
			else
				low = idx + 1;
		}
		return -1;
	}
};

template <class T>
class BinarySearchRecursive : public SearchAlgorithm<T>
{
public:
	virtual int Search(T item)
	{
		return binarysearch(item, 0, this->_container.size());
	}

	int binarysearch(T item, int left, int right)
	{
		if (left > right)
		{
			return -1;
		} else {
			int mid = ( left + right ) / 2;

			if (this->_container.at(mid) > item)
				return binarysearch(item, left, right - 1);
			else if (this->_container.at(mid) < item)
				return binarysearch(item, left + 1, right);
			else
				return mid;
		}
	}
};

#endif