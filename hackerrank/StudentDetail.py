class Detail:
    def __init__(self, name, roll_number, marks):
        self.name = name
        self.roll_number = roll_number
        self.marks = marks

    def calculate_percentage(self):
        return (float(self.marks / 500) * 100)

    def display_detail(self):
        print("Student details:")
        print(f"Name:{self.name}")
        print(f"Roll Number:{self.roll_number}")
        print(f"Total:{self.marks}")
        print(f"Percentage:{format(self.calculate_percentage(), '.1f')}")

name = input("Enter name:")
roll_number = int(input("Enter roll number:"))
marks = int(input("Enter total marks out of 500:"))

obj = Detail(name, roll_number, marks)
obj.display_detail()