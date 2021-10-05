#include "include/bsq.h"

//free the memory allocated for the map
void free_char_map(char_map map)
{
    int i;
    for (i = 0; i < map.size; i++)
    {
        free(map.map[i]);
    }
    free(map.map);
}

void free_int_map(int_map map)
{
    int i;
    for (i = 0; i < map.size; i++)
    {
        free(map.map[i]);
    }
    free(map.map);
}

//print the map
void print_char_map(char_map map){
    int i, j;
    for (i = 0; i < map.size; i++)
    {
        for (j = 0; j < map.size; j++)
        {
            printf("%c", map.map[i][j]);
        }
        printf("\n");
    }
}

char_map rewrite_char_map(int_map int_map, char_map char_map){

    int largest = int_map.largest - 1;

    for(int y = int_map.y - largest; y <= int_map.y; y++){
        for(int x = int_map.x - largest;x <= int_map.x ; x++){
            char_map.map[y][x] = 'x';
        }
    }

    return char_map;
}
