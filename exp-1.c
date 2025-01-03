#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm; // Graphics driver and mode
    float m, c, x_start, x_end, step_size, x, y;
    int screen_x, screen_y;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Get user input for slope and intercept
    printf("Enter the slope (m): ");
    scanf("%f", &m);

    printf("Enter the y-intercept (c): ");
    scanf("%f", &c);

    printf("Enter the starting value of x: ");
    scanf("%f", &x_start);

    printf("Enter the ending value of x: ");
    scanf("%f", &x_end);

    printf("Enter the step size for x: ");
    scanf("%f", &step_size);

    // Draw axes
    int mid_x = getmaxx() / 2;
    int mid_y = getmaxy() / 2;
    line(mid_x, 0, mid_x, getmaxy()); // Y-axis
    line(0, mid_y, getmaxx(), mid_y); // X-axis

    // Plot the line
    setcolor(WHITE);
    for (x = x_start; x <= x_end; x += step_size) {
        y = m * x + c;

        // Convert graph coordinates to screen coordinates
        screen_x = mid_x + (int)x * 10; // Scaling factor: 10 pixels/unit
        screen_y = mid_y - (int)y * 10; // Invert y-axis for graphics

        putpixel(screen_x, screen_y, WHITE);
    }

    // Hold the screen
    printf("Press any key to exit...");
    getch();

    closegraph(); // Close graphics mode
    return 0;
}
