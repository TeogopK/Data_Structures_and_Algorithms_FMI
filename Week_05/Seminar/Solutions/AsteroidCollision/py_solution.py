class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        d = []

        for el in asteroids:
            if el < 0:
                is_gone = False

                while not is_gone and d and d[-1] > 0:
                    if abs(el) > d[-1]:
                        d.pop()
                    elif abs(el) < d[-1]:
                        is_gone = True
                    else:
                        d.pop()
                        is_gone = True

                if not is_gone:
                    d.append(el)
            else:
                d.append(el)

        return d
