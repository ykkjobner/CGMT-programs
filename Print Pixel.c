#include <graphics.h>

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int x = 100; // X coordinate
   int y = 200; // Y coordinate

   // Plot the point
   putpixel(x, y, WHITE);

   delay(5000); // Delay to see the output
   closegraph();
   return 0;
}
