#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Function to translate a point by a vector
void translate_point(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

// Function to translate a line by a translation vector
void translate_line(int x1, int y1, int x2, int y2, int tx, int ty) {
    translate_point(&x1, &y1, tx, ty);
    translate_point(&x2, &y2, tx, ty);
    line(x1, y1, x2, y2); // Draw translated line
}

// Function to translate a triangle by a translation vector
void translate_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty) {
    translate_point(&x1, &y1, tx, ty);
    translate_point(&x2, &y2, tx, ty);
    translate_point(&x3, &y3, tx, ty);
    // Draw translated triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    // Original line (x1, y1) to (x2, y2)
    int x1 = 100, y1 = 100, x2 = 300, y2 = 100;
    
    // Original triangle (x1, y1), (x2, y2), (x3, y3)
    int x1_t = 150, y1_t = 150, x2_t = 350, y2_t = 150, x3_t = 250, y3_t = 50;
    
    // Translation vector (tx, ty)
    int tx = 100, ty = 50;

    // Draw original line
    line(x1, y1, x2, y2);

    // Draw original triangle
    line(x1_t, y1_t, x2_t, y2_t);
    line(x2_t, y2_t, x3_t, y3_t);
    line(x3_t, y3_t, x1_t, y1_t);

    delay(2000); // Wait for 2 seconds before translating

    // Translate line
    translate_line(x1, y1, x2, y2, tx, ty);

    // Translate triangle
    translate_triangle(x1_t, y1_t, x2_t, y2_t, x3_t, y3_t, tx, ty);

    getch(); // Wait for key press to exit
    closegraph(); // Close the graphics window
    return 0;
}
