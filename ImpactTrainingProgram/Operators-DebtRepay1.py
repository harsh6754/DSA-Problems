principal = float(input())
years = float(input())
rate = float(input())


interest = (principal * rate * years) / 100.0
amount = principal + interest
discount = 0.02 * interest
final_settlement = amount - discount

print("{:.2f}".format(interest))
print("{:.2f}".format(amount))
print("{:.2f}".format(discount))
print("{:.2f}".format(final_settlement))
