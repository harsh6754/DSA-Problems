def calculate_hotel_tariff(month, room_rent_per_day, days_stayed):
    if 1 <= month <= 12:
        # Checking if the month is in peak season
        is_peak_season = (month >= 4 and month <= 6) or (month >= 11 and month <= 12)

        # Applying the room rent modification for peak season
        if is_peak_season:
            room_rent_per_day *= 1.2

        # Calculating the total tariff
        total_tariff = room_rent_per_day * days_stayed

        # Printing the result
        print(int(total_tariff))
    else:
        print("Invalid Input")

# Taking input from the user
month = int(input())
room_rent_per_day = int(input())
days_stayed = int(input())

# Calling the function with the provided input
calculate_hotel_tariff(month, room_rent_per_day, days_stayed)
