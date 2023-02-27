#include <graphics.h>

void drawCircle(int x, int y, int r, int color) {
   int x0 = 0, y0 = r;
   int d = 5 - 4 * r;

   // Draw the circle using 8-way symmetry
   while (x0 <= y0) {
      putpixel(x + x0, y + y0, color);
      putpixel(x - x0, y + y0, color);
      putpixel(x + x0, y - y0, color);
      putpixel(x - x0, y - y0, color);
      putpixel(x + y0, y + x0, color);
      putpixel(x - y0, y + x0, color);
      putpixel(x + y0, y - x0, color);
      putpixel(x - y0, y - x0, color);

      if (d < 0) {
         d += 2 * x0 + 3;
      } else {
         d += 2 * (x0 - y0) + 5;
         y0--;
      }
      x0++;
   }
}

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int x = 200, y = 200, r = 100; // Center coordinates and radius
   drawCircle(x, y, r, WHITE);

   delay(5000); // Delay to see the output
   closegraph();
   return 0;
}
