#include <iostream>
#include <math.h>
extern "C"{
#include "gfx.h"
}

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800
#define MAX_ITERATIONS 100

int main()
{
	gfx_open( WINDOW_WIDTH, WINDOW_HEIGHT, "Mandelbrot");

	for (int xPos = 0; xPos < WINDOW_WIDTH; xPos ++)
	{
	       for(int yPos = 0; yPos < WINDOW_HEIGHT; yPos ++)
	       {
		       int n = 0;
		       int z = 0;
		       double a = 0;
		       double b = 0;
		       a = ((xPos - 400) * .005);
	               b = ((yPos - 400) * .005);
		       double ca = a;
		       double cb = b;
	
		       while (n < MAX_ITERATIONS)
		       {
			        double aa = (a*a) - (b*b);
			        double bb = 2*a*b;
			        a = aa + ca;
			        b = bb + cb;
				if (abs(a+b) > 16.0)
				{
				       break;
		       		}
				n++;
		       }

	        	double red = n*n*n % 255;
	        	double green = (n * 3/2) % 256;    // change color
	        	double blue = n / 2 % 255;
			gfx_color(red, green, blue);
			gfx_point(xPos,yPos);
	       }
        }
	int button = gfx_wait();
	return 0;
}


