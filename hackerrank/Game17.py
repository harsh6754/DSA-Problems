# from random import randint


# def game():
#     target=17
#     i=0

#     print("\n\nComputer\t\tUser")
#     computer=int(randint(1,2))
#     print("   ",computer,end="")
#     while(i<=target):
        
#         user=int(input("\t\t\t"))
#         if(user==computer+1 or user==computer+2):
#             i=user
#             #print("\t\t\t",user)
#             if(user==target):
#                 print("\n\nUser won")
#                 break
#         else:
#             print("Wrong input !!!")
#             print("YOU ARE DISQUALIFY")
#             break
            
#         computer=int(randint(user+1,user+2))
#         if(computer>target):
#             computer=target
#         i=computer
#         print("   ",computer,end="")
#         if(computer==target):
#             print("\n\nComputer won")
#             break
        
    
        
        
        

# print("\n\n-----------------------------Welcome to the game - Number 17 Game -----------------------------") 
# print("\n\nRules of Number 17 Game :-")
# print("\nWe will start the game by selecting a number from 1 or 2")
# print("\nYou will be playing this game with computer and First chance will be of computer")
# print("(Means First number will be selected by computer )")
# print("\nAfter the number is selected by computer, Opponent(User) will be selecting a number  ")
# print('''\n\nBut there is a restriction -
#     The number selected by next person can be only number greater by +1 or +2 only
#     example if computer selected 1 
#     then user can give input only 2 (1+1=2) or 3(1+2) only
#     And next number selected by computer will be 
#         if user selected 2 then computer will select 3/4
#         if user selected 3 then computer will select 4/5 
#     And this process will keep repeating ''')
# print("\nSo by following these steps the person who will reach to the number 17 first will be the winner")

# print("\n\nWARNING\n If you enter the number other then +1 or +2 then the previous value then you will be disqualify")
# print("Even the number same as previous number is consider as disqualify")

# print('''\nWould you like to play the game ?
#     Enter Y if you want to play 
#     else press any key''')
# choice=input("\nYour choice -> ")

# if(choice=="Y" or choice=="y"):
#     game()

# else:
#     print("You exited the game")



# from random import randint

# def game():
#     target = 17
#     i = 0

#     print("\n\nComputer\t\tUser")
#     computer = int(randint(1, 2))
#     print("   ", computer, end="")

#     while i <= target:
#         while True:
#             user = int(input("\t\t\t"))
#             if user == computer + 1 or user == computer + 2:
#                 break
#             else:
#                 print("Wrong input !!!")
#                 print("Enter a number either", computer + 1, "or", computer + 2)

#         i = user
#         if user == target:
#             print("\n\nUser won")
#             break

#         computer = int(randint(user + 1, user + 2))
#         if computer > target:
#             computer = target
#         i = computer
#         print("   ", computer, end="")
#         if computer == target:
#             print("\n\nComputer won")
#             break

# print("\n\n-----------------------------Welcome to the game - Number 17 Game -----------------------------")
# print("\n\nRules of Number 17 Game :-")
# print("\nWe will start the game by selecting a number from 1 or 2")
# print("\nYou will be playing this game with computer and First chance will be of computer")
# print("(Means First number will be selected by computer )")
# print("\nAfter the number is selected by computer, Opponent(User) will be selecting a number  ")
# print('''\n\nBut there is a restriction -
#     The number selected by next person can be only number greater by +1 or +2 only
#     example if computer selected 1 
#     then user can give input only 2 (1+1=2) or 3(1+2) only
#     And next number selected by computer will be 
#         if user selected 2 then computer will select 3/4
#         if user selected 3 then computer will select 4/5 
#     And this process will keep repeating ''')
# print("\nSo by following these steps the person who will reach to the number 17 first will be the winner")

# print("\n\nWARNING\n If you enter the number other then +1 or +2 then the previous value then you will be disqualified")
# print("Even the number same as the previous number is considered as disqualification")

# print('''\nWould you like to play the game ?
#     Enter Y if you want to play 
#     else press any key''')
# choice = input("\nYour choice -> ")

# if choice == "Y" or choice == "y":
#     game()
# else:
#     print("You exited the game")


# from random import randint

# def game():
#     target = 17
#     max_wrong_attempts = 3
#     wrong_attempts = 0

#     print("\n\nComputer\t\tUser")
#     computer = int(randint(1, 2))
#     print("   ", computer, end="")

