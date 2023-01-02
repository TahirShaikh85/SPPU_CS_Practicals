#include <iostream> // for input/output operations
#include <cstdlib> // for the exit() function
#include <graphics.h> // for graphics functions
using namespace std;

int main()
{
    int gd = DETECT, gm; // variables to store graphics driver and graphics mode
    int i, x, y, flag=0; // variables for loop iteration, x and y coordinates, and flag

    // initialize the graphics system
    initgraph(&gd, &gm, NULL);

    // get midpoint coordinates of the screen
    x = getmaxx() / 2;
    y = 30;

    // enter an infinite loop
    while (1)
    {
        // check if the y-coordinate of the circle has reached the top or bottom of the screen
        if (y >= getmaxy() - 30 || y <= 30)
        {
            // flip the value of the flag
            flag = !flag;
        }

        // set the color of the circle to red
        setcolor(RED);

        // draw a circle with the specified center point and radius
        circle(x, y, 30);

        // fill the interior of the circle with the current fill color
        floodfill(x, y, RED);

        // delay for 50 milliseconds
        delay(50);

        // clear the screen
        cleardevice();

        // update the y-coordinate of the circle based on the value of the flag
        if (flag)
        {
            y = y + 5;
        }
        else
        {
            y = y - 5;
        }
    }

    // delay for 5 seconds
    delay(5000);

    // close the graphics system
    closegraph();

    // return 0 to indicate successful completion of the program
    return 0;
}

