/**
 * Author:    Gowri Umesh <mailgowriumesh@gmail.com>
 * Created:   18.Aug.2021
 * License:   MIT
 * Filename:  pathFinder.h
 * Version:   0.2
 * Edited:    16.Mar.2025
 * 
 * Description:This header finds the shortest path between
 * a start cell and an end cell of a given 3D grid
 * The code uses Breadth First Search to find the goal.
 **/

#ifndef PATHFINDER_H
#define PATHFINDER_H


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/**
 * Cell - strucure cell with all its attributes
 * x,y,z: cell positions
 * id: unique cell id
 * parent: cells parent ID so it can be mappep
 */

typedef struct{
    int x, y,z,id,parent;
    
} Cell;


Cell startCell,endCell,currentCell;
vector<Cell> visitedCells;
vector<Cell> waitingList;
vector<vector<int>> shortestPath;
bool reached = false;

/**
 * reconstructPath - Reconstruct the Path
 * @visitedCells: vector of all the visited cells
 *
 * Description: This function reconstructs the path by
 * mapping each cell to its parent cell beginning with the end cell.
 */
void reconstructPath(vector<Cell>& visitedCells){
    
    if(visitedCells.empty()){
        cout<<"Error! No visted cells to reconstruct the path!"<<endl;
        return; 
    }
    
    vector<Cell> shortPath;
    for(int k=visitedCells.size()-1;k!=startCell.id;k=visitedCells[k].parent){
        shortPath.push_back(visitedCells[k]);
    }
    shortPath.push_back(startCell);
    for(int j=shortPath.size()-1;j>=0;j--){
        shortestPath.push_back({shortPath[j].x,shortPath[j].y,shortPath[j].z});
    }
}

/**
 * findNeighbors - find neighbour of each cell in the grid
 * @Maze: 3D vector filled with 0's and 1's
 * @neighbours: Vector of neighbour cells of the current cell
 * @currentCell: current cell whose neighbours are to be found
 *
 * Description: This function finds all the possible neighbours
 * of the current cells. Only a neighbour that is within bounds
 * of the grid and is not obstacle is pushed as a valid neighbour.
 * The fuctions returns vector of neighbour cells.
 * To find the neighbours direction vectors are considered along
 * x,y and z directions as for a cell there can only be 6 possible
 * neighbours.
 *
 */
vector<Cell> findNeighbors(vector<vector<vector<int>>> Maze,vector<Cell> neighbours, Cell currentCell){
    Cell N ;
    int dirX[] = {-1,1,0,0,0,0};
    int dirY[] = {0,0,-1,1,0,0};
    int dirZ[] = {0,0,0,0,-1,1};
    int row,col,depth;
    for(int i=0;i<6;i++){
        row = currentCell.x + dirX[i];
        col = currentCell.y + dirY[i];
        depth = currentCell.z + dirZ[i];
        if(!(row < 0 || col < 0 || depth < 0) && ! (row > (Maze.size()-1) || col > (Maze[0].size()-1) || depth> (Maze[0][0].size()-1) )  && !(Maze[row][col][depth] == 1)){
                N.x = row; N.y = col; N.z= depth;
                neighbours.push_back(N);
        }
    }
    return neighbours;
}

/**
 * find - finds if a neighbour cell is present in Visited cells
 * @visitedCells: Vector of visited cells
 * @neighbour: a single neighbour cell
 *
 * Description: This function finds if cell neighbour is present
 * in vector of visited cells and returns true to confirm the
 * presence or false otherwise.
 */
bool find(vector<Cell> visitedCells, Cell neighbour){
    for(int i=0;i<visitedCells.size();i++){
        if(visitedCells[i].x==neighbour.x && visitedCells[i].y == neighbour.y && visitedCells[i].z == neighbour.z){
            return true;
        }
    }
   return false;
}

/**
 * findPath - finds path
 * @Maze: 3D vector filled with 0's and 1's
 * @start: start cell of the grid
 * @stop: end cell of the grid
 *
 * Description: This function finds the shortest path
 * between the start cell and stop cell. The function uses
 * vector visitedCells for keeping track of all the visited
 * cells and waitingList that contains all the cells to be
 * explored
 */
vector<vector<int>> findPath(vector<vector<vector<int>>> Maze,int start[3],int stop[3]){

    int counter=0;
    vector<Cell> neighbours;

    startCell = {start[0], start[1], start[2], counter++,-1};
    endCell = {stop[0], stop[1], stop[2], -1,-1};
    
    waitingList.push_back(startCell);
    visitedCells.push_back(startCell);

    while(!(waitingList.empty()) && !reached){

        currentCell = waitingList.front();
        waitingList.erase(waitingList.begin());
        visitedCells.push_back(currentCell);

        if(currentCell.x == endCell.x && currentCell.y == endCell.y && currentCell.z == endCell.z){
            reached = true;
            cout<<"Path Found"<<endl;
            reconstructPath(visitedCells);
        }

        else{
            neighbours = findNeighbors(Maze,neighbours,currentCell);
            while(neighbours.size()>0){
                if(!find(visitedCells,neighbours.back()))
                {
                    counter++;
                    neighbours.back().id=counter;
                    neighbours.back().parent=currentCell.id;
                    waitingList.push_back(neighbours.back());
                }
            neighbours.pop_back();
            }
        }
    }
    if(!reached){
        cout<<"No Path Found between the start cell and stop cell"<<endl;
        shortestPath.clear();
    }
    return shortestPath;

}

#endif // PATHFINDER_H
