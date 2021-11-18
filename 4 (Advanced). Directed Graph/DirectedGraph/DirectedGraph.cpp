#include "pch.h"
#include "DirectedGraph.h"
#include "framework.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, DirectedGraph<T>& graph)
{
	for (auto it = graph.begin(); it != graph.end(); it++)
	{
		out << (*it).first;
	}

    return out;
}
