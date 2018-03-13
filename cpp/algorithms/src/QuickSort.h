#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortAlgorithm.h"
#include <algorithm>

template <class T>
class QuickSortWiki : public SortAlgorithm<T>
{
public:
	virtual void Sort()
	{
		quicksort(0, this->_container.size() - 1);
	}

	void quicksort(int left, int right)
	{
		if (left < right)
		{

			int store;
			int pivindex = ( right + left ) / 2;
			T pivval = this->_container.at(pivindex);
			std::swap(this->_container[pivindex], this->_container[right]);
			store = left;
			for(int i = left; i < right - 1; i++)
			{
				if (this->_container[i] < pivval)
				{
					std::swap(this->_container[i], this->_container[store]);
					store++;
				}
			}
			std::swap(this->_container[store], this->_container[right]);
			quicksort(left, store - 1);
			quicksort(store + 1, right);
		} else {
			return;
		}
	}
};

template <class T>
class QuickSort2 : public SortAlgorithm<T>
{
public:
	virtual void Sort()
	{
		quicksort(0, this->_container.size() - 1);
	}

	void quicksort(int left, int right)
	{
		if (right <= left)
			return;

		// parition
		int store = 0;
		int pivindex = ( left + right ) / 2;
		T piv_value = this->_container[pivindex];
		std::swap(this->_container[pivindex], this->_container[right]);
		store = left;
		for(int i = left; i <= right - 1; i++)
		{
			if (this->_container[i] < piv_value)
			{
				std::swap(this->_container[i], this->_container[store]);
				store++;
			}
		}
		std::swap(this->_container[store], this->_container[right]);


		quicksort(left, store - 1);
		quicksort(store + 1, right);
	}
};


template <class T>
class QuickSort : public SortAlgorithm<T>
{
public:
	virtual void Sort()
	{
		quicksort(0, this->_container.size() - 1);
	}

	void quicksort(int left, int right)
	{
		int leftpos = left, rightpos = right;
		T pivot = this->_container[(left + right) / 2];

		while (leftpos <= rightpos)
		{
			while(this->_container.at(leftpos) < pivot)
				leftpos++;

			while(this->_container.at(rightpos) > pivot)
				rightpos--;

			if (leftpos <= rightpos)
			{
				std::swap(this->_container[rightpos], this->_container[leftpos]);
				leftpos++;
				rightpos--;
			}
		}

		if (left < rightpos)
			quicksort(left, rightpos);
		if (leftpos < right)
			quicksort(leftpos, right);
	}
};

#endif