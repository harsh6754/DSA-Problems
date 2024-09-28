from collections import defaultdict
from typing import Dict, List, Tuple, Set
from io import StringIO

class Stock:
    def __init__(self, id: str, price: float):
        self.id = id
        self.price = price

class Account:
    def __init__(self, id: str, type: str, parent: int):
        self.id = id
        self.type = type
        self.parent = parent

def read_input() -> Tuple[Dict[str, Stock], Dict[str, Account], Dict[str, Set[str]], Dict[str, Dict[str, Set[str]]], Dict[str, Dict[str, int]]]:
    stocks = {}
    accounts = {}
    eligible_accounts = defaultdict(set)
    eligible_flows = defaultdict(lambda: defaultdict(set))
    balances = defaultdict(lambda: defaultdict(int))

    # Read stocks
    n_stocks = int(input("Enter the number of stocks: "))
    for _ in range(n_stocks):
        stock_id, price = input("Enter stock details (id,price): ").split(',')
        stocks[stock_id] = Stock(stock_id, float(price))

    # Read accounts
    n_accounts = int(input("Enter the number of accounts: "))
    for _ in range(n_accounts):
        account_id, account_type, parent = input("Enter account details (id,type,parent): ").split(',')
        accounts[account_id] = Account(account_id, account_type, int(parent))

    # Read eligible accounts
    n_eligible_accounts = int(input("Enter the number of eligible accounts: "))
    for _ in range(n_eligible_accounts):
        stock_id, account_id = input("Enter eligible account (stock_id,account_id): ").split(',')
        eligible_accounts[stock_id].add(account_id)

    # Read eligible flows
    n_eligible_flows = int(input("Enter the number of eligible flows: "))
    for _ in range(n_eligible_flows):
        stock_id, source, destination = input("Enter eligible flow (stock_id,source,destination): ").split(',')
        eligible_flows[stock_id][source].add(destination)

    # Read balances
    n_balances = int(input("Enter the number of balances: "))
    for _ in range(n_balances):
        stock_id, account_id, quantity = input("Enter balance (stock_id,account_id,quantity): ").split(',')
        balances[stock_id][account_id] = int(quantity)

    return stocks, accounts, eligible_accounts, eligible_flows, balances

def optimize_movements(stocks: Dict[str, Stock], accounts: Dict[str, Account], eligible_accounts: Dict[str, Set[str]], 
                       eligible_flows: Dict[str, Dict[str, Set[str]]], balances: Dict[str, Dict[str, int]]) -> List[Tuple[str, str, str, int]]:
    movements = []

    for stock_id, stock_balances in balances.items():
        excess = [(acc, qty) for acc, qty in stock_balances.items() if qty > 0]
        demand = [(acc, -qty) for acc, qty in stock_balances.items() if qty < 0]

        # Sort excess and demand by parent account and quantity
        excess.sort(key=lambda x: (accounts[x[0]].parent, -x[1]))
        demand.sort(key=lambda x: (accounts[x[0]].parent, x[1]))

        while excess and demand:
            source, available = excess[0]
            dest, needed = demand[0]

            if dest in eligible_flows[stock_id][source]:
                # Direct transfer
                quantity = min(available, needed)
                movements.append((stock_id, source, dest, quantity))
                excess[0] = (source, available - quantity)
                demand[0] = (dest, needed - quantity)
            else:
                # Try to find an intermediate account
                for mid in eligible_flows[stock_id][source]:
                    if dest in eligible_flows[stock_id][mid]:
                        quantity = min(available, needed)
                        movements.append((stock_id, source, mid, quantity))
                        movements.append((stock_id, mid, dest, quantity))
                        excess[0] = (source, available - quantity)
                        demand[0] = (dest, needed - quantity)
                        break
                else:
                    # No valid path found, move to next demand
                    demand.pop(0)
                    continue

            if excess[0][1] == 0:
                excess.pop(0)
            if demand[0][1] == 0:
                demand.pop(0)

        # Move remaining excess to TRIPARTY accounts
        for source, available in excess:
            triparty = next((acc for acc in eligible_accounts[stock_id] 
                             if accounts[acc].type == 'TRIPARTY' and acc in eligible_flows[stock_id][source]), 
                            None)
            if triparty:
                movements.append((stock_id, source, triparty, available))

    return sorted(movements)

def main():
    stocks, accounts, eligible_accounts, eligible_flows, balances = read_input()
    optimized_movements = optimize_movements(stocks, accounts, eligible_accounts, eligible_flows, balances)

    for movement in optimized_movements:
        print(f"{movement[0]},{movement[1]},{movement[2]},{movement[3]}")

if __name__ == "__main__":
    main()
