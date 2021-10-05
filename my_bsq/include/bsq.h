#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef struct map_s 
{
    char **map; // 2D array of chars
    int size; // size of the map
} char_map;

typedef struct int_map_s
{
    int **map; // 2D array of ints
    int x;
    int y;
    int largest;
    int size; // size of the map
} int_map;

#endif

//-----------------------------------------------------------------------------------------------
	
#ifndef READ_MAP_H
#define READ_MAP_H

int read_map_size(char*);	
char_map read_map_into_array(char*);
int_map convert_to_int_map(char_map);

#endif

//-----------------------------------------------------------------------------------------------

#ifndef BSQ_H
#define BSQ_H

int_map bsq(int_map map);

#endif

//-----------------------------------------------------------------------------------------------

#ifndef UTILITY_H
#define UTILITY_H

char_map rewrite_char_map(int_map int_map, char_map char_map);
void print_char_map(char_map map);
void free_int_map(int_map map);
void free_char_map(char_map map);

#endif