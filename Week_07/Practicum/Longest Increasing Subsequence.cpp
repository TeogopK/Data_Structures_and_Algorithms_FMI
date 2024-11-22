class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }

        // The idea is to build the longest sequence and return the size;
        // Note 1: We don't care if the sequence has the correct numbers, just it size;
        // Note 2: The sequence need to be strictly increasing;
        vector<int> sequence;

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(!sequence.size() || sequence[sequence.size()-1] < x){
                // if the element is bigger that the last element (the current bugger)
                // It is a new element to our increasing sequence.
                // example:
                // x = 5 sequence = [1, 2, 4]
                // because the longest sequence is [1, 2, 4, 5]
                sequence.push_back(x);
                continue;
            }

            // Here we are in the case where x is not the biggest element
            // This means that the sequence can not increase in size
            // 
            // So logically we need to split the algorithm in two:
            // 1. Continue with the current sequence and only add elements, 
            //    in order to find the biggest sequence with the current elements
            // 2. Find the smaller elements than x and remove them, then add x and start the algorithm for the new sequence
            // 
            // Example:
            // we have the numbers [1, 2, 4, 5, 3, 4, 5]
            // in our sequence we have [1, 2, 4, 5] and x = 3
            //                              here we split the algorithm
            //                              /                         \       
            //  we continue with  [1, 2, 4, 5]             | we remove all elements >= 3 and add 3
            //  and find that we can not add more numbers  | we get [1, 2, 3] then we start the same algorithm recursively
            //  so the max sequence length is 4            | Here because all the numbers are bigger we will get [1, 2, 3, 4, 5]
            //                               \             | so the max sequence length is 5 
            //                                \           MAX          /
            //                                      The answer is 5
            //
            // But sadly this is SDA and not brute force (we are not barbarians, we are mages)
            // So let's do the above algorithm faster
            // To do this we will simultaneously do the left and the right part of the algorithm above
            // 
            // Let's examine the right part of the algorithm once again:
            // We remove all the elements that are >= 3, but what will happen if don't remove the other greater elements 
            // and just replace the element on the position that it is rightfully his (the first element that is >=)
            // So we will have this:
            // [1, 2, 4, 5] and x = 3 -> new sequence [1, 2, 3, 5]
            // Yes the sequence is not correct, but it has the max size that we are looking for. That is important.
            // 
            // Now whit this logic we are going to replace the 5 with 4 -> [1, 2, 3, 4]
            // And when the new 5 comes we will just go in the first if and get [1, 2, 3, 4, 5]. The answer.
            //
            // Now you may be wondering why is this working?
            // Ok... Let's see the cases (it is pissing me off to write more so please understand it, please):
            // 1. Only the last number and the length determined the previous sequence 
            //    so until we don't replace the last element we are saving the previous sequence
            // 2. If we replace the last element it means that
            //    * all previous elements are smaller than the new one
            //    * the old last element is bigger than the new one 
            //      - (we always want to have the smallest biggest element, because it is better!)
            //      - (we know that the last element is bigger than the new one because we would have added it to the end otherwise)
            //
            // If you didn't understand it. Read it again.
            // ...
            // Let the arcane magic be with me.

            *lower_bound(sequence.begin(), sequence.end(), x) = x;
        }

        return sequence.size();
    }
};