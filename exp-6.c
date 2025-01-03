#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

// Function to rotate a point by a given angle around the origin (0, 0)
void rotate_point(int *x, int *y, float angle) {
    float angle_rad = angle * (M_PI / 180); // Convert angle to radians
    int x_new = *x * cos(angle_rad) - *y * sin(angle_rad);
    int y_new = *x * sin(angle_rad) + *y * cos(angle_rad);
    *x = x_new;
    *y = y_new;
}

// Function to rotate a line by an angle
void rotate_line(int *x1, int *y1, int *x2, int *y2, float angle) {
    rotate_point(x1, y1, angle);
    rotate_point(x2, y2, angle);
    line(*x1, *y1, *x2, *y2); // Draw rotated line
}

// Function to rotate a triangle by an angle
void rotate_triangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float angle) {
    rotate_point(x1, y1, angle);
    rotate_point(x2, y2, angle);
    rotate_point(x3, y3, angle);
    // Draw rotated triangle
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
    
    // Rotation angle
    float angle = 45; // Rotate by 45 degrees

    // Draw original line
    line(x1, y1, x2, y2);

    // Draw original triangle
    line(x1_t, y1_t, x2_t, y2_t);
    line(x2_t, y2_t, x3_t, y3_t);
    line(x3_t, y3_t, x1_t, y1_t);

    delay(2000); // Wait for 2 seconds before rotating

    // Rotate and draw the rotated line
    rotate_line(&x1, &y1, &x2, &y2, angle);

    // Rotate and draw the rotated triangle
    rotate_triangle(&x1_t, &y1_t, &x2_t, &y2_t, &x3_t, &y3_t, angle);

    getch(); // Wait for key press to exit
    closegraph(); // Close the graphics window
    return 0;
}
