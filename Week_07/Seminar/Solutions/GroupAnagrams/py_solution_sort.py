from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)

        for word in strs:
            word_hash = ''.join(sorted(word))

            d[word_hash].append(word)
        
        return d.values()    
        