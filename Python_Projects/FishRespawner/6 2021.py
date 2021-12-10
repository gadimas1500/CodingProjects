import copy
import math
arr = list()
for i in open('input.txt', 'r'):
    arr.append(i)

fishAge = []
for i in arr[0]:
    if i != ",":
        fishAge.append(int(i))
print(fishAge)

print(f"Initial num of fish: {len(fishAge)}")

fishDict = {0:0, 1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0, 8:0} #INITALIZES THE FIRST VALUES
fishKey = [i for i in fishDict.keys()]
fishVal = [i for i in fishDict.values()]
for i in fishAge:   #INITIALIZES THE LIST
    fishDict[i] = int(fishDict[i]) + 1  #ITERATES BY ONE

print(f"initial:{fishDict}")
initial = len(fishAge)
daysPass = 80
for i in range(daysPass):
    first = sum([i for i in fishDict.values()])
    print(f"First Sum: {first}")
    hold = copy.copy(int(fishDict[0]))  #HOLDER VALUE SO NO DATA IS LOST
    fishDict[0] = copy.copy(int(fishDict[1]))
    fishDict[1] = copy.copy(int(fishDict[2]))
    fishDict[2] = copy.copy(int(fishDict[3]))
    fishDict[3] = copy.copy(int(fishDict[4]))
    fishDict[4] = copy.copy(int(fishDict[5]))
    fishDict[5] = copy.copy(int(fishDict[6]))
    fishDict[6] = hold+copy.copy(int(fishDict[7]))  #RESTARTS PARENTS PLUS WHAT IS FROM SEVEN
    fishDict[7] = copy.copy(int(fishDict[8]))
    fishDict[8] = hold
    second = sum([i for i in fishDict.values()])
    floatFormat = "{:.4}".format(((second - first) / first) * 100)
    print(f"Second sum: {second}, Difference: {second - first}, {floatFormat}%")
    print()


sum = sum([i for i in fishDict.values()])   #SUMS UP ALL THE VALUES TO GET TOTAL FISH
print(f"output: {fishDict}")
print(f"Sum: {sum}")


#print(f"Total fish: {final}")
