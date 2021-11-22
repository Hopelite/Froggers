#include <iostream>
#include "..\DirectedGraph\DirectedGraph.h"
#include "..\DirectedGraph\DirectedGraph.cpp"

int main()
{
    DirectedGraph<int> dg;

    /*for (auto it = dg.beginVertexIterator(); it != dg.endVertexIterator(); it++)
    {
        std::cout << (*it) << std::endl;
    };

    for (auto it = dg.beginEdgesIterator(); it != dg.endEdgesIterator(); it++)
    {
        std::cout << '(' << (*it).first << ',' << (*it).second << ')' << std::endl;
    }*/

    /*for (DirectedGraph<int>::VertexIterator it = dg.beginVertexIterator(); it != dg.endVertexIterator(); it++)
    {
        std::cout << it->first << " ";
    }*/

    //dg.add(1, { 2, 3, 4, 5, 9, 192, -4, 78 });
    //dg.add(4, { 3, 5, 192, 228 });
    //DirectedGraph<int>::VertexIterator it = dg.beginVertexIterator();
    //for (auto it = dg.beginVertexIterator(); it != dg.endVertexIterator(); it++)
    //{
    //    for (DirectedGraph<int>::AdjacentVerticiesIterator it2 = dg.beginAdjacentVerticies(it); it2 != dg.endAdjacentVerticies(it); it2++)
    //    {
    //        std::cout << *it2 << " ";
    //    }

    //    std::cout << std::endl;
    //}

    //dg.addVertex(2);
    //dg.addVertex(3);
    //dg.addVertex(4);
    //dg.addVertex(5);
    //dg.addVertex(9);
    //dg.addVertex(192);
    //dg.addVertex(-4);
    //dg.addVertex(78);
    dg.add(1, { 2, 3, 4, 5, 9, 192, -4, 78 });
    dg.deleteVertex(3);
    dg.add(4, { 3, 5, 192, 228 });
    for (auto it = dg.beginVertexIterator();  it != dg.endVertexIterator(); it++)
    {
        for (DirectedGraph<int>::EdgesIterator it2 = dg.beginEdges(it); it2 != dg.endEdges(it); it2++)
        {
            std::cout << (*it2).first << "-" << (*it2).second << " ";
        }
    }
}