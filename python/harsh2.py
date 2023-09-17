import turtle
import time


def draw_shape(t, colors):
    t.speed(0)
    for i in range(120):
        t.pencolor(colors[i % 10])
        t.circle(170-i/2, 90)
        t.lt(90)
        t.circle(190-i/3, 90)
        t.lt(60)
        time.sleep(0.05)  # add a delay between each circle


# create a turtle object and a screen object
t = turtle.Turtle()
s = turtle.Screen()

# set the screen title and background color
s.title("kreggscode")
s.bgcolor("black")

# set the screen size and position
s.setup(width=800, height=600)
s.setworldcoordinates(-400, -300, 400, 300)

# define the colors list
colors = ["yellow", "red", "gold2", "cyan", "green", "blue","orange","black","purple","pink"]

# call the draw_shape function
draw_shape(t, colors)

# keep the turtle window open after the animation is complete
s.mainloop()
