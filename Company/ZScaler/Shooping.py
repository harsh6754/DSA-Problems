import csv
import io
from collections import defaultdict

def generate_files(input_data):


    product_quantity = defaultdict(list)
    product_brand_orders = defaultdict(lambda: defaultdict(int))

    with io.StringIO(input_data) as infile:
        reader = csv.reader(infile)
        for order_id, area, product, quantity, brand in reader:
            quantity = int(quantity)
            product_quantity[product].append(quantity)
            product_brand_orders[product][brand] += 1

    avg_quantity_data = [
        [product, round(sum(quantities) / len(quantities), 2)]
        for product, quantities in product_quantity.items()
    ]

    popular_brand_data = [
        [product, max(brands, key=brands.get)]
        for product, brands in product_brand_orders.items()
    ]

    for data, filename in [(avg_quantity_data, "6_output.txt"), (popular_brand_data, "1_output.txt")]:
        with open(filename, mode='w', newline='') as outfile:
            for row in data:
                outfile.write(",".join(map(str, row)) + "\n")


# Read input from HackerRank
num_test_cases = int(input())
for _ in range(num_test_cases):
    input_data = ""
    num_orders = int(input())
    for _ in range(num_orders):
        input_data += input() + "\n"
    generate_files(input_data)