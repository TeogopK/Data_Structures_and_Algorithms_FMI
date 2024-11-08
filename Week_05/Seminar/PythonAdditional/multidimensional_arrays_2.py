# https://github.com/telinc1/Introduction-To-Programming-Problems/blob/master/resources/tasks/multidimensional_arrays.md
# Task 2

rows, columns = map(int, input().split(" "))

matrix = []

for i in range(rows):
    row = list(map(int, input().split(" ")))
    matrix.append(row)

for row in matrix:
    for num in row:
        counter = 0
        if num < 0:
            counter += 1

    print(counter)
