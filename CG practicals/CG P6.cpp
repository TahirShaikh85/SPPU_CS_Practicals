#include<graphics.h>
int main(){
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,NULL);
	
	// set the center point and radius of the arc
	int midx,midy, r = 10;
	midx=getmaxx()/2;
	
	// enter a loop that continues until the radious is greater than 50
	while(r<=50){
		// clear the screen and set the drawing color to white
		cleardevice();
		setcolor(WHITE);
		
		// draw the lines for the scene
		line(0,310,160,150);
		line(160,150,320,310);
		line(320,310,480,150);
		line(480,150,640,310);
		line(0,310,640,310);
		
		// draw the arc and fill it in
		arc(midx,310,225,133,r);
		floodfill(midx,300,15);
		
		// if the radious is greater than 20 fill in different parts of the scene
		if(r>20){
			setcolor(7);
			floodfill(2,2,15);
			setcolor(6);
			floodfill(150,250,15);
			floodfill(550,25,15);
			setcolor(2);
			floodfill(2,450,15);
		}
		
		// delay for 1 sec
		delay(1000);
		r+=2;
	}
	
	
	getch();
	closegraph();
	return 0;
}
