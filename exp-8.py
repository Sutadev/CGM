import turtle

# Function to draw and fill a circle with a specified color
def draw_filled_circle(radius, color):
    turtle.penup()
    turtle.goto(0, -radius)  # Move turtle to the start position
    turtle.pendown()
    turtle.begin_fill()  # Start filling
    turtle.fillcolor(color)  # Set the fill color
    turtle.circle(radius)  # Draw the circle
    turtle.end_fill()  # End filling

# Set up screen and turtle
screen = turtle.Screen()
screen.bgcolor("white")  # Set background color to white
t = turtle.Turtle()
t.speed(1)

# Draw a filled circle with radius 100 and red color
draw_filled_circle(100, "red")

# Hide the turtle and display the result
t.hideturtle()
screen.mainloop()
