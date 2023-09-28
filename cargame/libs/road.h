#ifndef ROAD_H
#define ROAD_H
#include <iostream>
#include <vector>
class Road
{
    int roadWidth;
    int obstacleCount;
    std::vector<int> obstaclePosition;

public:
    void set_metadata(int roadWidth, int obstacleCount); 
    void draw_road();
    void draw_player(int x, int y);
};

#endif