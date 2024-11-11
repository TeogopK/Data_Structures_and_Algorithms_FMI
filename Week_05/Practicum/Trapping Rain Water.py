class Solution:
    def trap(self, height: List[int]) -> int:
        # We need the highest num on the left and a decreasing stack to keep 
        # The highest nums on the right

        stack_right = []
        for num in reversed(height):
            # Decreasing stack
            if not stack_right or num >= stack_right[-1]:
                stack_right.append(num)

        ans = 0
        highest_left = -1

        for hgh in height:
            if hgh >= highest_left:
                highest_left = hgh

            # Lol - the water that we can trap is the min of the difference between
            # our current height and the highest on the left or the right
            # the max is to avoid adding negative
            ans += max(min(highest_left - hgh, stack_right[-1] - hgh), 0)

            if hgh == stack_right[-1]:
                stack_right.pop()

        return ans
            
