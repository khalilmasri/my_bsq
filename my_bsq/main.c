#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct map_s 
{
    char **map; // 2D array of chars
    int size; // size of the map
} char_map;

typedef struct int_map_s
{
    int **map; // 2D array of ints
    int size; // size of the map
} int_map;

//function to read the map size from the first line of the file map.txt
int read_map_size()
{
    int size = 0;
    char c;
    //open the file
    int fd = open("map.txt", O_RDONLY);
    //read the first line
    read(fd, &c, 1);
    //read the size of the map
    while (c != '\n')
    {
        size = size * 10 + (c - '0');
        read(fd, &c, 1);
    }
    //close the file
    close(fd);
    return size;
}

//function to read the map from the file map.txt exluding the first line
char_map read_map_into_array()
{
    char c;
    char_map map;
    int size = read_map_size();
    map.size = size;
    map.map = malloc(sizeof(char *) * size);
    int i, j;
    //open the file
    int fd = open("map.txt", O_RDONLY);
    //read the first line
    while(c != '\n')
    {
        read(fd, &c, 1);
    }
    //read the map
    for (i = 0; i < size; i++)
    {
        map.map[i] = malloc(sizeof(char) * size);
        for (j = 0; j < size; j++)
        {
            read(fd, &c, 1);
            map.map[i][j] = c;
        }
        read(fd, &c, 1);
    }
    //close the file
    close(fd);
    return map;
}

//function to replace the '.' with 0 and 'o' with 1 and write to int_map
int_map convert_to_int_map(char_map map)
{
    int_map int_map;
    int i, j;
    int_map.size = map.size;
    int_map.map = malloc(sizeof(int *) * int_map.size);
    for (i = 0; i < int_map.size + 1; i++)
    {
        int_map
    }
    for (i = 0; i < int_map.size; i++)
    {
        int_map.map[i] = malloc(sizeof(int) * int_map.size);
        for (j = 0; j < int_map.size; j++)
        {
            if (map.map[i][j] == '.')
            {
                int_map.map[i][j] = 0;
            }
            else
            {
                int_map.map[i][j] = 1;
            }
        }
    }
    return int_map;
}

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
void print_char_map(char_map map)
{
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

void print_int_map(int_map map)
{
    int i, j;
    for (i = 0; i < map.size; i++)
    {
        for (j = 0; j < map.size; j++)
        {
            printf("%d", map.map[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    int i, j;
    //for testing purposes this will generate a map automatically, change the x y & density in this system call
    system("perl map_generator.pl 10 10 2 > map.txt");

    //read the map size
    printf("map size: %d\n", read_map_size());
    //read the map
    char_map char_map = read_map_into_array();
    int_map int_map = convert_to_int_map(char_map);
    //print the maps
    print_char_map(char_map);
    print_int_map(int_map);
    //free the memory allocated for the maps
    free_char_map(char_map);
    free_int_map(int_map);
    return 0;
}