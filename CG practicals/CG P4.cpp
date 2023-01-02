#include<iostream>
#include<graphics.h> // include the graphics library
#include<math.h>
#include<cstdlib>
using namespace std;

// function to move the "pen" to the next point on the curve
void move(int j, int h, int &x,int &y)
{
    // update the x and y coordinates based on the direction specified by j
    if(j==1) y-=h;
    else if(j==2) x+=h;
    else if(j==3) y+=h;
    else if(j==4) x-=h;
    // draw a line from the current point to the next point
    lineto(x,y);
}

// recursive function to generate the points of the curve
void hilbert(int r,int d,int l ,int u,int i,int h,int &x,int &y)
{
    // base case: if i is 0, return
    if(i>0)
    {
        // decrement i and make recursive calls
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y);
    }
}

int main()
{
    int n,x1,y1;
    // initial x and y coordinates of the curve
    int x0=50,y0=150,x,y,h=10,r=2,d=3,l=4,u=1;
    cout<<"Give the value of n=";
    cin>>n;
    // set the current x and y coordinates to the initial values
    x=x0;
    y=y0;
    // initialize the graphics window
    int driver=DETECT,mode=0;
    initgraph(&driver,&mode,NULL);
    // move the "pen" to the starting point
    moveto(x,y);
    // generate the points of the curve
    hilbert(r,d,l,u,n,h,x,y);
    // wait for 10 seconds before closing the window
    delay(10000);
    closegraph();
    return 0;
}

