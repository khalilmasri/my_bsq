<!-- GETTING STARTED -->
## My_bsq

### Task Description

This is an algorithm project!! Make it fast or low memory usage or both!

You must find the largest possible square on a board while avoiding obstacles. The board is represented by a file passed as the program’s argument, respecting those constraints:

• Its first line contains the number of lines on the board (and only that),
• . (representing an empty place) and "o" (representing an obstacle) are the only two allowed characters for the other lines
• All of the lines will be the same length (except the first one)
• There will always be at least one line
• Each line is terminated by \n.

You program must print the board, with some "." replaced by "x" to represent the largest square you found.

### Requirements


1. you must create a Makefile, and the ouput is the command itself
2. You can use:

   * malloc(3)
   * free(3)
   * open(2)
   * read(2)
   * close(2)
   * printf(3)
   * write(2)
   
 3. You can NOT use:
 
   * Any functions / syscalls which does not appear in the previous list
   * Yes, it includes exit


### Program Usage

1. From the terminal move to my_bsq directory and run the map_generator.pl perl script with the following command using whatever dimensions(x & y variables must be equal!!), density and filename(.txt)

   ```sh
   perl map_generator.pl [x] [y] [density] > [filename]
   e.g 'perl map_generator.pl 10 10 4 > map.txt'
   ```
2. Compile the C program by typing 'make' into the terminal and run the program from terminal with the program name followed by the filename of your generated map

   ```sh
   e.g './my_bsq map.txt'
   ```
3. Your map will be printed in the terminal with x's denoting the largest square in the map and below a statement of the largest squares size and its coordinates in the map
   ```sh
   .........o
   .o........
   ....ooo.o.
   o.......o.
   xxxo...o..
   xxx.o.....
   xxxo.....o
   o...o...o.
   ..o..o....
   .o.o......

   Largest Square: 3 at Co-ordinates x: 0 y: 4
   ```
4. You can clean up '.o' files by typing the following command after usage
    ```sh
   'make clean'
   ```
