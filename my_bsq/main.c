#include "include/bsq.h"

int main(int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf("Please enter map '.txt' file");
        return 1;
    }
    else
    {
        char *map_file = malloc(sizeof(char) * strlen(argv[1]));
        strcpy(map_file, argv[1]);
    
        //read the map
        if (read_map_size(map_file) == 1)
        {
            return 1;
        }
        char_map char_map = read_map_into_array(map_file);
        int_map int_map = convert_to_int_map(char_map);

        //print the maps
        int_map = bsq(int_map);
        char_map = rewrite_char_map(int_map, char_map);
        print_char_map(char_map);
        printf("\nLargest Square: %d at Co-ordinates x: %d y: %d\n", int_map.largest, int_map.x - int_map.largest + 1, int_map.y - int_map.largest + 1);
        //free the memory allocated for the maps
        free_char_map(char_map);
        free_int_map(int_map);
        free(map_file);
    }
    return 0;
}
