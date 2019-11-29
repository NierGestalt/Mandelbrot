#include <iostream>
#include <math.h>
extern "C"
{
#include "gfx.h"



}

#define PI 3.142635

int main()
{
	gfx_open( 800, 800, "mandelbrot");
	for (int x=0; x<800;x++)
	{
		for(int y=0; y<800; y++)
		{
			int n = 0;
			int z = 0;
			double a = 0;
			double b = 0;
			a = ((x-400) * 0.005);
			b = ((y-400) * 0.005);

			//      gfx_point(x,y);
			double ca = a;
			double cb = b;

			while (n < 100)
			{
				double aa = (a*a) - (b*b);
				double bb = 2*a*b;
				a = aa + ca;
				b = bb + cb;
				if (abs(a+b) > 16)
				{
					break;
				}
				n++;
			}
			double red = n*n*n % 255;		          
			double green = n*1/2 % 256;    // change color3/2) % 256;    
			double blue = n+25 *(7/36) % 255;	  
			gfx_color(red, green, blue);	 
			gfx_point(x,y);
		}
	}       
	int button = gfx_wait();
	return 0;
}
