import heapq

def delivery_order(cityNodes, roads, company):
    graph = {}
    for i in range(1, cityNodes + 1):
        graph[i] = []

    for road in roads:
        city_from, city_to = road
        graph[city_from].append(city_to)
        graph[city_to].append(city_from)
    distances = {city:float('inf') for city in range(1,cityNodes + 1)}
    distances[company] = 0
    pq = [(0, company)] 

    while pq:
        dist, node = heapq.heappop(pq)
        if dist > distances[node]:
            continue
        for neighbor in graph[node]:
            new_dist = dist + 1  
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))

    sorted_cities = sorted(distances.keys(), key=lambda x: (distances[x], x))

    sorted_cities.remove(company)

    return sorted_cities

cityNodes, roads_count = map(int, input().split())
roads = [list(map(int, input().split())) for _ in range(roads_count)]
company = int(input())

delivery_order_list = delivery_order(cityNodes, roads, company)

for city in delivery_order_list:
    print(city)
