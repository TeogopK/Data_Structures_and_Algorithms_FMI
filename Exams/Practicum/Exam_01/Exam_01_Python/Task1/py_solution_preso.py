n = int(input())

lst = []

for _ in range(n):
    name, height = input().split()
    lst.append((name, height))

swap1, swap2 = input().split()

lst.sort(key=lambda x: x[1])

out = [x[0] for x in lst]

i1, i2 = out.index(swap1), out.index(swap2)

out[i1], out[i2] = out[i2], out[i1]

print("\n".join(out))
