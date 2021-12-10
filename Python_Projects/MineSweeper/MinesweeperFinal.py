import random

m = int(input("Enter Length: "))
n = int(input("Enter Width: "))
play = True
gameWon = False
bombPlaces = []
flagLocations = []
flagsUsed = 0
char = '*'
maxSpaces = int((m * n) / 2)
numBombs = 0
while (numBombs == 0) or (numBombs > maxSpaces):
   print("Enter amount of bombs (Max = ", maxSpaces, "): ", end='')
   numBombs = int(input())
   if numBombs > maxSpaces:
       print("Please choose a smaller number...")
   elif numBombs < 2:
       print("Please choose a larger number...")
   else:
       break

print("Total Bombs: ", numBombs)
grid = [[0] * n for _ in range(m)]
showGrid = [['#'] * n for _ in range(m)]
print("Row: ", len(grid), "\nCol: ", len(grid[0]))


def printGrid():  # PRINTS GRID TO THE SCREEN
   print('   ', end='')    # SHOWS USER GRID FOR THE FIRST TIME
   for x in range(n):
       print(x, ' ', end='')  # TOP NUMS
   print()
   for i in range(m):
       print(i, " ", end='')  # SIDE NUMS
       for r in range(n):
           print(grid[i][r], " ", end='')
       print()


def placeBombs():  # PUTS BOMBS TO THE GRID
   global bombPlaces
   repeat = [[0] * 2 for _ in range(numBombs)]
   global grid
   while True: #MAKES SURE THAT THERE ARE NO REPEATS IN THE RANDOM LIST SO THAT ALL BOMBS ARE USED
       rep = 0
       for i in range(0, numBombs):
           randRow = random.randint(0, m - 1)
           repeat[i][0] = randRow
       for r in range(numBombs):
           randCol = random.randint(0, n - 1)
           repeat[r][1] = randCol
       for item in repeat:
           if repeat.count(item) > 1:
               rep = 1
               break
       #print(repeat)
       if rep == 0:
           bombPlaces = repeat
           #print(bombPlaces)
           break
  # print(repeat)
   for i in range(len(repeat)):
       grid[repeat[i][0]][repeat[i][1]] = char


def bombChecker():  # ITERATES THE INDICES WITH A BOMB NEAR IT
   for i in range(m):
       for r in range(n):
           if (i != 0) and (r != 0) and (i != m - 1) and (r != n - 1) and (grid[i][r] != char):
               if grid[i][r + 1] == char:  # FOR NUMS NOT AT THE EDGE:
                   grid[i][r] += 1
               if grid[i][r - 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r] == char:
                   grid[i][r] += 1
               if grid[i - 1][r] == char:
                   grid[i][r] += 1
               if grid[i - 1][r - 1] == char:
                   grid[i][r] += 1
               if grid[i - 1][r + 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r - 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r + 1] == char:
                   grid[i][r] += 1


           elif (i == 0) and (r == 0) and (grid[i][r] != char):
               if grid[i][r + 1] == char:  # TOP LEFT CORNER
                   grid[i][r] += 1
               if grid[i + 1][r] == char:
                   grid[i][r] += 1
               if grid[i + 1][r + 1] == char:
                   grid[i][r] += 1
           elif (i == m - 1) and (r == 0) and (grid[i][r] != char):  # BOTTEM LEFT CORNER
               if grid[i - 1][r] == char:
                   grid[i][r] += 1
               if grid[i][r + 1] == char:
                   grid[i][r] += 1
               if grid[i - 1][r + 1] == char:
                   grid[i][r] += 1
           elif (i == 0) and (r == n - 1) and (grid[i][r] != char):  # TOP RIGHT CORNER
               if grid[i][r - 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r] == char:
                   grid[i][r] += 1
               if grid[i + 1][r - 1] == char:
                   grid[i][r] += 1
           elif (i == m - 1) and (r == n - 1) and (grid[i][r] != char):  # BOTTOM RIGHT CORNER
               if grid[i - 1][r] == char:
                   grid[i][r] += 1
               if grid[i][r - 1] == char:
                   grid[i][r] += 1
               if grid[i - 1][r - 1] == char:
                   grid[i][r] += 1
           elif (i != 0) and (i != m - 1) and (r == 0) and (grid[i][r] != char):  # LEFT SIDE
               if grid[i - 1][r] == char:
                   grid[i][r] += 1
               if grid[i][r + 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r] == char:
                   grid[i][r] += 1
               if grid[i - 1][r + 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r + 1] == char:
                   grid[i][r] += 1
           elif (i == 0) and (r != 0) and (r != n - 1) and (grid[i][r] != char):  # TOP SIDE
               if grid[i][r - 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r] == char:
                   grid[i][r] += 1
               if grid[i][r + 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r - 1] == char:
                   grid[i][r] += 1
               if grid[i + 1][r + 1] == char:
                   grid[i][r] += 1
           elif (i != 0) and (i != m - 1) and (r == n - 1) and (grid[i][r] != char):  # RIGHT SIDE
               if grid[i - 1][r] == char:  # up
                   grid[i][r] += 1
               if grid[i][r - 1] == char:  # left
                   grid[i][r] += 1
               if grid[i - 1][r - 1] == char:  # up left
                   grid[i][r] += 1
               if grid[i + 1][r - 1] == char:  # down left
                   grid[i][r] += 1
               if grid[i + 1][r] == char:  # down
                   grid[i][r] += 1
           elif (i == m - 1) and (r != 0) and (r != n - 1) and (grid[i][r] != char):  # BOTTOM SIDE
               if grid[i][r - 1] == char:  # left
                   grid[i][r] += 1
               if grid[i - 1][r] == char:  # up
                   grid[i][r] += 1
               if grid[i][r + 1] == char:  # right
                   grid[i][r] += 1
               if grid[i - 1][r - 1] == char:  # up left
                   grid[i][r] += 1
               if grid[i - 1][r + 1] == char:  # up right
                   grid[i][r] += 1
