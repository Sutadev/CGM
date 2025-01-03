#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Function to scale a point by given sx and sy
void scale_point(int *x, int *y, float sx, float sy) {
    *x = *x * sx;
    *y = *y * sy;
}

// Function to scale a line by sx and sy
void scale_line(int *x1, int *y1, int *x2, int *y2, float sx, float sy) {
    scale_point(x1, y1, sx, sy);
    scale_point(x2, y2, sx, sy);
    line(*x1, *y1, *x2, *y2); // Draw scaled line
}

// Function to scale a triangle by sx and sy
void scale_triangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float sx, float sy) {
    scale_point(x1, y1, sx, sy);
    scale_point(x2, y2, sx, sy);
    scale_point(x3, y3, sx, sy);
    // Draw scaled triangle
    line(*x1, *y1, *x2, *y2);
    line(*x2, *y2, *x3, *y3);
    line(*x3, *y3, *x1, *y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    // Original line (x1, y1) to (x2, y2)
    int x1 = 100, y1 = 100, x2 = 300, y2 = 100;
    
    // Original triangle (x1, y1), (x2, y2), (x3, y3)
    int x1_t = 150, y1_t = 150, x2_t = 350, y2_t = 150, x3_t = 250, y3_t = 50;
    
    // Scaling factors (sx, sy)
    float sx = 1.5, sy = 1.5; // Scale by 1.5x in both x and y directions

    // Draw original line
    line(x1, y1, x2, y2);

    // Draw original triangle
    line(x1_t, y1_t, x2_t, y2_t);
    line(x2_t, y2_t, x3_t, y3_t);
    line(x3_t, y3_t, x1_t, y1_t);

    delay(2000); // Wait for 2 seconds before scaling

    // Scale and draw the scaled line
    scale_line(&x1, &y1, &x2, &y2, sx, sy);

    // Scale and draw the scaled triangle
    scale_triangle(&x1_t, &y1_t, &x2_t, &y2_t, &x3_t, &y3_t, sx, sy);

    getch(); // Wait for key press to exit
    closegraph(); // Close the graphics window
    return 0;
}
