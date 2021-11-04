#include <iostream>
#include "..\DirectedGraph\DirectedGraph.h"

int main()
{
    DirectedGraph<char> graph;
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addArc('A', 'B');

    std::cout << "Hello World!\n";
}