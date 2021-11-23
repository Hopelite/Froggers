#include <iostream>
#include "..\DirectedGraph\DirectedGraph.h"

int main()
{
    DirectedGraph<int> dg;
    try
    {
        dg.addVertex(3);
        dg.add(4, { 3 });
        dg.addVertex(5);
        dg.add(1, { 3, 4, 5 });
        dg.addVertex(9);
        dg.addArc(5, 3);
        dg.addArc(3, 9);
        dg.addArc(9, 1);
        /*dg.addVertex(3);
        dg.deleteVertex(3);*/
        for (auto it = dg.beginVertexIterator(); it != dg.endVertexIterator(); it++)
        {
            for (DirectedGraph<int>::EdgesIterator it2 = dg.beginEdges(it); it2 != dg.endEdges(it); it2++)
            {
                std::cout << (*it2).first << "-" << (*it2).second << " ";
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}