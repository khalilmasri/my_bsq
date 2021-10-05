#include "include/bsq.h"

//function to read the map size from the first line of the file map.txt
int read_map_size()
{
    int size = 0;
    char c;
    //open the file
    int fd = open("map.txt", O_RDONLY);
    if(fd < 0){
        printf("Error\n");
        return 0;
    }
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

//function to replace the '.' with 0 and 'o' with 1 and write to int_map
int_map convert_to_int_map(char_map map)
{
    int_map int_map;
    int i, j;
    int_map.size = map.size;
    int_map.map = malloc(sizeof(int *) * int_map.size);
    for (i = 0; i < int_map.size; i++)
    {
        int_map.map[i] = malloc(sizeof(int) * int_map.size);
        for (j = 0; j < int_map.size; j++)
        {
            if (map.map[i][j] == '.'){
                int_map.map[i][j] = 1;
			}
            else{
                int_map.map[i][j] = 0;
			}
        }
    }
    return int_map;
}

//function to read the map from the file map.txt exluding the first line
char_map read_map_into_array()
{
    char c;
    char_map map;
    int size = read_map_size();
    if(size == 0){

        printf("Error\n");
    }
    map.size = size;
    map.map = malloc(sizeof(char *) * size);
    int i, j;
    //open the file
    int fd = open("map.txt", O_RDONLY);
    //read the first line
    while(c != '\n'){
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
