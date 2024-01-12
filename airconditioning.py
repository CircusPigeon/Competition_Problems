import sys

if __name__ == "__main__":
    lines = sys.stdin.readlines()

    intervals = []
    for x in lines[1:]:
        l = int(x[:(x.find(" "))])
        u = int(x[(x.find(" ")+1):])
        intervals.append((l, u))

    intervals.sort(key = lambda x : x[0])
    
    numRooms = 0
    while (len(intervals)):
        maxT, maxNum = 0, 0
        for x in range(intervals[-1][0], int(intervals[-1][1]) + 1):
            num = 0
            for i in range(len(intervals)):
                for y in range(intervals[i][0], int(intervals[i][1]) + 1):
                    if (x == y):
                        num += 1
            if (num > maxNum):
                maxNum = num
                maxT = x
        
        for i in reversed(range(len(intervals))):
            for x in range(intervals[i][0], int(intervals[i][1]) + 1):
                if (x == maxT):
                    intervals.remove(intervals[i])

        numRooms += 1
    
    print(numRooms)