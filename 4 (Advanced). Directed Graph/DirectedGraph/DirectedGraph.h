#pragma once
#include <iostream>

template <typename T>
class DirectedGraph
{
friend std::ostream& operator<<(std::ostream& out, const DirectedGraph<T>& vector);

public:
	DirectedGraph()
	{
		// TODO: implement default constructor
	}

	DirectedGraph(const DirectedGraph& graph)
	{
		// TODO: implement copy constructor
	}

	~DirectedGraph()
	{
		// TODO: implement method
	}

	bool isEmpty()
	{
		// TODO: implement method
		return false;
	}

	void clear()
	{
		// TODO: implement method
	}

	int getNumberOfVertexes()
	{
		// TODO: implement method
		return -1;
	}

	int getNumberOfArcs()
	{
		// TODO: implement method
		return -1;
	}

	int getVertexDegree(const T& vertex)
	{
		// TODO: implement method
		return -1;
	}

	void addVertex(const T& vertexElement)
	{
		// TODO: implement method
	}

	void deleteVertex(const T& vertex)
	{
		// TODO: implement method
	}

	void addArc(const T& start, const T& end)
	{
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
};

