import random

COUNT: int = 100
BIT_LEN: int = 1000


def main():
    for i in range(0, 10):
        for j in range(0, i):
            print(i, j)

    for i in range(0, COUNT):
        num1 = random.getrandbits(BIT_LEN)
        num2 = random.getrandbits(BIT_LEN)

        if num1 < num2:
            num1, num2 = num2, num1

        print("%d %d" % (num1, num2), end="\n")
    pass


main()