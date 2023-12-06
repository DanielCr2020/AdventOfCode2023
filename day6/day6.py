from functools import reduce

timesDistances=[(47, 400), (98, 1213), (66, 1011), (98, 1540)]
timesDistances2=[(47986698, 400121310111540)]

def findRange(x):
    ranges=0
    for i in range(x[0]):
        if (x[0]-i)*i > x[1]:
            ranges+=1
    return ranges

print(reduce(lambda x,y:x*y,map(findRange,timesDistances)),reduce(lambda x,y:x*y,map(findRange,timesDistances2)))