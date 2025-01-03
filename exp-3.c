#include <graphics.h>
#include <stdio.h>
#include <math.h>

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);

    int x, y, xEnd;
    if (x1 > x2) {
        x = x2;
        y = y2;
        xEnd = x1;
    } else {
        x = x1;
        y = y1;
        xEnd = x2;
    }

    putpixel(x, y, WHITE);

    while (x < xEnd) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyDx;
        }
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1, y1, x2, y2;
    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
