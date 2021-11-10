#include <iostream>
#include "..\DirectedGraph\DirectedGraph.h"
#include "..\DirectedGraph\DirectedGraph.cpp"

int main()
{
    DirectedGraph<char> graph;
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addArc('A', 'B');
    graph.addArc('A', 'C');
    graph.addArc('B', 'C');

    std::cout << graph;
    std::cout << "Hello World!\n";
}