class Solution:
    def fill_arr(self, text):
        arr = []

        for el in text:
            if el != '#':
                arr.append(el) # O(1)
            elif arr:
                arr.pop()  # O(1)         
            
        return arr

    def backspaceCompare(self, s: str, t: str) -> bool:
        s_arr = self.fill_arr(s)
        t_arr = self.fill_arr(t)

        return s_arr == t_arr
            