#pragma once

#include <map>
#include <vector>
#include <ostream>
#include <iterator>
#include <cstddef>

template <typename T>
class DiGraph
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const DiGraph<U>& vector);

public:
	DiGraph()
	{

	}

	~DiGraph()
	{
		
	}

	void addVertex(T vertex)
	{
		std::vector<T> v = {};
		this->adjacencyList.push_back(std::pair<T, std::vector<T>>(vertex, v));
	}


	class Iterator
	{
	public:
		using category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using pointer = std::pair<T, std::vector<T>>*;
		using reference = std::pair<T, std::vector<T>>&;


		Iterator(pointer ptr) : _ptr(ptr) {};
		Iterator(const Iterator&) {};

		reference operator*() const
		{
			return *_ptr;
		}

		pointer operator->()
		{
			return _ptr;
		}

		Iterator& operator++() //prefix
		{
			_ptr++;
			return *this;
		}

		Iterator operator++(int) //postfix
		{
			Iterator temporary = *this;
			++(*this);
			return temporary;
		}

		Iterator& operator--() //prefix
		{
			_ptr--;
			return *this;
		}

		Iterator operator--(int) //postfix
		{
			Iterator temporary = *this;
			--(*this);
			return temporary;
		}

		friend bool operator==(const Iterator& a, const Iterator& b)
		{
			return a._ptr == b._ptr;
		}


		friend bool operator!=(const Iterator& a, const Iterator& b)
		{
			return !(a._ptr == b._ptr);
		}

	private:
		pointer _ptr;
	};

	Iterator begin()
	{
		return Iterator(&adjacencyList[0]);
	}

	Iterator end()
	{
		return Iterator(&adjacencyList[adjacencyList.size() - 1] + 1);
	}

private:
	std::vector<std::pair<T, std::vector<T>>> adjacencyList;

};
