#ifndef ROAD_H
#define ROAD_H
class Road
{
    bool hasObstacle;
    int roadWidth;

public:
    void set_metadata(int roadWidth, bool hasObstacle); 
    void draw_road();
    void draw_player(int x, int y);
};

#endif