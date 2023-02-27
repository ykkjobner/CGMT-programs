#include <graphics.h>

void drawEllipse(int x, int y, int a, int b, int color) {
   int x0 = 0, y0 = b;
   int d = b*b - a*a*b + a*a/4;

   // Draw the ellipse using 4-way symmetry
   while (b*b*(x0+1) < a*a*(y0-0.5)) {
      putpixel(x + x0, y + y0, color);
      putpixel(x - x0, y + y0, color);
      putpixel(x + x0, y - y0, color);
      putpixel(x - x0, y - y0, color);

      if (d < 0) {
         d += 2 * b*b * x0 + b*b;
      } else {
         d += 2 * b*b * x0 + b*b + 2 * a*a * (1 - y0);
         y0--;
      }
      x0++;
   }

   d = b*b*(x0+0.5)*(x0+0.5) + a*a*(y0-1)*(y0-1) - a*a*b*b;
   while (y0 >= 0) {
      putpixel(x + x0, y + y0, color);
      putpixel(x - x0, y + y0, color);
      putpixel(x + x0, y - y0, color);
      putpixel(x - x0, y - y0, color);

      if (d < 0) {
         d += 2 * b*b * x0 + 2 * a*a * (1 - y0) + a*a;
         x0++;
      } else {
         d += 2 * a*a * (1 - y0) + a*a;
      }
      y0--;
   }
}

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int x = 200, y = 200, a = 100, b = 50; // Center coordinates, major axis, and minor axis
   drawEllipse(x, y, a, b, WHITE);

   delay(5000); // Delay to see the output
   closegraph();
   return 0;
}
