/*
 * 	Mandelbrot Set c++
 *	for ECE 231
 * 	First writen on November 22, 2019
 */

#include <iostream>
#include <math.h>
#include "Timer.h"
extern "C"{
#include "gfx.h"
}

/*
   ==============
   Toggle complex
   ==============
*/

#define COMPLEX 0
#if COMPLEX
#include <complex>
typedef std::complex<double> Complex;
#endif

/*
   ==========================================
   MACRO definition for Window and iterations 
   ==========================================
*/

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800
#define MAX_ITERATIONS 100

/*
   ==========================================
   completed function prototypes are all here
   ==========================================
*/

double getRange(int coordinates);
void drawMandelbrot(int n, int xPos, int yPos);
int getMandelbrot(int xPos, int yPos);


/*
   =============
   main function
   =============
*/

int main()
{
	gfx_open( WINDOW_WIDTH, WINDOW_HEIGHT, "Mandelbrot");
	Timer t("Time to create Mandelbrot");
	for (int xPos = 0; xPos < WINDOW_WIDTH; xPos ++)
	{
	       for(int yPos = 0; yPos < WINDOW_HEIGHT; yPos ++)
	       {
			int n = getMandelbrot(xPos,yPos);
			drawMandelbrot(n,xPos,yPos);
	       }
        }
	int button = gfx_wait();
	return 0;
}

// Change Color of The Mandelbrot Set by manipulating (n)
void drawMandelbrot(int n, int xPos, int yPos)
{
	double red = n*n*n % 255;          
       	double green = (n * 3/2) % 256;    
  	double blue = n / 2 % 255;
	gfx_color(red, green, blue);
	gfx_point(xPos,yPos);
}	

// Calculate range of Window
double getRange(int coordinates)
{
       return ((coordinates - 400) * .005);
	
}

#if !COMPLEX

// Not using Complex Class
int getMandelbrot(int xPos, int yPos)
{
       int n = 0;
       double a = 0;
       double b = 0;
       a = getRange(xPos);
       b = getRange(yPos);
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
       return n;

}

#else
// Using Complex Class
int getMandelbrot(int xPos, int yPos)
{
	int n = 0;
	Complex z((xPos - 400) * .005, (yPos - 400) * .005);
	Complex c = z;
	while( n < MAX_ITERATIONS )
	{
		z =  z*z + c;
		if(abs(z.real() + z.imag()) > 16)
			break;
		n ++;
	}
	return n;
}
#endif

