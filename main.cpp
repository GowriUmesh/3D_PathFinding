#include "pathFinder.h"
#include<iostream>
using namespace std;

int main(int argc, char **argv){
    int start[3] = {0,0,0}, stop[3] = {2,3,3};
    vector<vector<vector<int>>> Maze={{{0,0,1,1},{0,1,1,1},{1,1,1,0},{0,0,1,0}},{{1,0,1,0},{0,1,0,0},{0,0,1,0},{0,0,0,0}},{{1,0,1,0},{1,1,0,1},{1,0,0,1},{0,0,1,0}}};

    vector<vector<int>> Path = findPath(Maze, start,stop);
    cout<<"The shortest path from the Start Cell and End Cell is:"<<endl;
    for(int i=0;i<Path.size();i++){
        cout<<Path[i][0]<<" "<<Path[i][1]<<" "<<Path[i][2]<<endl;
    }

}
