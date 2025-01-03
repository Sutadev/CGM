import matplotlib.pyplot as plt

def bresenham(x1, y1, x2, y2):
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    p = 2 * dy - dx
    x, y = x1, y1

    x_points = [x]
    y_points = [y]

    while x <= x2:
        x += 1
        if p < 0:
            p += 2 * dy
        else:
            y += 1
            p += 2 * (dy - dx)
        x_points.append(x)
        y_points.append(y)

    return x_points, y_points

if __name__ == "__main__":
    x1, y1 = map(int, input("Enter starting point (x1, y1): ").split())
    x2, y2 = map(int, input("Enter ending point (x2, y2): ").split())

    x_points, y_points = bresenham(x1, y1, x2, y2)

    plt.plot(x_points, y_points, marker="o")
    plt.title("Line using Bresenham's Algorithm")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid()
    plt.show()
