def doesCircleExist(commands):
    results = []
    for command in commands:
        # Directions correspond to [north, east, south, west]
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        # Initial position (x, y) and facing direction index
        x, y, dir_idx = 0, 0, 0
        # Simulate the command sequence
        for move in command:
            if move == 'G':
                x += directions[dir_idx][0]
                y += directions[dir_idx][1]
            elif move == 'L':
                dir_idx = (dir_idx - 1) % 4  # Turn left
            elif move == 'R':
                dir_idx = (dir_idx + 1) % 4  # Turn right
        # If the robot returns to the origin or changes direction (not facing north), 
        # it will eventually loop
        if (x, y) == (0, 0) or dir_idx != 0:
            results.append("YES")
        else:
            results.append("NO")
    print(results)

# Test the function
doesCircleExist(["GGLLGG","GG","GLGLGLGG"])



def doesCircleExist(commands):
    results = []
    for command in commands:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        x, y, dir_idx = 0, 0, 0

        for move in command:
            if move == 'G':
                x += directions[dir_idx][0]
                y += directions[dir_idx][1]
            elif move == 'L':
                dir_idx = (dir_idx - 1) % 4  # Turn left
            elif move == 'R':
                dir_idx = (dir_idx + 1) % 4  # Turn right
        if (x, y) == (0, 0) or dir_idx != 0:
            results.append("YES")
        else:
            results.append("NO")
    return results
