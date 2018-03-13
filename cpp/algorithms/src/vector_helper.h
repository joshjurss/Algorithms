#ifndef VECTOR_HELPER_H
#define VECTOR_HELPER_H

#include <string>
#include <vector>

template <typename T>
class create_vector
{
	private:
		std::vector<T> vect;
	public:
		create_vector(const T& val)
		{
			vect.push_back(val);
		}

		create_vector<T>& operator()(const T& val)
		{
			vect.push_back(val);
			return *this;
		}

		operator std::vector<T>()
		{
			return vect;
		}
};

#endif