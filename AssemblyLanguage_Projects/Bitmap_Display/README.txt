Gabriel Dimas
gadimas
Fall 2021
Lab 4: Functions and Graphics

-----------
DESCRIPTION

In this lab, we were continued our learning with assembly language using MIPS and MARS. We implemented
operations on a bitmap to simulate a display. With the test cases, we were able to draw horizontal and
vertical lines and implement other functions that allow the user to change different colors of the display.
We used the memory mapped IO in the display tools in MARS. We use macro functions, MMIO, subroutines, 
MIPS stack, and arrays in the program.

-----------
FILES

-
lab4.asm
The is the source file for my lab. It includes my assembly code for this project.

-
lab4_f21_test.asm
This is the test file I used to ensure that lab4.asm passes all test cases


-----------
INSTRUCTIONS

The user uses the test cases to input an XY coordinate along with an RBG value in hexadecimal to store
that pixel address with that specified color. For example, if you want to change the pixel at the
coordinate (14, 53) to a white color, we would make the following implementation: $a0 = 0x00140053
and $a1 = 0x00ffffff. The formatCoordinate function changes the coordinate register ($a0) into 
a mapped memory address routed to the actual address of the pixel. The program then stores the
RGB value in that address in memory and it displays that color to the screen.
