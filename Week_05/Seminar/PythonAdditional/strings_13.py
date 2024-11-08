# https://github.com/telinc1/Introduction-To-Programming-Problems/blob/master/resources/tasks/strings.md
# Task 13

def is_in_order(items):
    for index in range(len(items) - 1):
        curr_item = items[index]
        next_item = items[index + 1]

        if curr_item > next_item:
            return False

    return True

def get_word_lengths(string):
    return [len(word) for word in string.split(" ")]

def reveal_password(books):
    password = []

    for row in books:
        if is_in_order(row):
            # With if statement
            if len(row) % 2 == 0:
                mid = len(row) // 2 - 1
            else:
                mid = len(row) // 2

            # With ternary operator
            # mid = len(row) // 2 - 1 if len(row) % 2 == 0 else len(row) // 2)

            password += get_word_lengths(row[mid])

    return password

books = [
    ["Algebra", "Analytic Geometry", "Calculus"],
    ["Databases", "Artificial Intelligence", "Functional Programming"],
    ["Data Structures and Algorithms", "Introduction to Programming", "Object-oriented Programming"],
]

print(reveal_password(books))
