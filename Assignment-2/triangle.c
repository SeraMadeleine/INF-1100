#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "triangle.h"
#include "drawline.h"

#define TRIANGLE_PENCOLOR   0xBBBB0000

int max_value(int a, int b, int c);
int min_value(int a, int b, int c);

/* 
 * Print triangle coordinates along with a message
 */
void print_triangle(triangle_t *triangle, char *msg)
{
    printf("%s: %d,%d - %d,%d - %d,%d\n",
        msg,
        triangle->x1, triangle->y1, 
        triangle->x2, triangle->y2, 
        triangle->x3, triangle->y3);
}

/*
 * Return 0 if triangle coordinates are outside the surface boundary. 1 otherwise.
 */
int sanity_check_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    if (triangle->sx1 < 0 || triangle->sx1 >= surface->w || // || logical OR opperator 
        triangle->sx2 < 0 || triangle->sx2 >= surface->w ||
        triangle->sx3 < 0 || triangle->sx3 >= surface->w ||
        triangle->sy1 < 0 || triangle->sy1 >= surface->h ||
        triangle->sy2 < 0 || triangle->sy2 >= surface->h ||
        triangle->sy3 < 0 || triangle->sy3 >= surface->h) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * Scale triangle, altering the on-screen coordinates(e.g. triangle->sx1)
 */
void scale_triangle(triangle_t *triangle)
{
    // TODO: Replace the code below with code that scales each triangle coordinate. 
    // We define the on surface coordinates to be eqal to the coordinates of the model * scale, witch is defined in teapot 
    // Scale determens if the size of the triangle and is defined as a flot (see triangel.h)
    
    triangle->sx1 = (triangle -> x1 * triangle -> scale); // The on-screen coordinates are equal to the model coordinates multiplide with the scaling factor 
    triangle->sy1 = (triangle -> y1 * triangle -> scale); 
    triangle->sx2 = (triangle -> x2 * triangle -> scale);
    triangle->sy2 = (triangle -> y2 * triangle -> scale);
    triangle->sx3 = (triangle -> x3 * triangle -> scale);
    triangle->sy3 = (triangle -> y3 * triangle -> scale);    
}

/*
 * Move the triangle to the center of the surface,
 * altering the on-screen coordinates(e.g. triangle->sx1)
 */
void translate_triangle(triangle_t *triangle)
{
    // TODO: Insert code that moves the triangle on the surface.

    triangle->tx = 1024/2; // screen_w/2 to find the middel of the windo 
    triangle->ty = 768/2; // screen_h/2 to find the middel of the windo 

    // Update the on-surface coordinates so the triangles are moved the center of the surface
    triangle->sx1 = (triangle->tx + triangle->sx1); 
    triangle->sy1 = (triangle->ty + triangle->sy1);
    triangle->sx2 = (triangle->tx + triangle->sx2); 
    triangle->sy2 = (triangle->ty + triangle->sy2);
    triangle->sx3 = (triangle->tx + triangle->sx3); 
    triangle->sy3 = (triangle->ty + triangle->sy3);
    
}

/*
 * Calculate the triangle bounding box,
 * altering fields of the triangle's rect(e.g. triangle->rect.x)
 */
void calculate_triangle_bounding_box(triangle_t *triangle)
{
    // TODO: Insert code that calculates the bounding box of a triangle.

    /*
    Find the minimum value of x and y by using the min_value function
    Then rect.x and rect.y is set as the minimum value witch is the coordinates 
    in the left corner. 
    Find the maksimum value of x and y by using the max_value function
    Set rect.h and rect.w as the maximum value as x and y
    */   
    int x_max, x_min, y_max, y_min; 

    // Use the functions in the bottom of the script to find max and min value for the on screen coordinates of x and y
    x_min = min_value(triangle->sx1, triangle->sx2, triangle->sx3); 
    x_max = max_value(triangle->sx1, triangle->sx2, triangle->sx3); 
    y_min = min_value(triangle->sy1, triangle->sy2, triangle->sy3);
    y_max = max_value(triangle->sy1, triangle->sy2, triangle->sy3);

    triangle->rect.x = x_min; // x-coordinate of the bounding box' top left corner
    triangle->rect.y = y_min; // y-coordinate of the bounding box' top left corner
    triangle->rect.w = x_max; // width of the bounding box
    triangle->rect.h = y_max; // height of the bounding box
    // printf("x er %d \n y er %d \n w er %d \n h er %d \n", triangle->rect.x, triangle->rect.y, triangle->rect.w, triangle->rect.h); // to test the codinates of the bounding box 
}


