#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "list.h"
#include "teapot_data.h"
#include "sphere_data.h"
#include "object.h"

/* Two macro's that find the lesser or greater of two values */
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

/*
 * Clear the surface by filling it with 0x00000000(black).
 */
void clear_screen(SDL_Surface *surface)
{
    if(SDL_FillRect(surface, NULL, 0x00000000) < 0){
        fprintf(stderr, "Unable to clear the surface. Error returned: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

/*
 * Accelerate the object; altering its speed based on the boost given.
 */
void accelerate_object(object_t *a, float boost, float maxspeed)
{
    float s;
    float news;
    
    /* Calculate length of speed vector */
    s = sqrtf(a->speedx * a->speedx + a->speedy * a->speedy);

    /* Boost speed */
    news = s * boost;
    if (news < 0.0)
        news = 0.0;
    if (news > maxspeed)
        news = maxspeed;    
    a->speedx *= news/s;
    a->speedy *= news/s;
}

/*
 * Animate bouncing balls on the screen.
 */
void bouncing_balls(SDL_Window *window)
{
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Event event;
    list_t *newlist = list_create();  //  Sets list to be the function that returns a newly crated, empty list 
    object_t *balls;

    // fps locks to get a smooth and even movement  
    int time1 = 100; // the number of frames  you want
    unsigned int actual_time = 1000/time1; 

    int number_balls = 3; // the number of balls you want to draw on the screen 

    while (number_balls > 0) {
        balls = create_object(surface, sphere_model, SPHERE_NUMTRIANGLES); // create a ball 
        list_addfirst(newlist, balls); // make a list for each ball 
        accelerate_object(balls, 2+2*rand(), 12); // accelerate the object

        number_balls--; // update the number of balls 
    }

    list_iterator_t *iter = list_createiterator(newlist); // retuns a newly crated list iterator for the given list, witch is the list above

    int done = 0;

    while(!done){
        unsigned int time_start = SDL_GetTicks(); // take the time we spend to run the program
        clear_screen(surface); // update the screen so the balls do not get drawn over eachother 

        for (balls = list_next(iter); balls != NULL; balls = list_next(iter)) {
            
            // this crates new balls until the you close the screen, same loop as before the while not done 
            while (number_balls > 0) {
                balls = create_object(surface, sphere_model, SPHERE_NUMTRIANGLES); 
                list_addlast(newlist, balls); // can also use list_addfirst(newlist, balls);
                accelerate_object(balls, 9, 12); // accelerate object
                number_balls --;
            }

            float gravity = 0.5; // the gravity draws the object to the ground 
            float speed = -0.6; // the speedfactor that make the object turn and lose some speed when it hits the boundary

            balls -> speedy += gravity; // the gravity added to the y speed because it works in the y direction 
            balls -> tx += balls -> speedx; // update the x coordinate so it is correct given the x speed 
            balls -> ty += balls -> speedy; // update the y coordinate so it is correct given the y speed 
            balls -> rotation += balls -> speedx;

        if (balls -> tx + balls -> radius >= surface -> w || balls -> tx - balls -> radius<= 0) {
            balls -> speedx *= speed; // turn the object and make it loose some speed 
            balls -> tx += balls -> speedx; // to prevent the object from ending up outside the boundary
        }

        if (balls -> ty + balls -> radius >= surface -> h || balls -> ty - balls -> radius <= 0) {
            
            balls -> speedy *= speed; // turn the object and make it loose some speed 
            balls->ty += balls->speedy + speed; // to prevent the object from ending up outside the boundary
            balls->speedx *= -speed; // to make the ball stop 


            if (abs(balls->speedx)<= 0.00000001 && abs(balls -> speedy) <= 0.00000001) {
                unsigned int timer = SDL_GetTicks(); // Make a timer to remove the ball 

                if (balls->ttl == 5) {
                    balls->ttl = timer + 5000; // counts up to 5 seconds 
                }

                else if (balls->ttl <= timer) { // After 5 seconds 
                list_remove(newlist, balls); // remove the list created for each ball
                destroy_object(balls); // destroy the object 
                number_balls ++; // Change the number of objects (if not, there will not be added any new balls)
                continue; 
                }
            } 
        }
            unsigned int time_stop = SDL_GetTicks(); // the time it tok to run the program 

            unsigned int time = time_stop - time_start; // delta time 
            if (time <= actual_time)
            {
                unsigned int ms = actual_time - time; // calculate the time difference between the time it takes and the time we want it to take 
                SDL_Delay(ms); // delay 
            }

            draw_object(balls); // draw the object 
    
        }
        
        list_resetiterator(iter);

         /* Update the window surface */
         // from task 3, the last mandatory task
        SDL_UpdateWindowSurface(window);
        while (SDL_PollEvent(&event)) { 
            switch(event.type) { 
                case SDL_QUIT:
                    done = 1;
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_SHOWN)
                        SDL_SetWindowPosition(window, 50, 50);
                    break;
            }          
        }
        }

    }


int main(void)
{
    const size_t bufsize = 100;
    
    /* Change the screen width and height to your own liking */
    const int screen_w = 1024;
    const int screen_h = 700;

    char errmsg[bufsize];
    SDL_Window *window;

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < -1) {
        snprintf(errmsg, bufsize, "Unable to initialize SDL.");
        goto error;
    }
    
    /* Create a 1600x900 window */
    window = SDL_CreateWindow("The Amazing Bouncing Balls",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            screen_w, screen_h,
                            0);
    if(!window) {
        snprintf(errmsg, bufsize, "Unable to get video surface.");
        goto error;
    }

    /* Start bouncing some balls */
    bouncing_balls(window);

    /* Shut down SDL */
    SDL_Quit();

    /* Wait a little bit jic something went wrong (so that printfs can be read) */
    SDL_Delay(5000);
    
    return 0;

    /* Upon an error, print message and quit properly */
error:
    fprintf(stderr, "%s Error returned: %s\n", errmsg, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
