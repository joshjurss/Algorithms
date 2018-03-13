#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortAlgorithm.h"
#include <vector>

template <class T>
class MergeSort : public SortAlgorithm<T>
{
public:
	
	virtual void Sort()
	{
		this->_container = mergesort(this->_container);
	}

	std::vector<T> mergesort(std::vector<T> arr)
	{
		if (arr.size() <= 1)
			return arr;
		size_t middle = arr.size() / 2;
		std::vector<T> left(arr.begin(), arr.begin() + middle);
		std::vector<T> right(arr.begin() + middle, arr.end());

		left = mergesort(left);
		right = mergesort(right);
		
		return merge(left, right);
	}

	std::vector<T> merge(std::vector<T> left, std::vector<T> right)
	{
		std::vector<T> res;

		while (left.size() > 0 || right.size() > 0)
		{
			if (left.size() > 0 && right.size() > 0)
			{
				if (left.at(0) <= right.at(0))
				{
					res.push_back(left.at(0));
					left.erase(left.begin());
				} else {
					res.push_back(right.at(0));
					right.erase(right.begin());
				}
			} else if (left.size() > 0) {
				res.push_back(left.at(0));
				left.erase(left.begin());
			} else if (right.size() > 0) {
				res.push_back(right.at(0));
				right.erase(right.begin());
			}

		}

		return res;
	}
};

#endif