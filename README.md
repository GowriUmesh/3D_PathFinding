# 3D Path Finding
This code finds the shortest path between a start cell and an end cell of a 3D grid.
The code is written in C++ and can be included in any code by inclduing just the header `pathFinder.h`. The function `findPath(Maze,startCell,endCell)` returns the shortest path between the cells in a grid. 
## Objective
You are given a 3D grid of size (N x M x K). Each cell of a grid is either an empty cell (0) or an obstacle(1)
The objective is to find the shortest path from the start cell to the stop cell in the grid given their coordinates.
(e.g., start = [0,0,0], end = [N-1,M-1,K-1]).
## Specifications
* The code is importable , after inclduing `pathFiner.h` in the main code the function `findPath(Maze,startCell,endCell)` can be called from the main code providing the test samples.
* The code is scalable as the input is dynamic and uses vectors
* The function findPath() has the following input/output format
### Inputs
* Grid: 3D array of a custom size filled with 0's and 1's
* Start: list of coordinates of start cell {x_0,y_0,z_0}
* Stop: list of coordinates of start cell {x_end,y_end,z_end}
### Output
* Final path from start cell to end cell as a list of cell coordinates.

## Code Description
The code simply follows the algorithm described below.It implements Breadth First Search algorithm to reach the goal,
and then the bath is bactracked to return a path as cell coordinates
![image](https://user-images.githubusercontent.com/55944277/130051301-a626c8ff-69a0-4a3c-9a1d-ca419eeb6181.png)
The header also includes brief description of each functions to ease the understanding of the code.

## Usage
