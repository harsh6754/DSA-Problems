import csv
from collections import defaultdict
import os

def generate_files(input_file_name):
    print("Current Working Directory:", os.getcwd())

    product_quantities = {}
    product_brands = defaultdict(lambda: defaultdict(int))

    with open(input_file_name, 'r') as f:
        reader = csv.reader(f)
        header = next(reader)

        for row in reader:
            product_name = row[2]
            quantity = int(row[3])
            brand = row[4]

            if product_name not in product_quantities:
                product_quantities[product_name] = [quantity, 1]
            else:
                product_quantities[product_name][0] += quantity
                product_quantities[product_name][1] += 1

            product_brands[product_name][brand] += 1

    with open("0_" + input_file_name, "w", newline='') as f:
        writer = csv.writer(f)
        writer.writerow(["Product Name", "Average Quantity"])
        for product, data in product_quantities.items():
            average_quantity = data[0] / data[1]
            writer.writerow([product, round(average_quantity, 3)])

    with open("1_" + input_file_name, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(["Product Name", "Most Popular Brand"])
        for product, brands in product_brands.items():
            most_popular = max(brands, key=brands.get)
            writer.writerow([product, most_popular])

input_file_name = "order_log.csv"
generate_files(input_file_name)
