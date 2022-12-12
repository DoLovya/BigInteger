import sys


def main():
    for line in sys.stdin:
        num_a = int(line.split(" ")[0])
        num_b = int(line.split(" ")[1])

        print(num_a - num_b)


if __name__ == "__main__":
    main()