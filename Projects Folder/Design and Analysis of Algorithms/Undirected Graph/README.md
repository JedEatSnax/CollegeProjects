# Graph Implementation Using Adjacency Matrix in C++

## Overview
This project implements a simple **Graph** using an adjacency matrix in C++. The graph is represented as a two-dimensional vector, where each cell indicates the weight of the edge between two vertices. This implementation is for an **undirected** graph, meaning each edge is bidirectional.

## Features
- **Adjacency Matrix Representation:**  
  The graph is stored as an `n x n` matrix (using `vector<vector<int>>`), with each cell `[i][j]` holding the weight of the edge from vertex `i` to vertex `j`. By default, edges have a weight of 1.
  
- **Edge Addition with Validation:**  
  The `addEdge` function allows adding an edge between two vertices and includes checks to ensure the provided vertex indices are valid.

## References
Code retrieved from [GeeksforGeeks](https://www.geeksforgeeks.org/implementation-of-graph-in-cpp/) with the help of ChatGPT and Copilot
