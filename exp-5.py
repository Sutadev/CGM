import turtle

# Function to translate a point by a vector
def translate_point(x, y, tx, ty):
    return x + tx, y + ty

# Function to translate a line by a translation vector
def translate_line(x1, y1, x2, y2, tx, ty):
    x1_new, y1_new = translate_point(x1, y1, tx, ty)
    x2_new, y2_new = translate_point(x2, y2, tx, ty)
    return x1_new, y1_new, x2_new, y2_new

# Function to translate a triangle by a translation vector
def translate_triangle(x1, y1, x2, y2, x3, y3, tx, ty):
    x1_new, y1_new = translate_point(x1, y1, tx, ty)
    x2_new, y2_new = translate_point(x2, y2, tx, ty)
    x3_new, y3_new = translate_point(x3, y3, tx, ty)
    return x1_new, y1_new, x2_new, y2_new, x3_new, y3_new

# Initialize screen and turtle
screen = turtle.Screen()
t = turtle.Turtle()

# Set up for drawing line and triangle
t.penup()

# Original line (x1, y1) to (x2, y2)
x1, y1, x2, y2 = -200, -100, 100, 100
# Original triangle (x1, y1), (x2, y2), (x3, y3)
x1_t, y1_t, x2_t, y2_t, x3_t, y3_t = -150, -150, 50, -150, 0, 50

# Translation vector (tx, ty)
tx, ty = 150, 100

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

# Translate line
translated_line = translate_line(x1, y1, x2, y2, tx, ty)
t.goto(translated_line[0], translated_line[1])
t.pendown()
t.goto(translated_line[2], translated_line[3])
t.penup()

# Translate triangle
translated_triangle = translate_triangle(x1_t, y1_t, x2_t, y2_t, x3_t, y3_t, tx, ty)
t.goto(translated_triangle[0], translated_triangle[1])
t.pendown()
t.goto(translated_triangle[2], translated_triangle[3])
t.goto(translated_triangle[4], translated_triangle[5])
t.goto(translated_triangle[0], translated_triangle[1])
t.penup()

# Hide the turtle and display the result
t.hideturtle()
screen.mainloop()