def playerGrid():       #THIS IS THE GRID THAT IS DISPLAYED TO THE PLAYER
    print("   ", end= '')
    for x in range(n):
       print(x, ' ', end='')  # TOP NUMS
    print()
    for i in range(m):
       print(i, " ", end='')  # SIDE NUMS
       for r in range(n):
           print(showGrid[i][r], " ", end='')
       print()
def playInfo(row, col, flag):
   global play
   global flagsUsed
   coord = [row, col]
   if (row >= m) or (col >= n):    #CHECKS THE INDEX VALUE input
       print("Index too high, try again...")
       return None
   if showGrid[row][col] == 'F':   #IF THE USER ALREADY ADDED A FLAG TO THIS INDEX
       print("You already flagged this space, try another...")
       return None
   if(showGrid[row][col] != '#' and showGrid[row][col] != 'F'):
       print("You already unconvered this space, try another...")
       return None
   if flag:
       showGrid[row][col] = 'F'    #F FOR FLAG
       flagsUsed += 1
       flagLocations.append(coord)

   else:
       showGrid[row][col] = grid[row][col]
   if(grid[row][col] == char and showGrid[row][col] != 'F' and not flag): #IF YOU CHOOSE A BOMB
       grid[row][col] = '+'
       printGrid()
       play = False
       printMoves(row, col)
       return None
   playerGrid()
   print("Flags Used: ", flagsUsed,'\nFlag Locations:', flagLocations, "\nBombs: ", numBombs)
def checkWinner():  #CHECKS IF YOU ARE A WINNER
   global play
   global gameWon
   global showGrid
   if (flagsUsed == numBombs) and play and (bombPlaces == flagLocations):  #IF FLAGS == BOMBS AND THEY ARE IN THE CORRECT LOCATIONS (WINNER)
       gameWon = True
       play = False
       winnerGrid()
   elif (flagsUsed == numBombs) and play and (bombPlaces != flagLocations): #LOSER
       gameWon = False
       play = False
       printGrid()
def winnerGrid(): #EDITS THE GRID FOR THE WINNER
   global grid
   for i in range(len(grid)):
       for r in range(len(grid[0])):
           if showGrid[i][r] == 'F' and (grid[i][r] == char):
               grid[i][r] = 'F*'
   printGrid()


def printMoves(row, col):   #PRINTS THE LIST OF ALL THE BOMBS AND THE ONE THE USER CHOSE
   print("\nBombs were at coordinate(s):")
   for i in bombPlaces:
       if(i[0] == row) and (i[1] == col):
           print(i, "<--- You Chose")
       else:
           print(i)


#MAIN
placeBombs()
bombChecker()
playerGrid()
while play:
   user = input("Enter coordinate (Row Col Flag?): ").split()
   temp = []
   badInput = False
   for num in user:
       temp.append(num)
   user = []
   for item in temp:
       if item.isnumeric():    #JUST SEPARATES THE NUMS INTO READABLE INTS
           user.append(int(item))
       elif item == 'f':
           user.append(item)
       else:
           print("I did not understand that input, please try again...")
           badInput = True
           break
   if badInput:
       continue

   user.append('q')
   row = user[0]
   col = user[1]
   flag = True if user[2] == 'f' else False
   playInfo(row, col, flag)
   checkWinner()
   print()
if gameWon:
   print("You won!!!!! :)")
elif not gameWon:
   print("You lost :(")


