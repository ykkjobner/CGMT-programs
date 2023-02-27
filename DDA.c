#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Starting coordinates
    int x2 = 300, y2 = 300; // Ending coordinates
    int dx = x2 - x1, dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;
    float x = x1, y = y1;

    // Draw the line
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }

    delay(5000); // Delay to see the output
    closegraph();
    return 0;
}
