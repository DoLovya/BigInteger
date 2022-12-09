import random

COUNT: int = 1000


def main():
    for i in range(0, 100):
        for j in range(0, 100):
            print(i, j)

    for i in range(0, COUNT):
        print("%d %d" % (random.getrandbits(1000), random.getrandbits(1000)),
              end="\n")
    pass


main()