import math
arr = []
for i in open('input.txt', 'r'):
    arr.append(i)

def split(word):
    return [char for char in word]

def toDec(l):
    l = list(l)
    l.reverse()
    num = 0
    for i in range(len(l)):
        num += int((int(l[i]) * math.pow(2, i)))
    return num

def possible(l1, l2, min=0, max=0):
    #print("Possible Combos:")
    nothing = True
    if min==max:
        print(l1*l2)
        nothing = False
    if max > min:
        if min < l1*l2 < max:
            print(l1*l2)
            nothing = False
    if nothing:
        print(None)



commonGamma = []
one = 0
zero = 0
for char in range(12):
    for seq in arr:
        if seq[char] == '1':
            one += 1
        else:
            zero += 1
    if one >= zero:
        commonGamma.append(1)
    else:
        commonGamma.append(0)
    one = 0
    zero = 0

arr.reverse()
commonEp = []
one = 0
zero = 0
for char in range(12):
    for seq in arr:
        if seq[char] == '1':
            one += 1
        else:
            zero += 1
    if one <= zero:
        commonEp.append(1)
    else:
        commonEp.append(0)
    one = 0
    zero = 0
arr.reverse()   #REVERSE THE LIST BACK TO KEEP IT TRUE

#part2
print("GAMMA:")
print(f"Gamma: {commonGamma}")
discard = []
going = True
keep = []
for i in arr:
    keep.append(i[:-1])

tempKeep = []
finalBinStrGamma = str()
for i in range(12):
    for j in range(len(keep)):   #j is bin str in the overall list
        if commonGamma[i] == int(keep[j][i]) and keep[j] not in discard and keep[j] not in tempKeep:  #IF YOU'RE A GOOD NUMBER AND HAVEN'T BEEN DISCARDED AND YOU AREN'T IN THE LIST YET
            tempKeep.append(keep[j])    #ADDS TO A TEMPORARY LIST TO REPLACE IT
        elif commonGamma[i] != int(keep[j][i]):  #IF YOU'RE NOT A GOOD NUMBER
            discard.append(keep[j])  # YOU ARE DISCARDED
            if keep[j] in tempKeep:   #IF YOU WERE GOOD BEFORE YOU ARE NOW REMOVED FROM THE GOOD PILE
                if len(tempKeep) == 300:
                    finalBinStrGamma = [i for i in tempKeep]#keep[j]
               # print(f"tempKeep(at{i}should {commonGamma[i]}): {tempKeep} Removing: {keep[j]}")
                tempKeep.remove(keep[j])  #removes elt because it's no good
            #print(f"{j} was removed bc '{commonGamma[i]}' is not in the '{i+1}'  pos ->{commonGamma}, i = {i}, Gamma: {commonGamma[i]}, Bin = {j[i]}")
        else:   #IF YOU ARE A GOOD NUMBER AND YOU ARE STILL A GOOD NUMBER
            pass

#print(f"Keep: {keep}")
#print(toDec(keep))
#print(f"Discard: {discard}")
#print(f"Len of keep: {len(keep)}")
#print(f"Len of discard: {len(set(discard))}")
print(f"Last good bin Str: {finalBinStrGamma}")
print(f"Gamma: {commonGamma}")
#UPDATES KEEP
keep = []
for i in tempKeep:
    keep.append(i)
#print(f"New keep list: {keep}\nNew keep len: {len(keep)}")

print()


print("EPSILON:")
print(f"Epsilon: {commonEp}")
discard = []
going = True
keep = []
for i in arr:
    keep.append(i[:-1])

tempKeep = []
finalBinStrEp = str()
for i in range(12):
    for j in range(len(keep)):   #j is bin str in the overall list
        if commonEp[i] == int(keep[j][i]) and keep[j] not in discard and keep[j] not in tempKeep:  #IF YOU'RE A GOOD NUMBER AND HAVEN'T BEEN DISCARDED AND YOU AREN'T IN THE LIST YET
            tempKeep.append(keep[j])    #ADDS TO A TEMPORARY LIST TO REPLACE IT
        elif commonEp[i] != int(keep[j][i]):  #IF YOU'RE NOT A GOOD NUMBER
            discard.append(keep[j])  # YOU ARE DISCARDED
            if keep[j] in tempKeep:   #IF YOU WERE GOOD BEFORE YOU ARE NOW REMOVED FROM THE GOOD PILE
                if len(tempKeep) == 300:
                    finalBinStrEp = [i for i in tempKeep]#keep[j]
               # print(f"tempKeep(at{i}should {commonEp[i]}): {tempKeep} Removing: {keep[j]}")
                tempKeep.remove(keep[j])  #removes elt because it's no good
            #print(f"{j} was removed bc '{commonGamma[i]}' is not in the '{i+1}'  pos ->{commonGamma}, i = {i}, Gamma: {commonGamma[i]}, Bin = {j[i]}")
        else:   #IF YOU ARE A GOOD NUMBER AND YOU ARE STILL A GOOD NUMBER
            pass

print(f"Gamma: {commonGamma}")
print(f"Epsilon: {commonEp}")
#print(f"Keep: {keep}")
#print(toDec(keep))
#print(f"Discard: {discard}")
#print(f"Len of keep: {len(keep)}")
#print(f"Len of discard: {len(set(discard))}")
print(f"Last good bin Str: {finalBinStrEp}")
#UPDATES KEEP
keep = []
for i in tempKeep:
    keep.append(i)
#print(f"New keep list: {keep}\nNew keep len: {len(keep)}")



print()
print(f"Gamma: {finalBinStrGamma}")
print(f"Epsilon: {finalBinStrEp}")
print()

for i in range(300):
    possible(toDec(finalBinStrGamma[i]), toDec(finalBinStrEp[i]), 2928640, 3072483)

