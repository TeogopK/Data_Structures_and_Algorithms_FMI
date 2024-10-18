class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        n1_idx = m - 1
        n2_idx = n - 1
        r_idx = m + n - 1

        while n2_idx >= 0:
            if n1_idx >= 0 and nums1[n1_idx] > nums2[n2_idx]:
                nums1[r_idx] = nums1[n1_idx]
                n1_idx -= 1
            else:
                nums1[r_idx] = nums2[n2_idx]
                n2_idx -= 1

            r_idx -= 1