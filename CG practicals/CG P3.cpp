#include<iostream>
#include<graphics.h> // include the graphics library
#include <bits/stdc++.h> // include the bits/stdc++ library
using namespace std;

// class to contain the drawing algorithms
class algo
{
public:
    // function to draw a line segment using the DDA algorithm
    void dda_line(float x1, float y1, float x2, float y2);
    // function to draw a circle using the Bresenham algorithm
    void bresneham_cir(int r);
};

// function to draw a line segment using the DDA algorithm
void algo::dda_line(float x1, float y1, float x2, float y2)
{
    float x,y,dx,dy,step;
    int i;
    // calculate the differences in x and y
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    // determine the number of steps to take
    if(dx>=dy)
        step=dx;
    else
        step=dy;
    // calculate the increment in x and y for each step
    float xinc=float((x2-x1)/step);
    float yinc=float((y2-y1)/step);
    // set the initial x and y coordinates
    x=x1;
    y=y1;
    // draw the line segment one pixel at a time
    i=1;
    while(i<=step)
    {
        putpixel(320+x,240-y,4); // draw a pixel at (x, y)
        x=x+xinc; // update the x coordinate
        y=y+yinc; // update the y coordinate
        i=i+1; // increment the counter
    }
}

// function to draw a circle using the Bresenham algorithm
void algo::bresneham_cir(int r)
{
    float x,y,p;
    x=0;
    y=r;
    p=3-(2*r);
    // draw the circle one pixel at a time
    while(x<=y)
    {
        putpixel(320+x,240+y,1); // draw a pixel at (x, y)
        putpixel(320-x,240+y,2); // draw a pixel at (-x, y)
        putpixel(320+x,240-y,3); // draw a pixel at (x, -y)
        putpixel(320-x,240-y,5); // draw a pixel at (-x, -y)
        putpixel(320+y,240+x,6); // draw a pixel at (y, x)
        putpixel(320+y,240-x,7); // draw a pixel at (y, -x)
        putpixel(320-y,240+x,8); // draw a pixel at (-y, x)
        putpixel(320-y,240-x,9); // draw a pixel at (-y, -x)
        
        x=x+1; // update the x coordinate
        if(p<0) // choose an E or NE pixel
        {
			// choose an E pixel
			p=p+4*(x)+6;
        }
        else // choose a NE pixel
        {
            p=p+4*(x-y)+10;
            y=y-1; // update the y coordinate
        }
    }
}

int main()
{
    algo a1; // create an object of the algo class
    int i;
    float r,ang,r1;
    initwindow(630,480); // initialize the graphics window
    cout<<"Enter radius of circle";
    cin>>r; // prompt the user to enter the radius of the circle
    a1.bresneham_cir((int)r); // draw the circle using the Bresenham algorithm
    ang=3.24/180; // convert 30 degrees to radians
    float c=r*cos(30*ang); // calculate the x coordinate of one vertex of the triangle
    float s=r*sin(30*ang); // calculate the y coordinate of one vertex of the triangle
    a1.dda_line(0,r,0-c,0-s); // draw a line segment using the DDA algorithm
    a1.dda_line(0-c,0-s,0+c,0-s); // draw another line segment using the DDA algorithm
    a1.dda_line(0+c,0-s,0,r); // draw the third line segment using the DDA algorithm
    r1=s; // set the radius of the inner circle to the y coordinate of one vertex of the triangle
    a1.bresneham_cir((int)r1); // draw the inner circle using the Bresenham algorithm
    getch(); // wait for a key press
    closegraph(); // close the graphics window
    return 0;
}

