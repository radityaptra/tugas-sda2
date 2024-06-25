#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int numVertices;
    vector<list<int>> adjLists;
    vector<bool> visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void DFS(int vertex);
    void printGraph();
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists.resize(vertices);
    visited.resize(vertices, false);
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src); // Jika graf tidak berarah
}

void Graph::DFS(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int adjVertex : adjLists[vertex]) {
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
    }
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ":";
        for (int vertex : adjLists[i]) {
            cout << " -> " << vertex;
        }
        cout << endl;
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency list:" << endl;
    g.printGraph();

    cout << "Depth First Traversal dimulai dari vertex 0:" << endl;
    g.DFS(0);

    return 0;
}
