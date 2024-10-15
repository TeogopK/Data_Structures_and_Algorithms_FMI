// https://leetcode.com/problems/permutation-difference-between-two-strings/description/?fbclid=IwZXh0bgNhZW0CMTEAAR0b8EZjz1lC0NZ9e1AwSoMI6Jpr6wsUSrJWxfa01O5Bs-TDEUrtOv4o28E_aem_5z9ppXTeEKw5scnwfDIMVg

// O(n^2) solution
/* Logic:
 *  For each character in the first string, find the index of the same character in the second string.
 *  Calculate the difference between the two indexes.
 *  We are using abs, because the difference can be negative.
 */
class Solution {
public:
    int findPermutationDifference(string firstString, string secondString) {
        int permutations = 0;

        for (int i = 0; i < firstString.length(); i++) {
            char searchedChar = firstString[i];

            for (int j = 0; j < secondString.length(); j++) {
                if (searchedChar == secondString[j]) {
                    permutations += abs(i - j);
                    break;
                }
            }
        }

        return permutations;
    }
};

// O(n) solution
/* Logic:
 *  We can use an array to store the indexes of the characters in the first string, because we know the number of characters is limited to 26.
 *  For each character in the second string, we can find the index of the same character in the first string in O(1) time.
 *  We can calculate the difference between the two indexes.
 */
class Solution {
public:
    int findPermutationDifference(string firstString, string secondString) {
        int positionsInFirstStringByLetters[26];

        for (int i = 0; i < firstString.length(); i++) {
            int letterToNumber = firstString[i] - 'a';

            positionsInFirstStringByLetters[letterToNumber] = i;
        }

        int permutations = 0;

        for (int i = 0; i < secondString.length(); i++) {
            int letterToNumber = secondString[i] - 'a';

            int positionInFirstString = positionsInFirstStringByLetters[letterToNumber];

            permutations += abs(positionInFirstString - i);
        }

        return permutations;
    }
};