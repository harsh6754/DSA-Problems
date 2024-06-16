def max_connected_component(t, test_cases):
    results = []
    
    for case in test_cases:
        n, m, grid = case
        total_hashes = sum(row.count('#') for row in grid)
        
        max_connected = total_hashes
        
        # Check each row if we turn it completely to '#'
        for r in range(n):
            row_hashes = sum(1 for c in range(m) if grid[r][c] == '.')
            max_connected = max(max_connected, total_hashes + row_hashes)
        
        # Check each column if we turn it completely to '#'
        for c in range(m):
            col_hashes = sum(1 for r in range(n) if grid[r][c] == '.')
            max_connected = max(max_connected, total_hashes + col_hashes)
        
        results.append(max_connected)
    
    return results

# Reading input
import sys
input = sys.stdin.read
data = input().split()

t = int(data[0])
index = 1
test_cases = []

for _ in range(t):
    n = int(data[index])
    m = int(data[index + 1])
    index += 2
    grid = []
    for _ in range(n):
        grid.append(data[index])
        index += 1
    test_cases.append((n, m, grid))

# Getting results
results = max_connected_component(t, test_cases)

# Printing output
for result in results:
    print(result)
