from collections import deque

def find_min_clicks(N, pages, start, end):
    visited = [False] * (N + 1)
    queue = deque([(start, 0)])

    while queue:
        current_page, clicks = queue.popleft()
        visited[current_page] = True

        if current_page == end:
            return clicks

        for linked_page in pages[current_page]:
            if not visited[linked_page]:
                queue.append((linked_page, clicks + 1))

    return -1

try:
    N = int(input())
    pages = [[] for _ in range(N + 1)]
    for i in range(1, N + 1):
        pages[i] = list(map(int, input().split()))

    start, end = map(int, input().split())

    result = find_min_clicks(N, pages, start, end)
    print(result, end='')
except ValueError:
    print("Invalid input. Please enter valid integers.")
except IndexError:
    print("Index out of range. Please check your input data.")
except Exception as e:
    print(f"An error occurred: {str(e)}")
