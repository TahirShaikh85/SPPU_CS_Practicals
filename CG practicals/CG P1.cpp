// ***** Write C++ program to draw a concave polygon and fill it with desired color using fill
#include<graphics.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Function definition for the flood fill algorithm
// Takes four arguments: the x and y coordinates of a point within the triangle, the original color of the pixel at that point, and the new color to fill the triangle with
void ffill(int x,int y,int o_col,int n_col)
{
    // Get the color value of the pixel at the specified coordinates
    int current = getpixel(x,y);

    // If the color of the pixel is the same as the original color specified in the function arguments
    if(current==o_col)
    {
        // Add a delay of 1 millisecond
        delay(1);

        // Set the color of the pixel at the specified coordinates to the new color specified in the function arguments
        putpixel(x,y,n_col);

        // Recursively call the flood fill function to fill the pixels to the right, left, above, and below the current pixel with the new color
        ffill(x+1,y,o_col,n_col);
        ffill(x-1,y,o_col,n_col);
        ffill(x,y+1,o_col,n_col);
        ffill(x,y-1,o_col,n_col);
    }
}

// Main function where the program begins executing
int main()
{
    // Declare variables for the x and y coordinates of the three points of the triangle and the average x and y coordinates
    int x1,y1,x2,y2,x3,y3,xavg,yavg;

    // Initialize the graphics driver and mode
    int gdriver = DETECT,gmode;

    // Initialize the graphics system
    initgraph(&gdriver,&gmode,NULL);

    // Prompt the user to enter the points of the triangle
    cout << "\nEnter the points of triangle: ";

    // Set the color of the lines to be drawn to color 1 (in this case, a predefined constant for a specific color)
    setcolor(1);

    // Input the x and y coordinates of the three points of the triangle from the user
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate the average x and y coordinates of the triangle
    xavg = (int)(x1+x2+x3)/3;
    yavg = (int)(y1+y2+y3)/3;

    // Draw lines between the three points of the triangle
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    // Call the flood fill function to fill the triangle with the specified color, starting at the average x and y coordinates
    ffill(xavg,yavg,BLACK,RED);

    // Wait for the user to press a key before exiting
    getch();

    // Return 0 to indicate that the program has completed successfully
    return 0;
}

