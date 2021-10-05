#include "include/bsq.h"

int get_min(int first,int second, int third){

    if(first <= second && first <= third)
        return first;
    else if(second <= first && second <= third)
        return second;
    else
        return third;
}


int_map bsq(int_map map){

    int x, y,
        min;

    map.largest = 0;

    for(y = 1; y < map.size; y++){
        for(x = 1; x < map.size; x++){
            if(map.map[y][x] != 0 && map.map[y-1][x] != 0 && map.map[y-1][x-1] != 0 && map.map[y][x-1] != 0){
                min = get_min(map.map[y-1][x],map.map[y][x-1],map.map[y-1][x-1]);
                map.map[y][x] += min;
                if(map.map[y][x] > map.largest){
                    map.x = x;
                    map.y = y;
                    map.largest = map.map[y][x];
                }
            }
        }
    }

    return map;
}

