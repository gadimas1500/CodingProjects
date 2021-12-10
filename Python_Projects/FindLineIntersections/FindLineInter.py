import math
arr = []
graph = [[0 for _ in range(1000)] for _ in range(1000)]
line = []
for i in open('input.txt', 'r'):
    arr.append(i)

#GETS POINTS INTO LINE
for i in arr:
    num = str()
    number = []
    for char in list(i):
        if char.isnumeric():
            num += char
        elif char =="," or char == "-":
            number.append(int(num))
            num = str()
        elif char == "\n":
            number.append(int(num))
            line.append(number)


def showBoard():
    for row in range(len(graph)):
        for col in range(len(graph[row])):
            print(graph[row][col], end='')
        print()


def applyLine(ln):
    x1, y1, x2, y2 = ln[0], ln[1], ln[2], ln[3]
    #MAKE HORIZONTAL LINE
    if x1 == x2:
        if y2 > y1:
            for point in range(y1, y2+1):
                graph[x1][point] += 1
        else:
            for point in range(y2, y1+1):
                graph[x1][point] += 1
    #MAKE A VERTICAL LINE
    elif y1 == y2:
        if x2 > x1:
            for point in range(x1, x2+1):
                graph[point][y2] += 1
        else:
            for point in range(x2, x1+1):
                graph[point][y2] += 1
    #DIAGONALS
    elif ((y2 > y1) and (x2 < x1)) or ((y2 < y1) and x2 > x1):  #NEGATIVE SLOPE
        if (y2 > y1) and (x2 < x1): #DOWN AND TO THE LEFT
            slope = 0
            while x1-slope >= x2:
                graph[x1-slope][y1+slope] +=1
                slope+=1
        elif (y2 < y1) and (x2 > x1): #UP AND TO THE RIGHT
            slope = 0
            while x1+slope <= x2:
                graph[x1+slope][y1-slope] += 1
                slope +=1
    elif ((y2 < y1) and (x2 < x1)) or ((y2 > y1) and x2 > x1):  #POSITIVE SLOPE
        if (y2 < y1) and (x2 < x1):     #UP AND TO THE LEFT
            slope = 0
            while x1-slope >= x2:
                graph[x1-slope][y1-slope] += 1
                slope+=1
        elif (y2 > y1) and (x2 > x1):   #DOWN AND TO THE RIGHT
            slope = 0
            while x1+slope <= x2:
                graph[x1+slope][y1+slope] += 1
                slope+=1

#START OF THE PROGRAM
print(line)
for i in line:
    applyLine(i)
showBoard()


inters = 0
for i in range(len(graph)):
    for j in range(len(graph[i])):
        if graph[i][j] >= 2:
            inters += 1
print(f"Points with val gte 2: {inters}")