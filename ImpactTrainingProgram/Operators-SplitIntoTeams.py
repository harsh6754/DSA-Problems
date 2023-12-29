def split_teams():
    num_friends = int(input())
    num_teams = int(input())

    friends_per_team = num_friends // num_teams
    left_out_friends = num_friends % num_teams

    print(f"The number of friends in each team is {friends_per_team} and left out is {left_out_friends}")

# Call the function
split_teams()
