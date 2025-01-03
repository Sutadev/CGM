import turtle

# Function to scale a point by given sx and sy
def scale_point(x, y, sx, sy):
    x_new = x * sx
    y_new = y * sy
    return x_new, y_new

# Function to scale a line by sx and sy
def scale_line(x1, y1, x2, y2, sx, sy):
    x1_new, y1_new = scale_point(x1, y1, sx, sy)
    x2_new, y2_new = scale_point(x2, y2, sx, sy)
    return x1_new, y1_new, x2_new, y2_new

# Function to scale a triangle by sx and sy
def scale_triangle(x1, y1, x2, y2, x3, y3, sx, sy):
    x1_new, y1_new = scale_point(x1, y1, sx, sy)
    x2_new, y2_new = scale_point(x2, y2, sx, sy)
    x3_new, y3_new = scale_point(x3, y3, sx, sy)
    return x1_new, y1_new, x2_new, y2_new, x3_new, y3_new

# Initialize screen and turtle
screen = turtle.Screen()
t = turtle.Turtle()

# Set up for drawing the original line and triangle
t.penup()

# Original line (x1, y1) to (x2, y2)
x1, y1, x2, y2 = -200, -100, 100, 100
# Original triangle (x1, y1), (x2, y2), (x3, y3)
x1_t, y1_t, x2_t, y2_t, x3_t, y3_t = -150, -150, 50, -150, 0, 50

# Scaling factors (sx, sy)
sx, sy = 1.5, 1.5  # Scale by 1.5x in both x and y directions

# Draw original line
t.goto(x1, y1)
t.pendown()
t.goto(x2, y2)
t.penup()

# Draw original triangle
t.goto(x1_t, y1_t)
t.pendown()
t.goto(x2_t, y2_t)
t.goto(x3_t, y3_t)
t.goto(x1_t, y1_t)
t.penup()

# Scale and draw the scaled line
scaled_line = scale_line(x1, y1, x2, y2, sx, sy)
t.goto(scaled_line[0], scaled_line[1])
t.pendown()
t.goto(scaled_line[2], scaled_line[3])
t.penup()

# Scale and draw the scaled triangle
scaled_triangle = scale_triangle(x1_t, y1_t, x2_t, y2_t, x3_t, y3_t, sx, sy)
t.goto(scaled_triangle[0], scaled_triangle[1])
t.pendown()
t.goto(scaled_triangle[2], scaled_triangle[3])
t.goto(scaled_triangle[4], scaled_triangle[5])
t.goto(scaled_triangle[0], scaled_triangle[1])
t.penup()

# Hide the turtle and display the result
t.hideturtle()
screen.mainloop()
