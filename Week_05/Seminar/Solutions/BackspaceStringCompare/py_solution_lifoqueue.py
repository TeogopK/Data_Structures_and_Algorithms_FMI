"""
NOT recommended!

The queue module implements multi-producer, multi-consumer queues.
It is especially useful in threaded programming when information must be exchanged safely between multiple threads.

Note: Lifo stands for Last In First Out.
"""

from queue import LifoQueue

class Solution:
    def fill_queue(self, text):
        q = LifoQueue()

        for el in text:
            if el != '#':
                q.put(el)
            elif not q.empty():
                q.get()             
            
        return q

    def backspaceCompare(self, s: str, t: str) -> bool:
        s_queue= self.fill_queue(s)
        t_queue= self.fill_queue(t)
        
        return s_queue.queue == t_queue.queue
            