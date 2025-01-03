#include <graphics.h>
#include <stdio.h>
#include <math.h>

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midpointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    drawCircle(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCircle(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int xc, yc, r;
    printf("Enter center of circle (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius of circle: ");
    scanf("%d", &r);

    midpointCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
