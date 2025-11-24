from pyamaze import maze, agent, textLabel
from queue import PriorityQueue
from timeit import timeit

def manhattan_distance(cell_a, cell_b):
    r1, c1 = cell_a
    r2, c2 = cell_b
    return abs(r1 - r2) + abs(c1 - c2)


def a_star(maze_obj, start=None):
    if start is None:
        start = (maze_obj.rows, maze_obj.cols)

    # priority queue: (f_score, heuristic, cell)
    frontier = PriorityQueue()
    frontier.put((manhattan_distance(start, maze_obj._goal),
                  manhattan_distance(start, maze_obj._goal), start))

    came_from = {}
    g_cost = {cell: float("inf") for cell in maze_obj.grid}
    f_cost = {cell: float("inf") for cell in maze_obj.grid}
    g_cost[start] = 0
    f_cost[start] = manhattan_distance(start, maze_obj._goal)

    visited_order = [start]

    while not frontier.empty():
        current = frontier.get()[2]
        visited_order.append(current)

        if current == maze_obj._goal:
            break

        for direction in "ESNW":
            if maze_obj.maze_map[current][direction]:
                if direction == "E":
                    neighbor = (current[0], current[1] + 1)
                elif direction == "W":
                    neighbor = (current[0], current[1] - 1)
                elif direction == "N":
                    neighbor = (current[0] - 1, current[1])
                elif direction == "S":
                    neighbor = (current[0] + 1, current[1])

                tentative_g = g_cost[current] + 1
                tentative_f = tentative_g + manhattan_distance(neighbor, maze_obj._goal)

                if tentative_f < f_cost[neighbor]:
                    came_from[neighbor] = current
                    g_cost[neighbor] = tentative_g
                    f_cost[neighbor] = tentative_f
                    frontier.put((tentative_f, manhattan_distance(neighbor, maze_obj._goal), neighbor))

    forward_path = {}
    cell = maze_obj._goal
    while cell != start:
        forward_path[came_from[cell]] = cell
        cell = came_from[cell]

    return visited_order, came_from, forward_path


if __name__ == "__main__":
    m = maze(25, 40)
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
