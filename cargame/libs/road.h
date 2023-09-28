#ifndef ROAD_H
#define ROAD_H
#include <iostream>
#include <vector>
#include "player.h"
class Road
{
    int roadWidth;
    int obstacleCount;
    std::vector<int> obstaclePosition;
    Player *player;

public:
    void set_metadata(int roadWidth, int obstacleCount, Player *player); 
    void draw_road(int yAxis, int displayLength);
};

#endif