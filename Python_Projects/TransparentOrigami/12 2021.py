arr = []
tempArr = []
path = dict()
possiblePath = []
for i in open("input.txt", 'r'):
    arr.append([j for j in i[:-1].split("-")])


for i in range(len(arr)):
    if arr[i][0] not in path.keys():
        path[arr[i][0]] = [arr[i][1]]
    else:
        path[arr[i][0]].append(arr[i][1])


def printPath():
    for i in possiblePath:
        if len(i) > 0:
            print(i)
print(path)
print()

# PART ONE


def getPaths(oneKey):
    toRet = []
    if oneKey in path.keys():
        toRet.append(oneKey)
        toRet.append([i for i in getPaths(oneKey)])
    else:
        possiblePath.append(oneKey)
    return toRet


for key in path.keys():
    for i in path[key]:
        possiblePath.append([key, getPaths(i)])
printPath()