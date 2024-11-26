class Solution:
    def get_hash(self, word):
        counts = [0] * 26

        for ch in word:
            counts[ord(ch) - ord('a')] += 1
        
        return tuple(counts)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)

        for word in strs:
            word_hash = self.get_hash(word)

            d[word_hash].append(word)
        
        return d.values()
    