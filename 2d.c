#include <graphics.h>
#include <math.h>

// Function to perform translation
void translate(int x[], int y[], int n, int tx, int ty) {
   for (int i = 0; i < n; i++) {
      x[i] += tx;
      y[i] += ty;
   }
}

// Function to perform rotation
void rotate(int x[], int y[], int n, float theta) {
   float rad = theta * 3.14159 / 180.0;
   int tempX, tempY;
   for (int i = 0; i < n; i++) {
      tempX = x[i];
      tempY = y[i];
      x[i] = round(tempX * cos(rad) - tempY * sin(rad));
      y[i] = round(tempX * sin(rad) + tempY * cos(rad));
   }
}

// Function to perform scaling
void scale(int x[], int y[], int n, float sx, float sy) {
   for (int i = 0; i < n; i++) {
      x[i] = round(x[i] * sx);
      y[i] = round(y[i] * sy);
   }
}

// Function to perform reflection
void reflect(int x[], int y[], int n, int ch) {
   if (ch == 1) { // Reflection about x-axis
      for (int i = 0; i < n; i++) {
         y[i] = -y[i];
      }
   } else if (ch == 2) { // Reflection about y-axis
      for (int i = 0; i < n; i++) {
         x[i] = -x[i];
      }
   } else if (ch == 3) { // Reflection about origin
      for (int i = 0; i < n; i++) {
         x[i] = -x[i];
         y[i] = -y[i];
      }
   } else if (ch == 4) { // Reflection about line y=x
      int temp;
      for (int i = 0; i < n; i++) {
         temp = x[i];
         x[i] = y[i];
         y[i] = temp;
      }
   } else if (ch == 5) { // Reflection about line y=-x
      int temp;
      for (int i = 0; i < n; i++) {
         temp = x[i];
         x[i] = -y[i];
         y[i] = -temp;
      }
   }
}

// Function to perform shear
void shear(int x[], int y[], int n, float sx, float sy) {
   for (int i = 0; i < n; i++) {
      x[i] = round(x[i] + sx * y[i]);
      y[i] = round(y[i] + sy * x[i]);
   }
}

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   // Define the initial shape coordinates
   int x[] = {50, 100, 100, 50};
   int y[] = {50, 50, 100, 100};
   int n = sizeof(x) / sizeof(x[0]);

   // Draw the initial shape
   setcolor(WHITE);
   drawpoly(n, x, y);

   // Translation
   translate(x, y, n, 50, 100);
   setcolor(RED);
   drawpoly(n, x, y);

// Rotation
rotate(x, y, n, 45);
setcolor(YELLOW);
drawpoly(n, x, y);

// Scaling
scale(x, y, n, 1.5, 1);
setcolor(GREEN);
drawpoly(n, x, y);

// Reflection
reflect(x, y, n, 1); // Reflection about x-axis
setcolor(CYAN);
drawpoly(n, x, y);

// Shear
shear(x, y, n, 1, 0);
setcolor(MAGENTA);
drawpoly(n, x, y);

getch();
closegraph();
return 0;
}
