class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        
        res  = [0] * len(nums)                                 
        enum = list(enumerate(nums))
        
        self.mergeSort(enum, 0, len(nums) - 1, res)
        return res
    
    def mergeSort(self, enum, start, end, res):
        if start >= end: return
        
        mid = start + (end - start) // 2
        self.mergeSort(enum, start, mid, res)
        self.mergeSort(enum, mid + 1, end, res)
        self.merge(enum, start, mid, end, res)
    
    def merge(self, enum, start, mid, end, res):
        p, q = start, mid + 1
        inversion_count = 0
        temp = []
        
        while p <= mid and q <= end:
            if enum[p][1] <= enum[q][1]:
                temp.append(enum[p])
                res[enum[p][0]] += inversion_count
                p += 1
            else:
                temp.append(enum[q])
                inversion_count += 1
                q += 1
        
        while p <= mid:
            temp.append(enum[p])
            res[enum[p][0]] += inversion_count
            p += 1
        
        while q <= end:         
            temp.append(enum[q])
            q += 1
        
        enum[start:end+1] = temp 
        