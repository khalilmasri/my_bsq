#include "include/bsq.h"

int main()
{
    
    //read the map
    char_map char_map = read_map_into_array();
    int_map int_map = convert_to_int_map(char_map);
    
    //print the maps
    int_map = bsq(int_map);
    char_map = rewrite_char_map(int_map, char_map);
    print_char_map(char_map);
    printf("\nLargest: %d X: %d Y: %d\n", int_map.largest, int_map.x-int_map.largest + 2, int_map.y - int_map.largest +2);
    //free the memory allocated for the maps
    free_char_map(char_map);
    free_int_map(int_map);
    return 0;
}
