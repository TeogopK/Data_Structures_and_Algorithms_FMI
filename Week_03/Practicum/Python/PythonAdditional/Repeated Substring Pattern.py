class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for num in range(1, (len(s) // 2) + 1):
            if len(s) % num != 0:
                continue

            subset_s = s[0 : num]
            num_found = 0
            for i in range(0, len(s), num):
                if s[i : i + num] == subset_s:
                    num_found += 1
                else:
                    break

            if num_found == len(s) / num:
                return True

        return False