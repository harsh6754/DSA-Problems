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


from random import randint

def game():
    target = 17
    max_wrong_attempts = 3
    wrong_attempts = 0

    print("\n\nComputer\t\tUser")
    computer = int(randint(1, 2))
    print("   ", computer, end="")

    while True:
        while True:
            user = int(input("\t\t\t"))
            if user == computer + 1 or user == computer + 2:
                wrong_attempts = 0  # Reset wrong attempts on valid input
                break
            else:
                print("Wrong input !!!")
                print("Enter a number either", computer + 1, "or", computer + 2)
                wrong_attempts += 1

            if wrong_attempts == max_wrong_attempts:
                print("You've made three wrong inputs. You are disqualified!")
                return  # Exit the function

        i = user
        if user == target:
            print("\n\nUser won")
            break

        computer = int(randint(user + 1, user + 2))
        if computer > target:
            computer = target
        i = computer
        print("   ", computer, end="")
        if computer == target:
            print("\n\nComputer won")
            break

print("\n\n-----------------------------Welcome to the game - Number 17 Game -----------------------------")
print("\n\nRules of Number 17 Game :-")
print("\nWe will start the game by selecting a number from 1 or 2")
print("\nYou will be playing this game with computer and First chance will be of computer")
print("(Means First number will be selected by computer )")
print("\nAfter the number is selected by computer, Opponent(User) will be selecting a number  ")
print('''\n\nBut there is a restriction -
    The number selected by next person can be only number greater by +1 or +2 only
    example if computer selected 1 
    then user can give input only 2 (1+1=2) or 3(1+2) only
    And next number selected by computer will be 
        if user selected 2 then computer will select 3/4
        if user selected 3 then computer will select 4/5 
    And this process will keep repeating ''')
print("\nSo by following these steps the person who will reach to the number 17 first will be the winner")

print("\n\nWARNING\n If you enter the number other then +1 or +2 then the previous value then you will be disqualified")
print("Even the number same as the previous number is considered as disqualification")

print('''\nWould you like to play the game ?
    Enter Y if you want to play 
    else press any key''')
choice = input("\nYour choice -> ")

if choice.lower() == "y":
    game()
else:
    print("You exited the game")
