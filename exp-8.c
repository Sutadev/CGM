#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Function to draw and fill a circle with a specified color
void draw_filled_circle(int x, int y, int radius, int color) {
    setcolor(color);  // Set the border color
    setfillstyle(SOLID_FILL, color);  // Set the fill color
    floodfill(x, y, color);  // Fill the circle from the center
    circle(x, y, radius);  // Draw the circle
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    // Set the circle's center and radius
    int x = 300, y = 200, radius = 100;
    
    // Draw and fill the circle with red color
    draw_filled_circle(x, y, radius, RED);

    getch(); // Wait for key press to exit
    closegraph(); // Close the graphics window
    return 0;
}
