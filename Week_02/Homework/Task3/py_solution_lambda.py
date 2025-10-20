N = int(input())

names = [input() for _ in range(N)]
results = [int(input()) for _ in range(N)]

all = [(name, result) for name, result in zip(names, results)]

all.sort(key=lambda pair: (-pair[1], pair[0]))  # Adding minus to sort in reverse order
# all.sort(key = lambda pair: (pair[1], pair[0]), reverse=True) # Does not work

for name, result in all:
    print(name, result)
