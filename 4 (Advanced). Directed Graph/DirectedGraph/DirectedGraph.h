#pragma once
#include <map>
#include <vector>
#include <ostream>
#include <iterator>
#include <utility>
#include "NoSuchElementException.h"
#include "ArcAlreadyExistsException.h"
#include "NoSuchArcExistsException.h"

template <typename T>
class DirectedGraph
{
template <typename U>
friend std::ostream& operator<<(std::ostream& out, const DirectedGraph<U>& vector);

public:
	DirectedGraph()
	{
		this->clear();
	}

	DirectedGraph(const DirectedGraph& graph)
	{
		this->adjacencyList = graph.adjacencyList;
	}

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
		pointer _vertex;
	};

	AdjacentVerticiesIterator beginAdjacentVerticies(VertexIterator it)
	{
		return AdjacentVerticiesIterator(&(it->second[0]));
	}

	AdjacentVerticiesIterator endAdjacentVerticies(VertexIterator it)
	{
		return AdjacentVerticiesIterator(&(it->second[it->second.size() - 1]) + 1);
	}

	class EdgesIterator
	{
	public:
		using pointer = std::pair<T, T>*;
		using reference = std::pair<T, T>&;

		EdgesIterator(VertexIterator vit, AdjacentVerticiesIterator ait) : currentVertex(vit), adjacentVertex(ait) {};

		std::pair<T, T> operator*() const
		{
			auto pair = std::make_pair((*currentVertex).first, *adjacentVertex);
			return pair;
		}

		pointer operator->()
		{
			std::pair<T, T> p = std::make_pair((*currentVertex).first, *adjacentVertex);
			return &p;
		}

		EdgesIterator& operator++() //prefix
		{
			adjacentVertex++;
			return *this;
		}

		EdgesIterator operator++(int) //postfix
		{
			++adjacentVertex;
			return *this;
		}

		EdgesIterator& operator--() //prefix
		{
			adjacentVertex--;
			return *this;
		}

		EdgesIterator operator--(int) //postfix
		{
			--adjacentVertex;
			return *this;
		}

		bool operator==(const  EdgesIterator& b)
		{
			return this->adjacentVertex == b.adjacentVertex;
		}

		bool operator!=(const  EdgesIterator& b)
		{
			return !(this->adjacentVertex == b.adjacentVertex);
		}

	private:
		AdjacentVerticiesIterator adjacentVertex;
		VertexIterator currentVertex;
	};

	EdgesIterator beginEdges(VertexIterator it)
	{
		AdjacentVerticiesIterator iter(&(it->second[0]));
		return EdgesIterator(it, iter);
	}

	EdgesIterator endEdges(VertexIterator it)
	{
		AdjacentVerticiesIterator iter(&(it->second[it->second.size() - 1]) + 1);
		return EdgesIterator(it, iter);
	}

	bool isEmpty()
	{
		return this->adjacencyList.size() == 0;
	}

	void clear()
	{
		this->adjacencyList = std::vector<std::pair<T, std::vector<T>>>();
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
		for (int i = 0; i < this->adjacencyList.size(); i++)
		{
			if (this->adjacencyList[i].first == vertex)
			{
				return this->adjacencyList[i].second.size();
			}
		}
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
		if (!this->vertexAlreadyInGraphCheck(vertex))
		{
			throw NoSuchElementException(vertex);
		}

		for (int i = 0; i < this->adjacencyList.size(); i++)
		{
			if (this->adjacencyList[i].first == vertex)
			{
				this->adjacencyList.erase(this->adjacencyList.begin() + i);
				continue;
			}

			for (int j = 0; j < this->adjacencyList[i].second.size(); j++)
			{
				if (this->adjacencyList[i].second[j] == vertex)
				{
					this->adjacencyList[i].second.erase(this->adjacencyList[i].second.begin() + j);
					break;
				}
			}
		}
	}

	void addArc(const T& start, const T& end)
	{
		if (!this->vertexAlreadyInGraphCheck(start))
		{
			throw NoSuchElementException(start);
		}

		if (!this->vertexAlreadyInGraphCheck(end))
		{
			throw NoSuchElementException(end);
		}

		if (this->arcAlreadyExistsCheck(start, end))
		{
			throw ArcAlreadyExistsException(start, end);
		}


		for (int i = 0; i < this->adjacencyList.size(); i++)
		{
			if (this->adjacencyList[i].first == start)
			{
				for (int j = 0; j < this->adjacencyList[i].second.size(); j++)
				{
					this->adjacencyList[i].second.push_back(end);
					return;
				}
			}
		}
	}

	void deleteArc(const T& start, const T& end)
	{
		if (!this->vertexAlreadyInGraphCheck(start))
		{
			throw NoSuchElementException(start);
		}

		if (!this->vertexAlreadyInGraphCheck(end))
		{
			throw NoSuchElementException(end);
		}

		if (!this->arcAlreadyExistsCheck(start, end))
		{
			throw NoSuchArcExistsException(start, end);
		}

		for (int i = 0; i < this->adjacencyList.size(); i++)
		{
			if (this->adjacencyList[i].first == start)
			{
				for (int j = 0; j < this->adjacencyList[i].second.size(); j++)
				{
					if (this->adjacencyList[i].second[j] == end)
					{
						this->adjacencyList[i].second.erase(this->adjacencyList[i].second.begin() + j);
						return;
					}
				}
			}
		}
	}

private:
	std::vector<std::pair<T, std::vector<T>>> adjacencyList;

	bool vertexAlreadyInGraphCheck(T vertex)
	{
		for (auto it = this->adjacencyList.begin(); it != this->adjacencyList.end(); it++)
		{
			if ((*it).first == vertex)
			{
				return true;
			}
		}

		return false;
	}

	bool arcAlreadyExistsCheck(const T& start, const T& end)
	{
		for (auto it = this->adjacencyList.begin(); it != this->adjacencyList.end(); it++)
		{
			if ((*it).first == start)
			{
				for (auto innerIt = (*it).second.begin(); innerIt != (*it).second.end(); innerIt++)
				{
					if ((*innerIt) == end)
					{
						return true;
					}
				}
			}
		}

		return false;
	}
};

