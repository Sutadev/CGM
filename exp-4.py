import matplotlib.pyplot as plt

def draw_circle_points(xc, yc, x, y, x_points, y_points):
    x_points.extend([xc + x, xc - x, xc + x, xc - x, xc + y, xc - y, xc + y, xc - y])
    y_points.extend([yc + y, yc + y, yc - y, yc - y, yc + x, yc + x, yc - x, yc - x])

def midpoint_circle(xc, yc, r):
    x_points = []
    y_points = []

    x = 0
    y = r
    p = 1 - r

    draw_circle_points(xc, yc, x, y, x_points, y_points)

    while x < y:
        x += 1
        if p < 0:
            p += 2 * x + 1
        else:
            y -= 1
            p += 2 * (x - y) + 1
        draw_circle_points(xc, yc, x, y, x_points, y_points)

    return x_points, y_points

if __name__ == "__main__":
    xc, yc = map(int, input("Enter center of circle (xc, yc): ").split())
    r = int(input("Enter radius of circle: "))

    x_points, y_points = midpoint_circle(xc, yc, r)

    plt.scatter(x_points, y_points, s=10, color="blue")
    plt.title("Circle using Midpoint Algorithm")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid()
    plt.gca().set_aspect("equal", adjustable="box")
    plt.show()
