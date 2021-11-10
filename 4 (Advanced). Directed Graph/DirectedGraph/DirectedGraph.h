#pragma once
#include <map>
#include <vector>
#include <ostream>

template <typename T>
class DirectedGraph
{
template <typename U>
friend std::ostream& operator<<(std::ostream& out, const DirectedGraph<U>& vector);

public:
	DirectedGraph()
	{
		this->adjacencyList = new std::map<T, std::vector<T>>();
	}

	DirectedGraph(const DirectedGraph& graph)
	{
		this->adjacencyList = new std::map<T, std::vector<T>>(*graph.adjacencyList);
	}

	~DirectedGraph()
	{
		delete this->adjacencyList;
	}

	bool isEmpty()
	{
		return this->adjacencyList->size() == 0;
	}

	void clear()
	{
		// TODO: implement method
	}

	int getNumberOfVertexes()
	{
		return this->adjacencyList->size();
	}

	int getNumberOfArcs()
	{
		int numberOfArcs = 0;
		auto iterator = this->adjacencyList->begin();
		while (iterator != this->adjacencyList->end())
		{
			numberOfArcs += iterator->second.size();
			iterator++;
		}

		return numberOfArcs;
	}

	int getVertexDegree(const T& vertex)
	{
		if (!this->vertexAlreadyInGraphCheck(vertex))
		{
			// TODO: throw NoSuchElementException exception
		}

		auto iterator = this->adjacencyList->find(vertex);
		return (*iterator).second.size();
	}

	int getArcDegree(const T& start, const T& end)
	{
		// TODO: implement method
		return -1;
	}

	void addVertex(T vertex)
	{
		if (this->vertexAlreadyInGraphCheck(vertex))
		{
			// TODO: throw ElementAlreadyInGraphException exception
		}

		this->adjacencyList->insert(std::pair<T,std::vector<T>>(vertex, std::vector<T>()));
	}

	void deleteVertex(T vertex)
	{
		if (!this->vertexAlreadyInGraphCheck(vertex))
		{
			// TODO: throw NoSuchElementException exception
		}

		this->adjacencyList->erase(vertex);
		// TODO: implement logic of arcs deleting
	}

	void addArc(const T& start, const T& end)
	{
		if (!this->vertexAlreadyInGraphCheck(start))
		{
			// TODO: throw NoSuchElementException exception
		}

		if (!this->vertexAlreadyInGraphCheck(end))
		{
			// TODO: throw NoSuchElementException exception
		}

		auto iterator = this->adjacencyList->find(start);

		// TODO: add chech whether arc already exists
		(*iterator).second.push_back(end);

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
	std::map<T, std::vector<T>>* adjacencyList;

	bool vertexAlreadyInGraphCheck(const T vertex)
	{
		if (this->adjacencyList->find(vertex) == this->adjacencyList->end())
		{
			return false;
		}

		return true;
	}
};

