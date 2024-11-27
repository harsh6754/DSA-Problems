import pandas as pd
import numpy as np

# Create Multi-Index DataFrame
arrays = [
    ['Region A', 'Region A', 'Region B', 'Region B'],
    ['City X', 'City Y', 'City X', 'City Y']
]
index = pd.MultiIndex.from_arrays(arrays, names=['Region', 'City'])

data = {
    'Population': [1000, 2000, 1500, 2500],
    'GDP': [30000, 40000, 35000, 50000]
}

df = pd.DataFrame(data, index=index)

print("Original Multi-Index DataFrame:")
print(df)

# Select data for a specific Region
print("\nData for 'Region A':")
print(df.loc['Region A'])

# Perform operations on a specific level
# Add a new column 'GDP per capita' by dividing GDP by Population
df['GDP per capita'] = df['GDP'] / df['Population']

print("\nDataFrame with GDP per capita:")
print(df)

# Group by a specific level (Region) and calculate total Population and GDP
grouped = df.groupby(level='Region').sum()

print("\nTotal Population and GDP per Region:")
print(grouped)

# Swap levels of the MultiIndex
swapped = df.swaplevel()
print("\nDataFrame with Swapped Levels:")
print(swapped)

# Sort the DataFrame by MultiIndex
sorted_df = df.sort_index()
print("\nDataFrame Sorted by MultiIndex:")
print(sorted_df)

# Access data for specific City
print("\nData for 'City X' across all Regions:")
print(df.xs('City X', level='City'))
