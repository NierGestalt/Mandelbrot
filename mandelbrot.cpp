#include <iostream>
#include <math.h>
extern "C"{
#include "gfx.h"
}



int main()
{
gfx_open( 800, 800, "mandelbrot");
//gfx_clear_color(51,51,51);
//gfx_clear();
//gfx_point (200,200);
//gfx_point (150,150);
//gfx_point (100,100);
for (int x=0; x<800;x++){
       for(int y=0; y<800; y++)
       {
	       int n = 0;
	       int z = 0;
	       double a = 0;
	       double b = 0;
	       a = ((x - 400) * .005);
               b = ((y - 400) * .005);

	 //      gfx_point(x,y);
	       double ca = a;
	       double cb = b;

	       while (n < 100)
	       {
		       double aa = (a*a) - (b*b);
		       double bb = 2*a*b;
		       a = aa + ca;
		       b = bb + cb;
		       if (abs(a + b) > 16)
		       {
			       break;
		       }
		       n++;
	       }
	       double color = ((n) % 255);
	       double color1 = ((n * n ) % 255);    // change color
	       double color2 = ((n / 2) % 255);
	       gfx_color(color,color1,color2);
	       if (n == 100)
	       {
		       gfx_point(x,y);
	       }
       }
}       
int button = gfx_wait();
return 0;
}


