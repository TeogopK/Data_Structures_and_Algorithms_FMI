# https://www.hackerrank.com/contests/sda-hw-8/challenges/volleyball-friends/problem

m = int(input())
n = int(input())

team = {m}

for _ in range(n):
    friend, student = map(int, input().split())

    if friend in team:
        team.add(student)

print(len(team))
