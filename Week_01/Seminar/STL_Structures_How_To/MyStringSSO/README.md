# Small string optimization - implementation from OOP 2022/2023

Idea if the length of the string is less than sizeof(pointer) + sizeof(length) => then use the allocated
bytes for the pointer and for the length to store the string. Otherwise allocate on the heap.