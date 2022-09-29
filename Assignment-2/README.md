# The second assignment 

Your task is to complete the functions listed below. Together these functions
provide functionality to draw filled triangles on the screen. In addition, the
functions enable you to scale the size of a triangle and move (translate) a
triangle to a given position on the screen.
Each triangle is described by a triangle_t data structure. All the functions below
accept a pointer to a triangle data structure as input. Each function needs to
access and modify the fields of the data structure as appropriate.

• ScaleTriangle - Scale the size of the triangle. The scaling factor is specified
in the scale field in the triangle data structure. The scaling factor is a floating
point number. A factor less than 1.0 should decrease the size of the triangle,
while a factor greater than 1.0 should increase the size.
• TranslateTriangle - Move the triangle to a specific position on the screen.
The position is specified in the triangle data structure in the tx and ty fields.
• CalculateTriangleBoundingBox - Calculate the size of a rectangle that is
just large enough to contain the triangle. The bx, by, bw, and bh fields of the
triangle data structure should be initialized with the appropriate values.
• FillTriangle - Fill the triangle with a color. The fillcolor field in the triangle
data structure specifies the fill color. There exist many different approaches
for filling triangles and polygons in general. See the Resources section below
for some inspiration.
• DrawTriangle - Draw a scaled, translated, and filled triangle on the screen.

In this assignment, there should be no need to define functions beyond those
already defined in the files we provide. We recommend starting with code to
draw a wireframe version of the triangle on the screen (by use of the DrawLine
function). 
Then, either proceed with the code to scale the triangle, or the code to move the
triangle to a given position on the screen. Note that triangle scale is specified as
a floating-point number, while the triangle coordinates are integer variables. You
will need to think about conversions between integer and floating-point numbers
to make the scaling function work properly. When scaling, translation, and
drawing works, embark on the code for filling the triangles.
Once you have working code for drawing triangles, you can test it by drawing a
colorful teapot on the screen, using a triangle-based model that UiT provide. 

The teapot model is represented as an array of pre-initialized triangle data
structures. The model is contained within a 1000x1000 box, with coordinates
ranging from -500 to 500 on both the x and y axis. To properly draw this model,
you must translate it to the middle of the screen. Note that in this assignment we
set the resolution of the screen to 1024x768 pixels. If translated to the middle of
the screen, the teapot model does not have y coordinates that exceed the
resolution of the screen. Thus there is no need to scale the teapot before drawing
it.
