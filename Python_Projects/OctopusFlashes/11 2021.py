arr = []
tempArr = []
for i in open("input.txt", 'r'):
    arr.append([int(j) for j in i[:-1]])
flash = 0


def showBoard():
    for i in arr:
        print(i)


def incrementAll():
    global flash
    for x in range(len(arr)):
        for j in range(len(arr[x])):
            if 0 <= arr[x][j] < 9:
                arr[x][j] += 1
            elif arr[x][j] == 9:
                arr[x][j] = -1
                flash += 1
                boundaryChecker(x, j)



def increment(x, y):
    global flash
    if 0 <= arr[x][y] < 9:
        arr[x][y] += 1
    elif arr[x][y] == 9:
        arr[x][y] = -1
        flash += 1
        boundaryChecker(x, y)



def resetZeros():  # RESETS ALL FLASHED VALUES TO ZERO
    for num in range(len(arr)):
        for j in range(len(arr[num])):
            if arr[num][j] < 0:
                arr[num][j] = 0


def checkAllFlash():
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] != 0:
                return False
    return True

def boundaryChecker(ex, wy):
    # CHECKER
    currentNum = arr[ex][wy]
    if ex == 0:
        if 0 < wy < len(arr[ex]) - 1:  # IN BETWEEN TOP ROW
            if currentNum < 0:
                increment(ex, wy - 1)  # TO LEFT
                increment(ex + 1, wy - 1)  # DOWN LEFT
                increment(ex + 1, wy)  # DOWN
                increment(ex + 1, wy + 1)  # DOWN RIGHT
                increment(ex, wy + 1)  # RIGHT

        if wy == 0:  # TOP LEFT CORNER
            if currentNum < 0:
                increment(ex + 1, wy)  # DOWN
                increment(ex + 1, wy + 1)  # DOWN RIGHT
                increment(ex, wy + 1)  # RIGHT
        if wy == len(arr[ex]) - 1:  # TOP RIGHT CORNER
            if currentNum < 0:
                increment(ex, wy - 1)  # left
                increment(ex + 1, wy - 1)  # down left
                increment(ex + 1, wy)  # down
    elif wy == 0:
        if 0 < ex < len(arr[ex]) - 1:  # IN BETWEEN LEFT SIDE
            if currentNum < 0:
                increment(ex + 1, wy)  # DOWN
                increment(ex + 1, wy + 1)  # DOWN RIGHT
                increment(ex, wy + 1)  # RIGHT
                increment(ex - 1, wy + 1)  # up right
                increment(ex - 1, wy)  # up
        if ex == len(arr) - 1:  # BOTTOM LEFT CORNER
            if currentNum < 0:
                increment(ex, wy + 1)  # RIGHT
                increment(ex - 1, wy + 1)  # up right
                increment(ex - 1, wy)  # up
    elif ex == len(arr) - 1:
        if 0 < wy < len(arr[ex]) - 1:  # BOTTOM IN BETWEEN
            if currentNum < 0:
                increment(ex, wy + 1)  # RIGHT
                increment(ex - 1, wy + 1)  # up right
                increment(ex - 1, wy)  # up
                increment(ex - 1, wy - 1)  # up left
                increment(ex, wy - 1)  # left
        if wy == len(arr[ex]) - 1:  # BOTTOM RIGHT CORNER
            if currentNum < 0:
                increment(ex - 1, wy)  # up
                increment(ex - 1, wy - 1)  # up left
                increment(ex, wy - 1)  # left
    elif wy == len(arr) - 1:
        if 0 < ex < len(arr) - 1:  # IN BETWEEN RIGHT SIDE
            if currentNum < 0:
                increment(ex + 1, wy)  # DOWN
                increment(ex + 1, wy - 1)  # DOWN LEFT
                increment(ex, wy - 1)  # left
                increment(ex - 1, wy - 1)  # up left
                increment(ex - 1, wy)  # up
    else:  # ALL BETWEENS
        if currentNum < 0:
            increment(ex + 1, wy)  # DOWN
            increment(ex + 1, wy - 1)  # DOWN LEFT
            increment(ex, wy - 1)  # left
            increment(ex - 1, wy - 1)  # up left
            increment(ex - 1, wy)  # up
            increment(ex - 1, wy + 1)  # up right
            increment(ex, wy + 1)  # RIGHT
            increment(ex + 1, wy + 1)  # DOWN RIGHT


# PART ONE
step = 100
r = 1
print(f"Before any Step:")
showBoard()
print()
goOn = True
while True:#for r in range(1, step + 1):
    incrementAll()  # STEP +=1 FOR ALL ELTS
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            #boundaryChecker(i, j)
            resetZeros()
            if checkAllFlash():
                t = r
                goOn = False
                break
        if not goOn:
            break
    r +=1
    print(f"After Step {r}")
    showBoard()
    print()
    if not goOn:
        break


print(f"\nFlashes: {flash}")
print(f"Simultaneous at: {t}")
