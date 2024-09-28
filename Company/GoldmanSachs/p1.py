import pandas as pd
import numpy as np
from scipy.stats import norm
from io import StringIO

def read_input():
    inputdata = input()
    inputdata = inputdata.replace("\\n", "\n")
    inputdata = StringIO(inputdata)
    return pd.read_csv(inputdata)

def black_scholes(S, K, T, r, sigma, option_type):
    d1 = (np.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * np.sqrt(T))
    d2 = d1 - sigma * np.sqrt(T)
    
    if option_type == 'Call':
        price = S * norm.cdf(d1) - K * np.exp(-r * T) * norm.cdf(d2)
    else:  # Put
        price = K * np.exp(-r * T) * norm.cdf(-d2) - S * norm.cdf(-d1)
    
    return max(price, 0)  # Ensure non-negative price

def predict_option_price(row):
    S = row['Spot']
    K = row['Strike']
    T = row['TimeToExpiry']
    r = row['RiskfreeRate'] / 100  # Convert percentage to decimal
    
    # Use MarketFearIndex as a proxy for volatility (sigma)
    sigma = row['MarketFearIndex'] / 100  # Scale down to a reasonable volatility range
    
    option_type = row['OptionType']
    
    # Adjust price based on BuySellRatio
    base_price = black_scholes(S, K, T, r, sigma, option_type)
    adjusted_price = base_price * (row['BuySellRatio'] ** 0.1)  # Slight adjustment based on BuySellRatio
    
    return round(adjusted_price, 6)  # Round to 6 decimal places

def main():
    # Read input
    df = read_input()
    
    # Predict option prices
    df['OptionPrice'] = df.apply(predict_option_price, axis=1)
    
    # Prepare output
    output_df = df[['Id', 'OptionPrice']]
    
    # Print output
    print(output_df.to_csv(index=False))

if __name__ == "__main__":
    main()