#     while True:
#         while True:
#             user = int(input("\t\t\t"))
#             if user == computer + 1 or user == computer + 2:
#                 wrong_attempts = 0  # Reset wrong attempts on valid input
#                 break
#             else:
#                 print("Wrong input !!!")
#                 print("Enter a number either", computer + 1, "or", computer + 2)
#                 wrong_attempts += 1

#             if wrong_attempts == max_wrong_attempts:
#                 print("You've made three wrong inputs. You are disqualified!")
#                 return  # Exit the function

#         i = user
#         if user == target:
#             print("\n\nUser won")
#             break

#         computer = int(randint(user + 1, user + 2))
#         if computer > target:
#             computer = target
#         i = computer
#         print("   ", computer, end="")
#         if computer == target:
#             print("\n\nComputer won")
#             break

# print("\n\n-----------------------------Welcome to the game - Number 17 Game -----------------------------")
# print("\n\nRules of Number 17 Game :-")
# print("\nWe will start the game by selecting a number from 1 or 2")
# print("\nYou will be playing this game with computer and First chance will be of computer")
# print("(Means First number will be selected by computer )")
# print("\nAfter the number is selected by computer, Opponent(User) will be selecting a number  ")
# print('''\n\nBut there is a restriction -
#     The number selected by next person can be only number greater by +1 or +2 only
#     example if computer selected 1 
#     then user can give input only 2 (1+1=2) or 3(1+2) only
#     And next number selected by computer will be 
#         if user selected 2 then computer will select 3/4
#         if user selected 3 then computer will select 4/5 
#     And this process will keep repeating ''')
# print("\nSo by following these steps the person who will reach to the number 17 first will be the winner")

# print("\n\nWARNING\n If you enter the number other then +1 or +2 then the previous value then you will be disqualified")
# print("Even the number same as the previous number is considered as disqualification")

# print('''\nWould you like to play the game ?
#     Enter Y if you want to play 
#     else press any key''')
# choice = input("\nYour choice -> ")

# if choice.lower() == "y":
#     game()
# else:
#     print("You exited the game")


# from random import randint

# # User database for registration and login
# user_database = {}


# # Registration function
# def register():
#     print("\n----------------------------- Register -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         if username in user_database:
#             print("Username already exists. Please try a different one.")
#         else:
#             password = input("Enter your password: ")
#             user_database[username] = password
#             print("Registration successful! Please login to continue.")
#             break


# # Login function
# def login():
#     print("\n----------------------------- Login -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         password = input("Enter your password: ")

#         if username in user_database and user_database[username] == password:
#             print("Login successful! Welcome,", username)
#             return True
#         else:
#             print("Invalid username or password. Please try again.")


# # Game logic
# def game():
#     target = 17
#     max_wrong_attempts = 3
#     wrong_attempts = 0

#     print("\n\nComputer\t\tUser")
#     computer = int(randint(1, 2))
#     print("   ", computer, end="")

#     while True:
#         while True:
#             try:
#                 user = int(input("\t\t\t"))
#                 if user == computer + 1 or user == computer + 2:
#                     wrong_attempts = 0  # Reset wrong attempts on valid input
#                     break
#                 else:
#                     print("Wrong input !!!")
#                     print("Enter a number either", computer + 1, "or", computer + 2)
#                     wrong_attempts += 1

#                 if wrong_attempts == max_wrong_attempts:
#                     print("You've made three wrong inputs. You are disqualified!")
#                     return  # Exit the function
#             except ValueError:
#                 print("Invalid input. Please enter a valid number.")

#         i = user
#         if user == target:
#             print("\n\nUser won")
#             break

#         computer = int(randint(user + 1, user + 2))
#         if computer > target:
#             computer = target
#         i = computer
#         print("   ", computer, end="")
#         if computer == target:
#             print("\n\nComputer won")
#             break


# # Main function
# def main():
#     print("\n\n----------------------------- Welcome to the game - Number 17 Game -----------------------------")
#     print("\n\nRules of Number 17 Game :-")
#     print("\nWe will start the game by selecting a number from 1 or 2")
#     print("\nYou will be playing this game with computer and the first chance will be for the computer")
#     print("(Means the first number will be selected by the computer)")
#     print("\nAfter the number is selected by the computer, the user will select the next number.")
#     print('''\n\nBut there is a restriction:
#         The number selected by the next person can only be greater by +1 or +2.
#         Example:
#             If the computer selects 1,
#             then the user can only give input 2 (1+1=2) or 3 (1+2).
#         And the next number selected by the computer will be:
#             If the user selects 2, then the computer will select 3/4.
#             If the user selects 3, then the computer will select 4/5.
#         And this process will keep repeating.''')
#     print("\nSo by following these steps, the person who reaches the number 17 first will be the winner.")
#     print("\n\nWARNING\n If you enter a number other than +1 or +2 of the previous value, you will be disqualified.")
#     print("Even the same number as the previous number is considered a disqualification.")

