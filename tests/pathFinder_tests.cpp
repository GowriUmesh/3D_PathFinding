#include <gtest/gtest.h>
#include "../pathFinder.h"  

/*
* Author:    Gowri Umesh <mailgowriumesh@gmail.com>
* Created:   16.Mar.2025
* License:   MIT
* Filename:  pathFinder_tests.cpp
* Version:   0.1

* Test cases : to test reconstructPath() function
* 1. Reconstruct path with no visited cells (edge case).
* 2. Reconstruct path when visited cells contain valid path.
* 3. Reconstruct path when start and end are the same.    

* To do:
* Add more test cases to test the reconstructPath() function.
* Add test cases : find().
* Add test cases : the findPath().
* Add test cases : the findNeighbors().
* Add test cases : the main().
*/

// Test case 1: Reconstruct path with no visited cells.
TEST(ReconstructPathTest, NoVisitedCells) {
    
    vector<Cell> visitedCells;
    shortestPath.clear();
    reached = false;
    reconstructPath(visitedCells);
    ASSERT_TRUE(shortestPath.empty());
}

// Test case 2: Reconstruct path when visited cells contain valid path.
TEST(ReconstructPathTest, ValidPath) {

    vector<Cell> visitedCells = {
        {0, 0, 0, 0, -1},
        {1, 0, 0, 1, 0},
        {1, 1, 0, 2, 1},
        {2, 1, 0, 3, 2}
    };

    startCell = {0, 0, 0, 0, -1};
    endCell = {2, 1, 0, -1, -1};

    shortestPath.clear();
    reached = false;
    
    reconstructPath(visitedCells);

    // Validate the reconstructed path
    ASSERT_EQ(shortestPath.size(), 4);
    ASSERT_EQ(shortestPath[3][0], 2);
    ASSERT_EQ(shortestPath[3][1], 1);
    ASSERT_EQ(shortestPath[2][0], 1);
    ASSERT_EQ(shortestPath[2][1], 1);
    ASSERT_EQ(shortestPath[1][0], 1); 
    ASSERT_EQ(shortestPath[1][1], 0);
    ASSERT_EQ(shortestPath[0][0], 0);
    ASSERT_EQ(shortestPath[0][1], 0);
}

// Test case 3: Reconstruct path when start and end are the same.
TEST(ReconstructPathTest, StartEqualsEnd) {
    vector<Cell> visitedCells = {
        {0, 0, 0, 0, -1}
    };

    startCell = {0, 0, 0, 0, -1};
    endCell = {0, 0, 0, 0, -1};

    shortestPath.clear();
    reached = false;
    reconstructPath(visitedCells);

    ASSERT_EQ(shortestPath.size(), 1);
    ASSERT_EQ(shortestPath[0][0], 0); 
    ASSERT_EQ(shortestPath[0][1], 0);
}


