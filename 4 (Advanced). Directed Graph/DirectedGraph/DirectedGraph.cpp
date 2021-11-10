#include "pch.h"
#include "DirectedGraph.h"
#include "framework.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, const DirectedGraph<T>& vector)
{
	// TODO: refactor method using custom iterator

	auto mapIterator = vector.adjacencyList->begin();
	while (mapIterator != vector.adjacencyList->end())
	{
		out << (*mapIterator).first << ": ";

		auto vectorIterator = (*mapIterator).second.begin();
		while (vectorIterator != (*mapIterator).second.end())
		{
			out << *vectorIterator << " ";
			vectorIterator++;
		}

		out << std::endl;
		mapIterator++;
	}

    return out;
}
