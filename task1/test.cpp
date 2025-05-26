#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void runBFSTest(IGraph& graph, size_t start, const std::string& expected) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    BFS(graph, start, [](size_t vertex) { std::cout << vertex << " "; });

    std::cout.rdbuf(old);
    std::string output = buffer.str();

    if (output == expected) {
        std::cout << "Test passed for start vertex " << start << "\n";
    } else {
        std::cout << "Test failed for start vertex " << start << "\n";
        std::cout << "Expected: \"" << expected << "\", Got: \"" << output << "\"\n";
    }
}

void testListGraph() {
    ListGraph graph(7);
    graph.addEdge(0, 0);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 6);
    graph.addEdge(1, 5);
    graph.addEdge(2, 1);
    graph.addEdge(2, 6);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(6, 2);

    std::cout << "\nListGraph tests:\n";
    runBFSTest(graph, 0, "0 1 4 6 5 2 ");
    runBFSTest(graph, 1, "1 5 ");
    runBFSTest(graph, 2, "2 1 6 5 ");
}

void testMatrixGraph() {
    MatrixGraph graph(7);
    graph.addEdge(0, 0);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 6);
    graph.addEdge(1, 5);
    graph.addEdge(2, 1);
    graph.addEdge(2, 6);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(6, 2);

    std::cout << "\nMatrixGraph tests:\n";
    runBFSTest(graph, 0, "0 1 4 6 5 2 ");
    runBFSTest(graph, 1, "1 5 ");
    runBFSTest(graph, 2, "2 1 6 5 ");
}

void testSetGraph() {
    SetGraph graph(7);
    graph.addEdge(0, 0);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 6);
    graph.addEdge(1, 5);
    graph.addEdge(2, 1);
    graph.addEdge(2, 6);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(6, 2);

    std::cout << "\nSetGraph tests:\n";
    runBFSTest(graph, 0, "0 1 4 6 5 2 ");
    runBFSTest(graph, 1, "1 5 ");
    runBFSTest(graph, 2, "2 1 6 5 ");
}

void testArcGraph() {
    ArcGraph graph(7);
    graph.addEdge(0, 0);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 6);
    graph.addEdge(1, 5);
    graph.addEdge(2, 1);
    graph.addEdge(2, 6);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(6, 2);

    std::cout << "\nArcGraph tests:\n";
    runBFSTest(graph, 0, "0 1 4 6 5 2 ");
    runBFSTest(graph, 1, "1 5 ");
    runBFSTest(graph, 2, "2 1 6 5 ");
}

void testInterfaceConversion() {
    ListGraph graph(7);
    graph.addEdge(0, 0);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 6);
    graph.addEdge(1, 5);
    graph.addEdge(2, 1);
    graph.addEdge(2, 6);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(6, 2);

    std::string expected = "0 1 4 6 5 2 ";

    std::cout << "\nInterface Conversion tests:\n";

    MatrixGraph mGraph(graph);
    runBFSTest(mGraph, 0, expected);

    SetGraph sGraph(mGraph);
    runBFSTest(sGraph, 0, expected);

    ArcGraph aGraph(sGraph);
    runBFSTest(aGraph, 0, expected);

    ListGraph lGraph(aGraph);
    runBFSTest(lGraph, 0, expected);
}

int main() {
    testListGraph();
    testMatrixGraph();
    testSetGraph();
    testArcGraph();
    testInterfaceConversion();

    return 0;
}