#     while True:
#         print("\n----------------------------- Menu -----------------------------")
#         print("1. Register")
#         print("2. Login")
#         print("3. Exit")
#         choice = input("Enter your choice: ")

#         if choice == "1":
#             register()
#         elif choice == "2":
#             if login():
#                 print('''\nWould you like to play the game?
#                     Enter Y if you want to play 
#                     else press any key.''')
#                 game_choice = input("\nYour choice -> ")
#                 if game_choice.lower() == "y":
#                     game()
#                 else:
#                     print("You exited the game.")
#         elif choice == "3":
#             print("Exiting the program. Goodbye!")
#             break
#         else:
#             print("Invalid choice. Please try again.")


# if __name__ == "__main__":
#     main()



# from random import randint

# # User database for registration and login
# user_database = {}

# # Registration function
# def register():
#     print("\n----------------------------- Register -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         if username in user_database:
#             print("Username already exists. Please try a different one.")
#         else:
#             password = input("Enter your password: ")
#             user_database[username] = password
#             print("Registration successful! Please login to continue.")
#             break

# # Login function
# def login():
#     print("\n----------------------------- Login -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         password = input("Enter your password: ")

#         if username in user_database and user_database[username] == password:
#             print("Login successful! Welcome,", username)
#             return username
#         else:
#             print("Invalid username or password. Please try again.")

# # Game logic
# def game(username):
#     target = 17
#     max_wrong_attempts = 3
#     wrong_attempts = 0

#     print("\n\nComputer\t\tUser")
#     computer = int(randint(1, 2))
#     print("   ", computer, end="")

#     while True:
#         print(f"\n\n{username}, it's your turn. Choose a number +1 or +2 from {computer}.")
#         while True:
#             try:
#                 user = int(input("\t\t\t"))
#                 if user == computer + 1 or user == computer + 2:
#                     wrong_attempts = 0  # Reset wrong attempts on valid input
#                     break
#                 else:
#                     print("Wrong input !!!")
#                     print("Enter a number either", computer + 1, "or", computer + 2)
#                     wrong_attempts += 1

#                 if wrong_attempts == max_wrong_attempts:
#                     print("You've made three wrong inputs. You are disqualified!")
#                     return  # Exit the function
#             except ValueError:
#                 print("Invalid input. Please enter a valid number.")

#         if user == target:
#             print("\n\nUser won")
#             break

#         computer = int(randint(user + 1, user + 2))
#         if computer > target:
#             computer = target
#         print(f"Computer chose {computer}. Now it's your turn, {username}.")
#         if computer == target:
#             print("\n\nComputer won")
#             break

# # Main function
# def main():
#     print("\n\n----------------------------- Welcome to the game - Number 17 Game -----------------------------")
#     print("\n\nRules of Number 17 Game :-")
#     print("\nWe will start the game by selecting a number from 1 or 2")
#     print("\nYou will be playing this game with computer and the first chance will be for the computer")
#     print("(Means the first number will be selected by the computer)")
#     print("\nAfter the number is selected by the computer, the user will select the next number.")
#     print('''\n\nBut there is a restriction:
#         The number selected by the next person can only be greater by +1 or +2.
#         Example:
#             If the computer selects 1,
#             then the user can only give input 2 (1+1=2) or 3 (1+2).
#         And the next number selected by the computer will be:
#             If the user selects 2, then the computer will select 3/4.
#             If the user selects 3, then the computer will select 4/5.
#         And this process will keep repeating.''')
#     print("\nSo by following these steps, the person who reaches the number 17 first will be the winner.")
#     print("\n\nWARNING\n If you enter a number other than +1 or +2 of the previous value, you will be disqualified.")
#     print("Even the same number as the previous number is considered a disqualification.")

#     while True:
#         print("\n----------------------------- Menu -----------------------------")
#         print("1. Register")
#         print("2. Login")
#         print("3. Exit")
#         choice = input("Enter your choice: ")

