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
    dg.addVertex(5);
    dg.addVertex(9);
    dg.addVertex(-11);
    dg.addVertex(92);
    dg.addVertex(87);
    dg.addVertex(13);
    dg.addVertex(52);

    for (DiGraph<int>::Iterator it = dg.begin(); it != dg.end(); it++)
    {
        std::cout << it->first << "\n";
    }
}