/*
 * Fill the triangle on the surface with the triangle's color
 */
void fill_triangle(SDL_Surface *surface, triangle_t *triangle)
{ 
    // TODO: Insert code that fills the triangle with the color specified in triangle->fillcolor.
    // This can be done with both y as the outer loop and x as the inner loop (then we draw the line from right to left)
    // and it can be done with x as the outer loop and y as the inner loop (then we draw the line from top to bottom)
    
int  x1, x2, y; 
    for (y = triangle -> rect.y; y <= triangle -> rect.h ; y++) // From the smalest y value (left corner) to the largest y value 
        {
            for (int  x = triangle ->rect.x; x <= triangle ->rect.w; x++) // From the smalest x value (left corner) to the largest x value (witch i )
            {
                if (get_pixel(surface, x, y) == triangle ->fillcolor) // Find when the pixels have the fillcolor, from left to right 
                { 
                    x1 = x;     // Save the x coordinate where the fillcolor is detected 
                    break;      // Break the loop
                }
            }
            for (int x = triangle -> rect.w; x >= triangle ->rect.x; x --)
            {
                if (get_pixel(surface, x, y) == triangle ->fillcolor) // Find when the pixels have the fillcolor, from right to right 
                {
                    x2 = x;     // Save the x coordinate where the fillcolor is detected 
                    break;      // Break the loop
                }
            }
            draw_line(surface, x1, y, x2, y, triangle ->fillcolor); // Draw a line between the left pixel where fillcolor is detected and the right pixel where fillcolor is detected 
        }  
}

/*
 * Draw a filled triangle on the given surface
 */

void draw_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    int isOK;

    // Scale. 
    scale_triangle(triangle);
    
    // Translate. 
    translate_triangle(triangle);
    
    // Determine bounding box 
    calculate_triangle_bounding_box(triangle);

    // Sanity check that triangle is within surface boundaries.
    isOK = sanity_check_triangle(surface, triangle);
    if (!isOK) {
        print_triangle(triangle, "Triangle outside surface boundaries");
        return;
    }

    /* 
     * TODO: Insert calls to draw_line to draw the triangle.
     * Use the on screen coordinates to draw the outer lines for the teapot 
     */

    draw_line(surface, triangle -> sx1, triangle -> sy1, triangle -> sx2, triangle -> sy2, triangle ->fillcolor); 
    draw_line(surface, triangle -> sx2, triangle -> sy2, triangle -> sx3, triangle -> sy3, triangle ->fillcolor);
    draw_line(surface, triangle -> sx3, triangle -> sy3, triangle -> sx1, triangle -> sy1, triangle ->fillcolor);

    /* Fill triangle */
    fill_triangle(surface, triangle);
}

/*
* Find minimum value 
* a is x1, y1 
* b is x2, y2 
* c is x3, y3 
*/

int min_value(int a, int b, int c) {
    int min; 

    if ((a <=  b) && (a <= c))
    {
        min = a; 
    }

    else if ((b <= a) && (b <= c))
    {
        min = b;
    }

    else if ((c <= a) && (c <= b))
    {
        min = c;
    }

    return min; 
}


/*
* Find maximum value 
* a is x1, y1 
* b is x2, y2 
* c is x3, y3 
*/

int max_value (int a, int b, int c) {
    int max; 
    if ((a >= b) && (a >= c))
    {
        max = a; 
    }

    else if ((b >= a )&& (b >= c))
    {
        max = b;
    }

    else 
    {
        max = c;
    }
    return max;
    
}