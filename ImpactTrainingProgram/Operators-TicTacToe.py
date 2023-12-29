def convert_to_row_column(n):
    row = (n - 1) // 3
    column = (n - 1) % 3
    return row, column

 
n = int(input().strip())

row, column = convert_to_row_column(n)

print(f"{row} {column}")
