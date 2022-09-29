#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "object.h"


/*
 * Return a newly created object based on the arguments provided.
 */
object_t *create_object(SDL_Surface *surface, triangle_t *model, int numtriangles)
{
    object_t *new_object; // new_object exists in the object struckt 
    new_object = malloc(sizeof(object_t)); //allocate memory for the new object 
    new_object -> model = malloc(sizeof(triangle_t)*numtriangles);

    new_object -> surface = surface; // the object is placed on the surface 
    new_object -> scale = 0.1; 
    new_object -> rotation = 0.5; 
    new_object -> radius = (1000*new_object -> scale)/2; // the radius to the object 
    new_object -> tx = surface -> w/2; // place the object in the middle of the screen 
    new_object -> ty = surface -> h/2; // place the object in the middle of the screen 

    //startposition  
    new_object -> tx = 0 + new_object -> radius;
    new_object -> ty = 0 + new_object -> radius;

    new_object -> speedx = (10+5*(float)rand())/RAND_MAX; // a random speed for the x direction 
    new_object -> speedy = 6; // speed for the y direction 
    new_object -> ttl = 5; // who many seconds until the ball disappears  
    new_object -> numtriangles = numtriangles; 
    new_object -> model = model;

    return new_object;  // returns the new object 
}

/*
 * Destroy the object, freeing the memory.
 */
void destroy_object(object_t *object)
{
    if(object == NULL) { 
        return;
    }
    free(object);
}

/*
 * Draw the object on its surface.
 */
void draw_object(object_t *object)
{
   for (int i = 0; i < object -> numtriangles; i++) // 
    {
        object->model[i].tx = object->tx; // runs through all the tx values for the given object  
        object->model[i].ty = object->ty; // runs through all the ty values for the given object  
        object->model[i].scale = object->scale; // runs through the scale values for the given object  
        object->model[i].rotation = object->rotation; // runs through the rotation values for the given object  
        draw_triangle(object->surface, &object->model[i]); // Draw the triangle 
    } 
} 

