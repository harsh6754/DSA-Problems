from collections import deque

# Function to simulate contamination spread
def spread_contamination(grid, r, c, p):
    h, w = len(grid), len(grid[0])
    visited = [[False] * w for _ in range(h)]
    queue = deque([(r, c, 0)])  # Initialize queue with origin cell and distance 0
    visited[r][c] = True
    contaminated_cells = 0

    while queue:
        row, col, distance = queue.popleft()
        if distance > p:
            break
        contaminated_cells += 1
        # Check neighboring cells
        for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:  # Right, Down, Left, Up
            new_row, new_col = row + dr, col + dc
            if 0 <= new_row < h and 0 <= new_col < w and not visited[new_row][new_col]:
                if distance + 1 <= p:
                    queue.append((new_row, new_col, distance + 1))
                    visited[new_row][new_col] = True

    return contaminated_cells

# Read input
test_cases = int(input())
for _ in range(test_cases):
    h, w, q = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(h)]
    for _ in range(q):
        r, c, p = map(int, input().split())
        # Adjust row and column to 0-based indexing
        r -= 1
        c -= 1
        print(spread_contamination(grid, r, c, p), end=" ")
    print() 
