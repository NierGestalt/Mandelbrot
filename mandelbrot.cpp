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

	for (int x = 0; x < WINDOW_WIDTH; x ++)
	{
	       for(int y = 0; y < WINDOW_HEIGHT; y++)
	       {
		       int n = 0;
		       int z = 0;
		       double a = 0;
		       double b = 0;
		       a = ((x - 400) * .005);
	               b = ((y - 400) * .005);
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
			gfx_point(x,y);
	       }
        }
	int button = gfx_wait();
	return 0;
}


