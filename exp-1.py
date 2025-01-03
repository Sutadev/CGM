import matplotlib.pyplot as plt
import numpy as np

def plot_line(slope, intercept):
    # Define the range of x values
    x = np.linspace(-10, 10, 100)  # x values from -10 to 10
    # Calculate corresponding y values using y = mx + c
    y = slope * x + intercept

    # Plot the line
    plt.plot(x, y, label=f"y = {slope}x + {intercept}")

    # Label the axes
    plt.xlabel("x-axis")
    plt.ylabel("y-axis")
    plt.title("Line using Slope-Intercept Formula")
    plt.axhline(0, color='black',linewidth=0.5)  # Add x-axis
    plt.axvline(0, color='black',linewidth=0.5)  # Add y-axis
    plt.grid(color='gray', linestyle='--', linewidth=0.5)  # Add grid
    plt.legend()  # Show legend

    # Show the plot
    plt.show()

# Input for slope and intercept
m = float(input("Enter the slope (m): "))
c = float(input("Enter the y-intercept (c): "))

# Plot the line
plot_line(m, c)
