// C++ Program to Implement a Graph Using Adjacency Matrix
#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph {
    vector<vector<int>> adjacency_matrix;

public:
    explicit UndirectedGraph(int n) : adjacency_matrix(n, vector<int>(n, 0)) {}


    void addEdge(int u, int v, int weight = 1) {
        if (u >= adjacency_matrix.size() || v >= adjacency_matrix.size() || u < 0 || v < 0) {
            cout << "Invalid vertex index\n";
            return;
        }
        adjacency_matrix[u][v] = weight;
        adjacency_matrix[v][u] = weight;
    }

    void printGraph() const {
        cout << "Adjacency Matrix for the Undirected Graph:\n";
        for (const auto& row : adjacency_matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
    
};

int main() {
    int vertices = 7;
    UndirectedGraph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    graph.printGraph();
    return 0;
}
