input = [int(i) for i in open("input.txt", 'r').readline().split(",")]
fuelNum = []
possibleList = []
for i in range(max(input)):
    for j in range(len(input)):
        r = abs(input[j]-i)
        fuelNum.append(int(r*(r+1)/2))
    possibleList.append(sum(fuelNum))
    fuelNum = []
print(min(possibleList))




