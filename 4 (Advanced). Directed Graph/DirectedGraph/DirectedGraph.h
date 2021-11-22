#pragma once
#include <map>
#include <vector>
#include <ostream>
#include <iterator>
#include <utility>

template <typename T>
class DirectedGraph
{
template <typename U>
friend std::ostream& operator<<(std::ostream& out, const DirectedGraph<U>& vector);

public:

	void add(T i, std::vector<T> v)
	{
		this->adjacencyList.push_back(make_pair(i, v));
	}


	class VertexIterator
	{
	public:
		using pointer = std::pair<T, std::vector<T>>*;
		using reference = std::pair<T, std::vector<T>>&;

		VertexIterator(pointer ptr) : _ptr(ptr) {};

		reference operator*() const
		{
			return *_ptr;
		}

		pointer operator->()
		{
			return _ptr;
		}

		VertexIterator& operator++() //prefix
		{
			_ptr++;
			return *this;
		}

		VertexIterator operator++(int) //postfix
		{
			VertexIterator temporary = *this;
			++(*this);
			return temporary;
		}

		VertexIterator& operator--() //prefix
		{
			_ptr--;
			return *this;
		}

		VertexIterator operator--(int) //postfix
		{
			VertexIterator temporary = *this;
			--(*this);
			return temporary;
		}

		bool operator==(const VertexIterator& b)
		{
			return this->_ptr == b._ptr;
		}

		bool operator!=(const VertexIterator& b)
		{
			return !(this->_ptr == b._ptr);
		}

	private:
		pointer _ptr;
	};

	VertexIterator beginVertexIterator()
	{
		return VertexIterator(&adjacencyList[0]);
	}

	VertexIterator endVertexIterator()
	{
		return VertexIterator(&adjacencyList[adjacencyList.size() - 1] + 1);
	}



	class AdjacentVerticiesIterator
	{
	public:
		//using vector_pointer = std::pair<T, std::vector<T>>*;
		using pointer = T*;
		using reference = T&;

		AdjacentVerticiesIterator(pointer vertex) : _vertex(vertex) {};

		reference operator*() const
		{
			return *_vertex;
		}

		pointer operator->()
		{
			return _vertex;
		}

		AdjacentVerticiesIterator& operator++() //prefix
		{
			_vertex++;
			return *this;
		}

		AdjacentVerticiesIterator operator++(int) //postfix
		{
			AdjacentVerticiesIterator temporary = *this;
			++(*this);
			return temporary;
		}

		AdjacentVerticiesIterator& operator--() //prefix
		{
			_vertex--;
			return *this;
		}

		AdjacentVerticiesIterator operator--(int) //postfix
		{
			AdjacentVerticiesIterator temporary = *this;
			--(*this);
			return temporary;
		}

		bool operator==(const  AdjacentVerticiesIterator& b)
		{
			return this->_vertex == b._vertex;
		}

		bool operator!=(const  AdjacentVerticiesIterator& b)
		{
			return !(this->_vertex == b._vertex);
		}

	private:
		//pointer _ptr;
		pointer _vertex;
	};

	/*AdjacentVerticiesIterator beginAdjacentVerticies(VertexIterator it)
	{
		return AdjacentVerticiesIterator(&(it->second[0]));
	}

	AdjacentVerticiesIterator endAdjacentVerticies(VertexIterator it)
	{
		return AdjacentVerticiesIterator(&(it->second[it->second.size() - 1]) + 1);
	}*/

	AdjacentVerticiesIterator beginAdjacentVerticies(VertexIterator it)
	{
		return AdjacentVerticiesIterator(&(it->second[0]));
	}

	AdjacentVerticiesIterator endAdjacentVerticies(VertexIterator it)
	{
		return AdjacentVerticiesIterator(&(it->second[it->second.size() - 1]) + 1);
	}

	//class VertexIterator
	//{
	//public:
	//	using pointer = std::pair<T, std::vector<T>>*;

	//	VertexIterator(pointer ptr) : iterator(ptr)
	//	{
	//		this->iterator = AdjacentVertexesIterator(ptr);
	//	}

	//	T operator*() const
	//	{
	//		return (*iterator).first;
	//	}

	//	VertexIterator& operator++() //prefix
	//	{
	//		this->iterator++;
	//		return *this;
	//	}

	//	VertexIterator operator++(int) //postfix
	//	{
	//		VertexIterator temporary = *this;
	//		++(*this);
	//		return temporary;
	//	}

	//	VertexIterator& operator--() //prefix
	//	{
	//		this->iterator--;
	//		return *this;
	//	}

	//	VertexIterator operator--(int) //postfix
	//	{
	//		VertexIterator temporary = *this;
	//		--(*this);
	//		return temporary;
	//	}

	//	bool operator==(const VertexIterator& b)
	//	{
	//		return this->iterator == b.iterator;
	//	}

	//	bool operator!=(const VertexIterator& b)
	//	{
	//		return !(this->iterator == b.iterator);
	//	}

