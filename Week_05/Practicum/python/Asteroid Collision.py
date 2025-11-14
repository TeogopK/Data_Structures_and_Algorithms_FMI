class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        output = []
        stack_ = []

        for asteroid in asteroids:
            if asteroid > 0:
                stack_.append(asteroid)

            else:
                while stack_ and stack_[-1] < abs(asteroid):
                    stack_.pop()

                if stack_ and stack_[-1] == abs(asteroid):
                    stack_.pop()

                elif len(stack_) == 0:
                    output.append(asteroid)

        return output + stack_
                    