# https://www.hackerrank.com/challenges/simple-array-sum/problem

N = int(input())
arr = [int(x) for x in input().split()]  # Using list comprehension
print(sum(arr))
