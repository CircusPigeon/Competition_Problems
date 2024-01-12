import sys

if __name__ == "__main__":
    lines = sys.stdin.readlines()

    l1 = lines[0]
    time = int(l1[(l1.find(" ")+1):])

    info, sol = [], []
    for x in lines[1:]:
        cash = int(x[:(x.find(" "))])
        mins = int(x[(x.find(" ")+1):])
        info.append((cash, mins))
    for t in range(time):
        sol.append(0)

    info.sort(key = lambda x : x[0], reverse = True)

    for person in info:
        i = person[1]
        while (i >= 0):
            if (sol[i] == 0):
                sol[i] = person[0]
                i = 0
            i -= 1

    totalCash = 0
    for cash in sol:
        totalCash += cash
    
    print(totalCash)