import math
chosenNums = [91,17,64,45,8,13,47,19,52,68,63,76,82,44,28,56,37,2,78,48,32,58,72,53,9,85,77,89,36,22,49,86,51,99,6,92,80,87,7,25,31,66,84,4,98,67,46,61,59,79,0,3,38,27,23,95,20,35,14,30,26,33,42,93,12,57,11,54,50,75,90,41,88,96,40,81,24,94,18,39,70,34,21,55,5,29,71,83,1,60,74,69,10,62,43,73,97,65,15,16]
board = [[[0 for col in range(5)] for col in range(5)] for row in range(100)]
boolBoard = [[[False for col in range(5)] for col in range(5)] for row in range(100)]
file = open('input.txt', 'r').readlines()
editCard = [True for _ in range(len(board))]
print(chosenNums)
def getBoard(line):
    toRet = []
    for r in range(line):
        if file[r] == "\n":
            continue
        toSplit = file[r].split(" ")
        nums = []
        for i in toSplit:
            if i.isnumeric():
                nums.append(int(i))
            else:
                tempstr = []
                for j in i:
                    if j.isnumeric():
                        tempstr.append(j)
                nums.append("".join(tempstr))
        for _ in range(2):
            l = 0
            for i in nums:
                if i == '':
                    nums.remove(nums[l])
                elif isinstance(i, str):
                    nums[l] = int(nums[l])
                l += 1
        toRet.append(nums)
    return toRet

def evalBoard(num, brd=0, x=0, y=0):    #TAKES IN ONE BOARD EVALUATES IT
    #PARAMS num = chosen number, ind = board

    #APPLIES THE NUMBERS
    for brd in range(len(board)):
        for row in range(len(board[brd])):
            for col in range(len(board[brd][row])):
                if board[brd][row][col] == num and editCard[brd]:
                    boolBoard[brd][row][col] = True
               # else:
               #     boolBoard[brd][row][col] = False

def checkBoard(which=None):
    #CHECKS A SPECIFIC BOARD part two
    if which is not None:
        # CHECKS ROWS
        for row in range(len(boolBoard[which])):
            if all(boolBoard[which][row]):
                return [True, (which, row, None), board[which][row]]

        # CHECK COLUMNS
        for row in range(len(boolBoard[which])):
            tempCol = []
            winRow = []
            for col in range(len(boolBoard[which][row])):
                tempCol.append(boolBoard[which][col][row])
                winRow.append(board[which][col][row])
            if all(tempCol):
                return [True, (which, None, col), winRow]
    else:
        #CHECKS ROWS
        for brd in range(len(boolBoard)):
            for row in range(len(boolBoard[brd])):
                if all(boolBoard[brd][row]):
                    return [True, (brd, row, None), board[brd][row]]
        #CHECK COLUMNS
        for brd in range(len(boolBoard)):
            for row in range(len(boolBoard[brd])):
                tempCol = []
                winRow = []
                for col in range(len(boolBoard[brd][row])):
                    tempCol.append(boolBoard[brd][col][row])
                    winRow.append(board[brd][col][row])
                if all(tempCol):
                    return [True, (brd, None, col), winRow]
    return [False, (None, None, None)]

def getBoardSum(brd):
    sum = 0
    for row in range(len(board[brd])):
        for col in range(len(board[brd][row])):
            if not boolBoard[brd][row][col]:
                sum += board[brd][row][col]
    return sum

def showBoard(which=None):
    if which is None:
        for brd in range(len(board)):
            for row in range(len(board[0])):
                for col in range(len(board[row])):
                    if col%5==0:
                        print()
                    else:
                        print(f"{boolBoard[brd][row][col]}\t", end='')
            print()
    else:
        for row in range(len(board[0])):
            for col in range(len(boolBoard[which])):
                if col % 5 == 0:
                    print()
                else:
                    print(f"{boolBoard[which][row][col]}\t", end='')
        print()


#START OF THE PROGRAM
    #MAKES BOARD
line = getBoard(599)
q = 0
for brd in range(100):
    for row in range(5):
        for col in range(5):
            #START OF ONE LINE
            board[brd][row][col] = line[q][col]
        q+=1
#APPLIES AND EVALUATES BOARD
print(board)
winningBoards = dict() #[brd num] = last chosen num
picked = []
finalPick = 0   #THE MOST RECENT NUMBER CHOSEN
for i in chosenNums:
    picked.append(i)
    evalBoard(i)
    finalPick = i
    #NEXT LINE SHOULD BE WITHIN FOR LOOP FOR PART ONE
    for brd in range(len(board)):   #CHECKS EVERY SINGLE BOARD prt 2
        if checkBoard(which=brd)[0] and checkBoard(which=brd)[1][0] not in winningBoards.keys():   #PART ONE CHANGE WHICH TO NONE
            winningBoards[checkBoard(which=brd)[1][0]] = finalPick
            editCard[brd] = False
            #break #part one
'''
if checkBoard()[0]:#PART ONE
    print(f"There is a winner: {checkBoard()[1]}. Winning Values: {checkBoard()[2]}")
    for i in checkBoard()[2]:
        if i not in picked:
            print(f"Not all values were chosen --> {i} was not chosen")
    print("All values were chosen!")
    sum = getBoardSum(checkBoard()[1][0])
    print(f"Here is the sum of the FIRST winning board: {sum}")
    print(f"Here is the final answer: {sum*finalPick}")
else:
    print("No winner")
    print(boolBoard)
'''
if checkBoard()[0]:#PART TWO
    print("All values were chosen!")
    print(winningBoards)
    sum = getBoardSum(list(winningBoards)[-1])
    finalPick = list(winningBoards.values())[-1]
    print(f"Here is the LAST board that won: {list(winningBoards)[-1]}")
    print(f"Here is the sum of the LAST winning board: {sum}")
    print(f"Sum: {sum}, Final: {finalPick}")
    print(f"Here is the final answer: {sum*finalPick}")
else:
    print("No winner")
    print(boolBoard)