#         if choice == "1":
#             register()
#         elif choice == "2":
#             username = login()
#             if username:
#                 print('''\nWould you like to play the game?
#                     Enter Y if you want to play 
#                     else press any key.''')
#                 game_choice = input("\nYour choice -> ")
#                 if game_choice.lower() == "y":
#                     game(username)
#                 else:
#                     print("You exited the game.")
#         elif choice == "3":
#             print("Exiting the program. Goodbye!")
#             break
#         else:
#             print("Invalid choice. Please try again.")

# if __name__ == "__main__":
#     main()




# from random import randint

# # User database for registration and login
# user_database = {}

# # Registration function
# def register():
#     print("\n----------------------------- Register -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         if username in user_database:
#             print("Username already exists. Please try a different one.")
#         else:
#             password = input("Enter your password: ")
#             user_database[username] = password
#             print("Registration successful! Please login to continue.")
#             break

# # Login function
# def login():
#     print("\n----------------------------- Login -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         password = input("Enter your password: ")

#         if username in user_database and user_database[username] == password:
#             print("Login successful! Welcome,", username)
#             return username
#         else:
#             print("Invalid username or password. Please try again.")

# # Game logic
# def game(username):
#     target = 17
#     max_wrong_attempts = 3
#     wrong_attempts = 0

#     moves = []  # To store the sequence of moves (computer and user choices)

#     print("\n\nComputer\t\tUser")
#     computer = int(randint(1, 2))
#     print("   ", computer, end="")
#     moves.append(("Computer", computer))

#     while True:
#         print(f"\n\n{username}, it's your turn. Choose a number +1 or +2 from {computer}.")
#         while True:
#             try:
#                 user = int(input("\t\t\t"))
#                 if user == computer + 1 or user == computer + 2:
#                     wrong_attempts = 0  # Reset wrong attempts on valid input
#                     moves.append((username, user))
#                     break
#                 else:
#                     print("Wrong input !!!")
#                     print("Enter a number either", computer + 1, "or", computer + 2)
#                     wrong_attempts += 1

#                 if wrong_attempts == max_wrong_attempts:
#                     print("You've made three wrong inputs. You are disqualified!")
#                     return  # Exit the function
#             except ValueError:
#                 print("Invalid input. Please enter a valid number.")

#         if user == target:
#             print("\n\nUser won")
#             break

#         computer = int(randint(user + 1, user + 2))
#         if computer > target:
#             computer = target
#         print(f"Computer chose {computer}. Now it's your turn, {username}.")
#         moves.append(("Computer", computer))
#         if computer == target:
#             print("\n\nComputer won")
#             break

#     # Display the moves table
#     print("\n\n----------------------------- Moves Table -----------------------------")
#     print("Player\t\tNumber")
#     print("------------------------------------------")
#     for move in moves:
#         print(f"{move[0]}\t\t{move[1]}")

# # Main function
# def main():
#     print("\n\n----------------------------- Welcome to the game - Number 17 Game -----------------------------")
#     print("\n\nRules of Number 17 Game :-")
#     print("\nWe will start the game by selecting a number from 1 or 2")
#     print("\nYou will be playing this game with computer and the first chance will be for the computer")
#     print("(Means the first number will be selected by the computer)")
#     print("\nAfter the number is selected by the computer, the user will select the next number.")
#     print('''\n\nBut there is a restriction:
#         The number selected by the next person can only be greater by +1 or +2.
#         Example:
#             If the computer selects 1,
#             then the user can only give input 2 (1+1=2) or 3 (1+2).
#         And the next number selected by the computer will be:
#             If the user selects 2, then the computer will select 3/4.
#             If the user selects 3, then the computer will select 4/5.
#         And this process will keep repeating.''')
#     print("\nSo by following these steps, the person who reaches the number 17 first will be the winner.")
#     print("\n\nWARNING\n If you enter a number other than +1 or +2 of the previous value, you will be disqualified.")
#     print("Even the same number as the previous number is considered a disqualification.")

#     while True:
#         print("\n----------------------------- Menu -----------------------------")
#         print("1. Register")
#         print("2. Login")
#         print("3. Exit")
#         choice = input("Enter your choice: ")

