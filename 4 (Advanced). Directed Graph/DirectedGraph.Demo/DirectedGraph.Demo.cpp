#include <iostream>
//#include "..\DirectedGraph\DirectedGraph.h"
//#include "..\DirectedGraph\DirectedGraph.cpp"
#include "..\DirectedGraph\DiGraph.h"

int main()
{
    /*DirectedGraph<char> graph;
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addArc('A', 'B');
    graph.addArc('A', 'C');
    graph.addArc('B', 'C');

    std::cout << graph;
    std::cout << "Hello World!\n";

    for (DirectedGraph<char>::Iterator it = graph.begin(); it != graph.end(); it++)
    {
        std::cout << *it;
    }*/

    DiGraph<int> dg;
    dg.addVertex(9);
    dg.addVertex(0);
    dg.addVertex(1);

    for (DiGraph<int>::Iterator it = dg.begin(); it != dg.end(); it++)
    {
        std::cout << it->first << "\n";
    }
}