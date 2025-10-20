N = int(input())

names = [input() for _ in range(N)]
results = [int(input()) for _ in range(N)]

all = [(name, result) for name, result in zip(names, results)]

all.sort(key=lambda pair: pair[0])  # Since .sort is a stable sort, the same scores will come out as they were inputed
all.sort(key=lambda pair: pair[1], reverse=True)  # Meaning that 100 Ani will be before 100 Boris

for name, result in all:
    print(name, result)