#         if choice == "1":
#             register()
#         elif choice == "2":
#             username = login()
#             if username:
#                 print('''\nWould you like to play the game?
#                     Enter Y if you want to play 
#                     else press any key.''')
#                 game_choice = input("\nYour choice -> ")
#                 if game_choice.lower() == "y":
#                     game(username)
#                 else:
#                     print("You exited the game.")
#         elif choice == "3":
#             print("Exiting the program. Goodbye!")
#             break
#         else:
#             print("Invalid choice. Please try again.")

# if __name__ == "__main__":
#     main()



# from random import randint

# # User database for registration and login
# user_database = {}

# # Registration function
# def register():
#     print("\n----------------------------- Register -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         if username in user_database:
#             print("Username already exists. Please try a different one.")
#         else:
#             password = input("Enter your password: ")
#             user_database[username] = password
#             print("Registration successful! Please login to continue.")
#             break

# # Login function
# def login():
#     print("\n----------------------------- Login -----------------------------")
#     while True:
#         username = input("\nEnter your username: ")
#         password = input("Enter your password: ")

#         if username in user_database and user_database[username] == password:
#             print("Login successful! Welcome,", username)
#             return username
#         else:
#             print("Invalid username or password. Please try again.")

# # Game logic
# def game(username):
#     target = 17
#     max_wrong_attempts = 3
#     wrong_attempts = 0

#     moves = []  # To store the sequence of moves (computer and user choices)

#     print("\n\nComputer\t\tUser")
#     computer = int(randint(1, 2))
#     print("   ", computer, end="")
#     moves.append(("Computer", computer))

#     while True:
#         print(f"\n\n{username}, it's your turn. Choose a number +1 or +2 from {computer}.")
#         while True:
#             try:
#                 user = int(input("\t\t\t"))
#                 if user == computer + 1 or user == computer + 2:
#                     wrong_attempts = 0  # Reset wrong attempts on valid input
#                     moves.append((username, user))
#                     break
#                 else:
#                     print("Wrong input !!!")
#                     print("Enter a number either", computer + 1, "or", computer + 2)
#                     wrong_attempts += 1

#                 if wrong_attempts == max_wrong_attempts:
#                     print("You've made three wrong inputs. You are disqualified!")
#                     # Display the moves table before exiting
#                     display_moves_table(moves)
#                     return
#             except ValueError:
#                 print("Invalid input. Please enter a valid number.")

#         if user == target:
#             print("\n\nUser won!")
#             break

#         computer = int(randint(user + 1, user + 2))
#         if computer > target:
#             computer = target
#         print(f"Computer chose {computer}. Now it's your turn, {username}.")
#         moves.append(("Computer", computer))
#         if computer == target:
#             print("\n\nComputer won!")
#             break

#     # Display the moves table at the end of the game
#     display_moves_table(moves)

# # Function to display the moves table
# def display_moves_table(moves):
#     print("\n\n----------------------------- Moves Table -----------------------------")
#     print("Player\t\tNumber")
#     print("------------------------------------------")
#     for move in moves:
#         print(f"{move[0]}\t\t{move[1]}")

# # Main function
# def main():
#     print("\n\n----------------------------- Welcome to the game - Number 17 Game -----------------------------")
#     print("\n\nRules of Number 17 Game :-")
#     print("\nWe will start the game by selecting a number from 1 or 2")
#     print("\nYou will be playing this game with computer and the first chance will be for the computer")
#     print("(Means the first number will be selected by the computer)")
#     print("\nAfter the number is selected by the computer, the user will select the next number.")
#     print('''\n\nBut there is a restriction:
#         The number selected by the next person can only be greater by +1 or +2.
#         Example:
#             If the computer selects 1,
#             then the user can only give input 2 (1+1=2) or 3 (1+2).
#         And the next number selected by the computer will be:
#             If the user selects 2, then the computer will select 3/4.
#             If the user selects 3, then the computer will select 4/5.
#         And this process will keep repeating.''')
#     print("\nSo by following these steps, the person who reaches the number 17 first will be the winner.")
#     print("\n\nWARNING\n If you enter a number other than +1 or +2 of the previous value, you will be disqualified.")
#     print("Even the same number as the previous number is considered a disqualification.")

#     while True:
#         print("\n----------------------------- Menu -----------------------------")
#         print("1. Register")
#         print("2. Login")
#         print("3. Exit")
#         choice = input("Enter your choice: ")

