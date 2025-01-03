import matplotlib.pyplot as plt

def DDA(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    steps = abs(dx) if abs(dx) > abs(dy) else abs(dy)
    x_inc = dx / steps
    y_inc = dy / steps

    x = x1
    y = y1
    x_points = [x]
    y_points = [y]

    for i in range(int(steps)):
        x += x_inc
        y += y_inc
        x_points.append(round(x))
        y_points.append(round(y))

    return x_points, y_points

if __name__ == "__main__":
    x1, y1 = map(int, input("Enter starting point (x1, y1): ").split())
    x2, y2 = map(int, input("Enter ending point (x2, y2): ").split())

    x_points, y_points = DDA(x1, y1, x2, y2)

    plt.plot(x_points, y_points, marker="o")
    plt.title("Line using DDA Algorithm")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid()
    plt.show()
