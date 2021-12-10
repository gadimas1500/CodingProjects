arr = []
tempArr = []
#charBoard = []
for i in open("input.txt", 'r'):
    tempArr.append(i[:-1])
print(tempArr)
for i in tempArr:
    arr.append([int(j) for j in i])
    #charBoard.append([j for j in i])

low = 0

def showBoard():
    #for i in charBoard:
     #   print(i)
    for i in arr:
        print(i)


def makeBasin(x, y):
    size = 0
    start = arr[x][y]
    if start == 0:
        arr[x][y]  =1
        size+=1
        if x > 0:
            size +=makeBasin(x-1, y)
        if x < len(arr)-1:
            size += makeBasin(x+1, y)
        if y > 0:
            size +=makeBasin(x, y-1)
        if y < len(arr[i])-1:
            size +=makeBasin(x, y+1)
    return size


for i in range(len(arr)):
    for j in range(len(arr[i])):
        currentPos = arr[i][j]

        if i == 0:
            if j == 0:  #TOP LEFT
                if arr[i][j+1] > currentPos and arr[i+1][j] > currentPos:
                    arr[i][j] = 0
            if j == len(arr[0])-1: #TOP RIGHT
                if arr[i+1][j] > currentPos and arr[i][j-1] > currentPos:    #TO DOWN
                    arr[i][j] = 0
            if 0 < j < len(arr[0])-1:   #TOP ROW
                if arr[i][j-1] > currentPos and arr[i][j+1] > currentPos and arr[i+1][j] > currentPos:    #to left
                    arr[i][j] = 0

        elif i == len(arr)-1:
            if j == 0:  #BOTTOM LEFT
                if arr[i-1][j] > currentPos and arr[i][j+1] > currentPos:    #up
                    arr[i][j] = 0

            if j == len(arr[i])-1:  #BOTTOM RIGHT
                if arr[i-1][j] > currentPos and arr[i][j-1] > currentPos:
                    arr[i][j] = 0

            if 0 < j < len(arr[i])-1:   #BOTTOM ROW
                if arr[i][j-1] > currentPos and arr[i][j+1] > currentPos and arr[i-1][j] > currentPos:
                    arr[i][j] = 0

        elif j == 0:  #LEFT SIDE
            if 0 < i < len(arr)-1:    #LEFT SIDE
                if arr[i-1][j] > currentPos and arr[i+1][j] > currentPos and arr[i][j+1] > currentPos:
                    low += currentPos+1
                    arr[i][j] = 0

        elif j == len(arr[i])-1:
            if 0 < i < len(arr[i])-1:   #RIGHT SIDE
                if arr[i-1][j] > currentPos and arr[i][j-1] > currentPos and arr[i+1][j] > currentPos:
                    low += currentPos+1
                    arr[i][j] = 0


        else:
            if arr[i - 1][j] > currentPos and arr[i + 1][j] > currentPos and arr[i][j - 1] > currentPos and arr[i][j+1] > currentPos:
                low += currentPos+1    #CHECKS A NUMBER IN THE (COL, ROW)
                #basins.append(makeBasin(i, j))
        if arr[i][j] != 9:
            arr[i][j] = 0

basins = []
for i in range(len(arr)):
    for j in range(len(arr[i])):
        basins.append(makeBasin(i, j))



showBoard()
#print(f"Lows: {low}")
print(f"Basins: {basins}")
nums = []
for i in range(3):
    print(f"Max #{i+1}: {max(basins)}")
    nums.append(max(basins))
    basins.remove(max(basins))
prod = 1
for i in nums:
    prod *=i
print(f"Product: {prod}")