	//private:
	//	AdjacentVertexesIterator iterator;
	//};

	//VertexIterator beginVertexIterator()
	//{
	//	return VertexIterator(&adjacencyList[0]);
	//}

	//VertexIterator endVertexIterator()
	//{
	//	return VertexIterator(&adjacencyList[adjacencyList.size() - 1] + 1);
	//}



	//class EdgesIterator 
	//{
	//public:
	//	using pointer = std::pair<T, std::vector<T>>*;

	//	EdgesIterator(pointer ptr) : iterator(ptr)
	//	{
	//		this->iterator = AdjacentVertexesIterator(ptr);
	//	}

	//	std::pair<T, T> operator*()
	//	{
	//		return std::make_pair((*this->iterator).first, (*this->adjacentVertexes));
	//	}

	//	EdgesIterator& operator++() //prefix
	//	{
	//		if (this->adjacentVertexes == (*this->iterator).second.end())
	//		{
	//			this->iterator++;
	//			this->adjacentVertexes = (*this->iterator).second.begin();
	//		}
	//		else
	//		{
	//			this->adjacentVertexes++;
	//		}

	//		return *this;
	//	}

	//	EdgesIterator operator++(int) //postfix
	//	{
	//		EdgesIterator temporary = *this;
	//		++(*this);
	//		return temporary;
	//	}

	//	//EdgesIterator& operator--() //prefix
	//	//{
	//	//	this->iterator--;
	//	//	return *this;
	//	//}

	//	//EdgesIterator operator--(int) //postfix
	//	//{
	//	//	EdgesIterator temporary = *this;
	//	//	--(*this);
	//	//	return temporary;
	//	//}

	//	bool operator==(const EdgesIterator& b)
	//	{
	//		return this->iterator == b.iterator;
	//	}

	//	bool operator!=(const EdgesIterator& b)
	//	{
	//		return !(this->iterator == b.iterator);
	//	}

	//private:
	//	AdjacentVertexesIterator iterator;
	//	std::vector<T>::iterator adjacentVertexes;
	//};

	//EdgesIterator beginEdgesIterator()
	//{
	//	return EdgesIterator(&adjacencyList[0]);
	//}

	//EdgesIterator endEdgesIterator()
	//{
	//	return EdgesIterator(&adjacencyList[adjacencyList.size() - 1] + 1);
	//}



	bool isEmpty()
	{
		return this->adjacencyList.size() == 0;
	}

	void clear()
	{
		// TODO: implement method
	}

	int getNumberOfVertexes()
	{
		return this->adjacencyList.size();
	}

	int getNumberOfArcs()
	{
		int numberOfArcs = 0;
		auto iterator = this->adjacencyList.begin();
		while (iterator != this->adjacencyList.end())
		{
			numberOfArcs += iterator->second.size();
			iterator++;
		}

		return numberOfArcs;
	}

	int getVertexDegree(const T& vertex)
	{
		return -1;
	}

	int getArcDegree(const T& start, const T& end)
	{
		// TODO: implement method
		return -1;
	}

	void addVertex(T vertex)
	{
		std::vector<T> v = {};
		this->adjacencyList.push_back(std::pair<T, std::vector<T>>(vertex, v));
	}

	void deleteVertex(T vertex)
	{
		//if (!this->vertexAlreadyInGraphCheck(vertex))
		//{
		//	// TODO: throw NoSuchElementException exception
		//}
		
		// TODO: implement logic of arcs deleting
	}

	void addArc(const T& start, const T& end)
	{
		//if (!this->vertexAlreadyInGraphCheck(start))
		//{
		//	// TODO: throw NoSuchElementException exception
		//}

		//if (!this->vertexAlreadyInGraphCheck(end))
		//{
		//	// TODO: throw NoSuchElementException exception
		//}

		//auto iterator = this->adjacencyList->find(start);

		// TODO: add chech whether arc already exists
		//(*iterator).second.push_back(end);

		// TODO: implement method
	}

	void deleteArc(const T& start, const T& end)
	{
		// TODO: implement method
	}

	const DirectedGraph& operator=(const DirectedGraph& rhs)
	{
		// TODO: override operator
		return DirectedGraph();
	}

	const bool operator==(const DirectedGraph& rhs)
	{
		// TODO: override operator
		return false;
	}

	const bool operator!=(const DirectedGraph& rhs)
	{
		// TODO: override operator
		return false;
	}

	const bool operator>(DirectedGraph& rhs)
	{
		// TODO: override operator
		return false;
	}

	const bool operator>=(DirectedGraph& rhs)
	{
		// TODO: override operator
		return false;
	}

	const bool operator<(DirectedGraph& rhs)
	{
		// TODO: override operator
		return false;
	}

	const bool operator<=(DirectedGraph& rhs)
	{
		// TODO: override operator
		return false;
	}

private:
	std::vector<std::pair<T, std::vector<T>>> adjacencyList;
};

