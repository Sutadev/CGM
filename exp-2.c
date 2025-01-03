#include <graphics.h>
#include <stdio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    float x_inc = dx / steps;
    float y_inc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Draw pixel
        x += x_inc;
        y += y_inc;
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

    DDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
