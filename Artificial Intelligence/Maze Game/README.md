# A* Maze Game Solver with Pyamaze
This project demonstrates the A pathfinding algorithm* applied to a randomly generated maze using the `pyamaze` library. It visualizes how the algorithm explores the maze and constructs the shortest path to the goal.

## Code Snippet
```py
if __name__ == "__main__":
    m = maze(25, 35)
    m.CreateMaze(pattern="h", loopPercent=100)
    timer = timeit(stmt='a_star(m)', number=1000, globals=globals())

    visited_order, came_from, forward_path = a_star(m)

    search_agent = agent(m, footprints=True, color="blue", filled=True)
    parent_agent = agent(m, 1, 1, footprints=True, color="yellow", filled=True, goal=(m.rows, m.cols))
    path_agent = agent(m, footprints=True, color="red")

    m.tracePath({search_agent: visited_order}, delay=50)
    m.tracePath({parent_agent: came_from}, delay=50)
    m.tracePath({path_agent: forward_path}, delay=50)

    textLabel(m, "A* Path Length", len(forward_path) + 1)
    textLabel(m, "A* Search Length", len(visited_order))
    textLabel(m, "A* Time (1000 runs)", timer)
    m.run()
```

## Example Output
https://github.com/user-attachments/assets/7f160aa3-7ae6-46b9-88f9-4bca20f1d7ca



