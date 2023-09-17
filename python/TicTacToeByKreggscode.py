import pygame
import sys

# Initialize Pygame
pygame.init()

# Set the size of the screen
size = (300, 300)
screen = pygame.display.set_mode(size)

# Set the title of the window
pygame.display.set_caption("TIC TAC TOE BY KREGGSCODE ")

# Define colors
yellow = (255, 255, 0)
black = (0, 0, 0)

# Define the font
font = pygame.font.Font(None, 36)

# Define the board
board = [[None, None, None], [None, None, None], [None, None, None]]

# Define the player
player = "X"

# Define the winner
winner = None

# Define the game loop
while True:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN and not winner:
            # Get the position of the mouse click
            pos = pygame.mouse.get_pos()
            column = pos[0] // 100
            row = pos[1] // 100

            # If the cell is empty, fill it with the player's mark
            if board[row][column] == None:
                board[row][column] = player

                # Check for a winner
                if (board[row][0] == board[row][1] == board[row][2] == player or
                    board[0][column] == board[1][column] == board[2][column] == player or
                    board[0][0] == board[1][1] == board[2][2] == player or
                    board[2][0] == board[1][1] == board[0][2] == player):
                    winner = player

                # Switch to the other player
                if player == "X":
                    player = "O"
                else:
                    player = "X"

    # Fill the screen with yellow
    screen.fill(yellow)

    # Draw the board
    for row in range(3):
        for column in range(3):
            pygame.draw.rect(screen, black, [column * 100, row * 100, 100, 100], 2)

    # Draw the X's and O's
    for row in range(3):
        for column in range(3):
            if board[row][column] == "X":
                text = font.render("X", True, black)
                screen.blit(text, [column * 100 + 35, row * 100 + 25])
            elif board[row][column] == "O":
                text = font.render("O", True, black)
                screen.blit(text, [column * 100 + 35, row * 100 + 25])

    # Draw the winner message if there is a winner
    if winner:
        text = font.render(f"{winner} wins!", True, black)
        screen.blit(text, [50, 150])

    # Update the display
    pygame.display.update()
