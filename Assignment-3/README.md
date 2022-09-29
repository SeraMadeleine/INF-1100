# Assignment 3

Your task is to implement a variant of the classic bouncing ball animation. To give
you an idea of what such an animation could look like we've enclosed a windows
executable as part of this assignment (see files section on Canvas). Aim to
develop something like what you see in this example.
Each ball should start off at the top of the screen with a random speed in the x
direction. Whenever a ball hits a screen boundary it should bounce off at an
angle equal to the impact angle and lose some speed. Eventually each ball
should come to a rest at the bottom of the screen. Five seconds after coming to a
rest a ball should be removed from the screen.
To ensure that the balls come to a rest at the bottom of the screen you need a
constant gravity pulling on each ball. The direction of the gravity should be down.
Each ball must be represented as a separate object data structure (see "object.h"
in the zip file). The object data structure contains all variables pertinent to
rendering the object on the screen (translation, scale, model coordinates, etc.).
Note   that   the   object   data   structure   uses   floats   to   represent   translation
coordinates. This is to make it easier to handle very small movements (at points,
a ball might be moving at a speed less than a pixel). Cast the translation
coordinates into integers before drawing the triangles on the screen.
Your code must keep track of objects (balls) by placing the object data structures
in a linked list. You need to create your own linked list implementation. Below is a
brief description of the object programming interface:
CreateObject - Create a new object. The function accepts as input 
parameters a pointer to the SDL screen, a pointer to a model triangle array, 
and a variable telling the size of the model triangle array. The function returns
a pointer to a new object data structure. The model triangle array specified as
input parameter should not be shared across objects. (Not sharing the model 
triangle array allows e.g. objects to have different colors.) Perform the 
necessary memory allocation and copying.
DestroyObject - Free object. The function accepts as input parameters a 
pointer to an object data structure. The function should free all memory 
allocated to represent the object (memory allocated for the model triangle 
array and the object data structure itself).
Drawobject - Draw object on screen. The function accepts as input 
parameters a pointer to an object data structure. The function must draw the 
object on the screen by calling DrawTriangle on each of the model triangles. 
Remember to update scale, translation, etc., in each triangle data structure 
before invoking DrawTriangle.
Hint: Do not make the bouncing algorithm too complex. Bouncing a ball off a 
vertical or horizontal surface can be accomplished without resorting to 
calculating impact angles.
Code
Your starting point is the following set of files:
drawline.h - Specifies the interface of the drawline function.
drawline.c - Implements the DrawLine function.
triangle.h- Specifies the triangle data structure and the interface to the
DrawTriangle function.
triangle.c- Draw triangle and friends.
teapot_data.h- Coordinates for the classic teapot model.
sphere_data.h- Coordinates for a sphere model.
list.h- Specifies the interface of the list functionality. Do not modify this file
list.c- Empty stubs for each function in the list interface. Modify this file.
object.h - Specifies the interface of the object functionality. Do not modify
this file
object.c - Empty stubs for each function in the object interface. Modify this
file.
main.c- Contains the main function and calls to initialize SDL. Place your
bouncing ball code in this file.
bouncingballs64.exe - Executable showing what your result might look like.
Copy this file to your source folder and run make before attempting to run
the executable.
Makefile - A Makefile for compiling the code.
We've bundled these files in a zip file. Use this zip file as a starting point, as it
also includes the necessary SDL files
