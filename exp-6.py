import turtle
import math

# Function to rotate a point by a given angle around the origin (0, 0)
def rotate_point(x, y, angle):
    # Convert angle to radians
    angle_rad = math.radians(angle)
    x_new = x * math.cos(angle_rad) - y * math.sin(angle_rad)
    y_new = x * math.sin(angle_rad) + y * math.cos(angle_rad)
    return x_new, y_new

# Function to rotate a line by an angle
def rotate_line(x1, y1, x2, y2, angle):
    x1_new, y1_new = rotate_point(x1, y1, angle)
    x2_new, y2_new = rotate_point(x2, y2, angle)
    return x1_new, y1_new, x2_new, y2_new

# Function to rotate a triangle by an angle
def rotate_triangle(x1, y1, x2, y2, x3, y3, angle):
    x1_new, y1_new = rotate_point(x1, y1, angle)
    x2_new, y2_new = rotate_point(x2, y2, angle)
    x3_new, y3_new = rotate_point(x3, y3, angle)
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

# Rotation angle
angle = 45  # Rotate by 45 degrees

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

# Rotate and draw the rotated line
rotated_line = rotate_line(x1, y1, x2, y2, angle)
t.goto(rotated_line[0], rotated_line[1])
t.pendown()
t.goto(rotated_line[2], rotated_line[3])
t.penup()

# Rotate and draw the rotated triangle
rotated_triangle = rotate_triangle(x1_t, y1_t, x2_t, y2_t, x3_t, y3_t, angle)
t.goto(rotated_triangle[0], rotated_triangle[1])
t.pendown()
t.goto(rotated_triangle[2], rotated_triangle[3])
t.goto(rotated_triangle[4], rotated_triangle[5])
t.goto(rotated_triangle[0], rotated_triangle[1])
t.penup()

# Hide the turtle and display the result
t.hideturtle()
screen.mainloop()
