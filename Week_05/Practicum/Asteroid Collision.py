class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ans = []
        stack = []

        for asteroid in asteroids:
            if not stack and asteroid < 0:
                ans.append(asteroid)
                continue

            if not stack:
                stack.append(asteroid)
                continue

            if asteroid < 0 and stack:
                while stack and abs(stack[-1]) < abs(asteroid):
                    stack.pop()

                if stack and abs(stack[-1]) == abs(asteroid):
                    stack.pop()
                elif not stack:
                    ans.append(asteroid)

            else:
                if asteroid < 0:
                    ans.append(asteroid)
                else:
                    stack.append(asteroid)

        ans.extend(stack)
        return ans
