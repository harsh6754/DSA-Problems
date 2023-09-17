import turtle
t = turtle.Turtle()
s = turtle.Screen()
s.title("kreggscode")
s.bgcolor("black")
t.speed(0)
col = ["yellow", "red", "gold2", "cyan", "green", "blue"]

for i in range(120):
    t.pencolor(col[i % 6])
    t.circle(170-i/2, 90)
    t.lt(90)
    t.circle(190-i/3, 90)
    t.lt(60)
s.exitonclick()
