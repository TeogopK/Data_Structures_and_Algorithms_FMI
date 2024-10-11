// https://leetcode.com/problems/jewels-and-stones/description/?fbclid=IwZXh0bgNhZW0CMTEAAR3SN9AhD4-rjbWUJFrszohCxj-tnBVQYb3ZHs7vAIalUpurrw949b1NIgM_aem_TjgNybsvJMudsZwmdB7VFw

// O(n^2) solution
/* Logic:
 *  For each character in the jewels string, find the number of times the character appears in the stones string.
 */
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int numJewels = 0;

        for(int i = 0; i < jewels.length(); i++) {
            char jewel = jewels[i];

            for(int j = 0; j < stones.length(); j++) {
                numJewels += (jewel == stones[j]);
            }
        }

        return numJewels;
    }
};

// O(n) solution
/* Logic:
 *  We can use an array to store the jewels.
 *  For each character in the stones string, we can check if the character is a jewel in O(1) time.

 * This solution is better than the previous one because:
    1. It has a time complexity of O(n) instead of O(n^2).
    2. If the chars in jewels are not unique, the above solution will break.
 */
class Solution {
public:
    int convertLetterToNumber(char letter) {
        if(letter >= 'A' && letter <= 'Z'){
            return letter - 'A';
        }

        // We already have 26 uppercase letters, so we need an ofset of 26;
        return letter - 'a' + 26;
    }

    int numJewelsInStones(string jewels, string stones) {
        bool isJewelByLetter[26*2] = {false};
        
        for(int i = 0; i < jewels.length(); i++) {
            int letterToNumber = convertLetterToNumber(jewels[i]);

            isJewelByLetter[letterToNumber] = true;
        }

        int numJewels = 0;

        for(int i = 0; i < stones.length(); i++) {
            int letterToNumber = convertLetterToNumber(stones[i]);
            bool isJewel = isJewelByLetter[letterToNumber];

            if(isJewel){
                numJewels++;
            }
        }

        return numJewels;
    }
};