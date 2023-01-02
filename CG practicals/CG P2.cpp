// Write C++ program to implement Cohen Southerland line clipping algorithm.

#include<iostream>
#include<graphics.h> // include graphics library for drawing functions
using namespace std;

// Constants for the four regions of the viewport
static int LEFT = 1;
static int RIGHT = 2;
static int BOTTOM = 4;
static int TOP = 8;

// Variables to store the coordinates of the viewport
static int xl, yl, xh, yh;

// Function to compute the region code for a point (x, y)
int getcode(int x, int y)
{
    int code = 0;

    // Perform Bitwise OR to get the outcode
    if (y > yh) code |= TOP;
    if (y < yl) code |= BOTTOM;
    if (x < xl) code |= LEFT;
    if (x > xh) code |= RIGHT;

    return code;
}

int main()
{
    // Initialize graphics mode
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    // Set the color to blue
    setcolor(BLUE);

    // Read in the coordinates of the viewport
    cout << "Enter bottom left and top right co-ordinates of window: ";
    cin >> xl >> yl >> xh >> yh;

    // Draw the viewport as a rectangle
    rectangle(xl, yl, xh, yh);

    // Read in the endpoints of the line
    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the line
    line(x1, y1, x2, y2);

    // Wait for user input before continuing
    getch();

    // Compute the region codes for the two endpoints of the line
    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);

    // Initialize a variable to store whether or not the line is accepted
    int accept = 0;

    // Loop until both endpoints have been accepted or rejected
    while (true)
    {
        // Calculate the slope of the line
        float m = (float)(y2 - y1) / (x2 - x1);

        // Both points inside. Accept line
        if (outcode1 == 0 && outcode2 == 0)
        {
            accept = 1;
            break;
        }
       //AND of both codes != 0.Line is outside. Reject line
        else if ((outcode1 & outcode2) != 0)
        {
            break;
        }
        // If one endpoint is inside and one is outside, we need to clip the line
        else
        {
            // Choose the endpoint that is outside the viewport
            int temp;
            if (outcode1 == 0)
                temp = outcode2;
            else
                temp = outcode1;

            // Calculate the new x and y coordinates of the endpoint using the Cohen-Sutherland algorithm
            int x, y;
            if (temp & TOP) // Line clips top edge
            {
                x = x1 + (yh - y1) / m;
                y = yh;
            }
            else if (temp & BOTTOM) // Line clips bottom edge
            {
                x = x1 + (yl - y1) / m;
                y = yl;
            }
            else if (temp & LEFT) // Line clips left edge
            {
                x = xl;
                y = y1 + m * (xl - x1);
            }
            else if (temp & RIGHT) // Line clips right edge
            {
                x = xh;
                y = y1 + m * (xh - x1);
            }

            // Update the coordinates of the endpoint
            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    // Set the color to white
    setcolor(WHITE);

    // If the line is partially visible, draw it using the new coordinates of the endpoints
    cout << "After clipping:";
    if (accept)
        line(x1, y1, x2, y2);

    // Close the graphics mode
    closegraph();

    return 0;
}

