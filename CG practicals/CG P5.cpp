#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
	
	int gdriver = DETECT,gmode,s;
	initgraph(&gdriver,&gmode,(char*)"");
	
	// display the menu of options to the user
	cout<<"1.Translation\n2.Rotation\n3.Scaling";
	cout<<"\n\nEnter the choice: ";
	cin>>s;
	
	switch(s){
		case 1: // translation
			{
				// define the coords of original rectangle
				int x1 = 200, y1 = 150, x2 = 300, y2 = 250;
				
				// get the translation value from the user
				int tx = 50, ty = 50;
				
				// draw the rectangle
				cout<<"Rectangle before translation"<<endl;
				setcolor(3); // blue
				rectangle(x1,y1,x2,y2); 
				
				// draw the translated rectangle
				setcolor(4); // green
				cout<<"Rectangle after translation"<<endl;
				rectangle(x1+tx, y1+ty, x2+tx, y2+ty);
				getch();
				break;
			}
			case 2: // rotation
			  {
				// coords of original reactangle
				int x1=200, y1=200, x2=300, y2=300;
				
				// get the angle of rotation from the user
				double a;
					cout<<"Rectangle with rotation"<<endl;
					cout<<"Enter the angle of rotation: ";
					cin>>a;
					
				// convert the angle to radians
				a = (a*3.14)/180;
				
				// calculate the new x and y coords of the rotated rectangle
				long xr = x1 + ((x2 - x1) * cos(a) - (y2 - y1) * sin(a));
				long yr = y1 + ((x2 - x1) * sin(a) + (y2 - y1) * cos(a));
				
				// draw original rectangle
				setcolor(3); // blue
				rectangle(x1,y1,x2,y2);
				
				// draw the rotated rectangle
				setcolor(2); // green
				rectangle(x1,y1,xr,yr);
				
				getch();
				break;
			  }
			case 3: // scaling
			   {
				// coords of original reactangle
				int x1=20, y1=20, x2=30, y2=30;
				
				// get the scaling value from the user
				int y = 2, x = 2;
				
				// draw the original rectangle
				cout<<"Before scaling: "<<endl;
				setcolor(3);
				rectangle(x1,y1,x2,y2);
				
				// draw the scaled rectangle
				cout<<"After scaling"<<endl;
				setcolor(4);
				rectangle(x1 * x, y1 * y, x2 * x, y2 * y);
				
				getch();
				break;
			    }
			default:
				{
					cout<<"Invalid selection"<<endl;
					break;
				}
	}
	closegraph();
	return 0;
}
