#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <string>
#include <sstream>

template <class T>
class Algorithm
{
protected:
	std::vector<T> _container;
	//friend class SortAlgorithm;
public:
	void initContainer(std::vector<T> arr)
	{
		this->_container = arr;
	}

	std::string ToString()
	{
		std::stringstream ss;
		ss << "[ ";
		for(size_t i = 0; i < this->_container.size(); i++)
		{
			ss << this->_container.at(i) << " ";
		}
		ss << "] ";
		return ss.str();
	}

	std::vector<T> getContainer()
	{
		return this->_container;
	}
};

#endif