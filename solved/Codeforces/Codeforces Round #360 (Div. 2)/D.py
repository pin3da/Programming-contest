readLine = raw_input
readArgs = lambda : readLine().split()
readInts = lambda : map(int, readArgs())
readInt = lambda : readInts()

def read_int():
    while (True):
        n = readInt()
        if (len(n) > 0):
            return n[0]


def main():
    n = read_int(), k = read_int();




main()