#         if choice == "1":
#             register()
#         elif choice == "2":
#             username = login()
#             if username:
#                 print('''\nWould you like to play the game?
#                     Enter Y if you want to play 
#                     else press any key.''')
#                 game_choice = input("\nYour choice -> ")
#                 if game_choice.lower() == "y":
#                     game(username)
#                 else:
#                     print("You exited the game.")
#         elif choice == "3":
#             print("Exiting the program. Goodbye!")
#             break
#         else:
#             print("Invalid choice. Please try again.")

# if __name__ == "__main__":
#     main()


from random import randint

# User database for registration and login
user_database = {}

# Registration function
def register():
    print("\n----------------------------- Register -----------------------------")
    while True:
        username = input("\nEnter your username: ")
        if username in user_database:
            print("Username already exists. Please try a different one.")
        else:
            password = input("Enter your password: ")
            user_database[username] = password
            print("Registration successful! Please login to continue.")
            break

# Login function
def login():
    print("\n----------------------------- Login -----------------------------")
    while True:
        username = input("\nEnter your username: ")
        password = input("Enter your password: ")

        if username in user_database and user_database[username] == password:
            print("Login successful! Welcome,", username)
            return username
        else:
            print("Invalid username or password. Please try again.")

# Game logic
def game(username):
    target = 17
    max_wrong_attempts = 3
    wrong_attempts = 0

    moves = []  # To store the sequence of moves (computer and user choices)

    print("\n\nComputer\t\tUser")
    computer = int(randint(1, 2))
    print("   ", computer, end="")
    moves.append(("Computer", computer))

    while True:
        print(f"\n\n{username}, it's your turn. Choose a number +1 or +2 from {computer}.")
        while True:
            try:
                user = int(input("\t\t\t"))
                if user == computer + 1 or user == computer + 2:
                    wrong_attempts = 0  # Reset wrong attempts on valid input
                    moves.append((username, user))
                    break
                else:
                    print("Wrong input !!!")
                    print("Enter a number either", computer + 1, "or", computer + 2)
                    wrong_attempts += 1

                if wrong_attempts == max_wrong_attempts:
                    print("You've made three wrong inputs. You are disqualified!")
                    # Display the moves table before exiting
                    display_moves_table(moves)
                    return
            except ValueError:
                print("Invalid input. Please enter a valid number.")

        if user == target:
            print("\n\nUser won!")
            break

        # Computer's turn
        computer = int(randint(user + 1, user + 2))
        if computer > target:
            computer = target
        print(f"\nComputer chose {computer}. Now it's your turn, {username}.")
        moves.append(("Computer", computer))
        if computer == target:
            print("\n\nComputer won!")
            break

    # Display the moves table at the end of the game
    display_moves_table(moves)

# Function to display the moves table
def display_moves_table(moves):
    print("\n\n----------------------------- Moves Table -----------------------------")
    print("Player\t\tNumber")
    print("------------------------------------------")
    for move in moves:
        print(f"{move[0]}\t\t{move[1]}")

# Main function
def main():
    print("\n\n----------------------------- Welcome to the game - Number 17 Game -----------------------------")
    print("\n\nRules of Number 17 Game :-")
    print("\nWe will start the game by selecting a number from 1 or 2")
    print("\nYou will be playing this game with computer and the first chance will be for the computer")
    print("(Means the first number will be selected by the computer)")
    print("\nAfter the number is selected by the computer, the user will select the next number.")
    print('''\n\nBut there is a restriction:
        The number selected by the next person can only be greater by +1 or +2.
        Example:
            If the computer selects 1,
            then the user can only give input 2 (1+1=2) or 3 (1+2).
        And the next number selected by the computer will be:
            If the user selects 2, then the computer will select 3/4.
            If the user selects 3, then the computer will select 4/5.
        And this process will keep repeating.''')
    print("\nSo by following these steps, the person who reaches the number 17 first will be the winner.")
    print("\n\nWARNING\n If you enter a number other than +1 or +2 of the previous value, you will be disqualified.")
    print("Even the same number as the previous number is considered a disqualification.")

    while True:
        print("\n----------------------------- Menu -----------------------------")
        print("1. Register")
        print("2. Login")
        print("3. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            register()
        elif choice == "2":
            username = login()
            if username:
                print('''\nWould you like to play the game?
                    Enter Y if you want to play 
                    else press any key.''')
                game_choice = input("\nYour choice -> ")
                if game_choice.lower() == "y":
                    game(username)
                else:
                    print("You exited the game.")
        elif choice == "3":
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
