# Graph Implementation Using Adjacency Matrix in C++

## Overview
This project implements a simple **Graph** using an adjacency matrix in C++. The graph is represented as a two-dimensional vector, where each cell indicates the weight of the edge between two vertices. This implementation is for an **undirected** graph, meaning each edge is bidirectional.

## Midterms Analysis
After running the program 5 times, `printMemoryUsage()` shows an average of 3463.2 KBs peak RAM usage. In addition, the program was run 5 times on [JDoodle](https://www.jdoodle.com/online-compiler-c++) and was compiled and executed in an average of 1.9052 seconds. Lastly, the worst time complexity of the program is O(n²).
.

## Code Snippet
```cpp
int main() {
    int vertices = 7;
    UndirectedGraph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    graph.printGraph();

    graph.printMemoryUsage();

    return 0;
}
```

## Output
```
Adjacency Matrix for the Undirected Graph:
0 1 1 0 0 0 0
1 0 0 1 0 0 0
1 0 0 1 0 0 0
0 1 1 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
Peak RAM used: 3468 KB

Process finished with exit code 0
```

## Features
- **Adjacency Matrix Representation:**  
  The graph is stored as an `n x n` matrix (using `vector<vector<int>>`), with each cell `[i][j]` holding the weight of the edge from vertex `i` to vertex `j`. By default, edges have a weight of 1.
  
- **Edge Addition with Validation:**  
  The `addEdge` function allows adding an edge between two vertices and includes checks to ensure the provided vertex indices are valid.

## References
Code retrieved from [GeeksforGeeks](https://www.geeksforgeeks.org/implementation-of-graph-in-cpp/) with the help of ChatGPT and Copilot
