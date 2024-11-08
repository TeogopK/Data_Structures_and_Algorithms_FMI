# https://github.com/telinc1/Introduction-To-Programming-Problems/blob/master/resources/tasks/multidimensional_arrays.md
# Task 1

def input_matrix_with_comprehension():
    return [int(x) for x in input().split(" ")]

def input_matrix_with_map():
    return list(map(int, input().split(" ")))

# rows, columns = [int(x) for x in input().split(" ")]
rows, columns = map(int, input().split(" "))

matrix = []

for i in range(rows):
    row = list(map(int, input().split(" ")))
    matrix.append(row)

# print(matrix)

for row in matrix:
    # print(row, min(row))
    print(min(row))
