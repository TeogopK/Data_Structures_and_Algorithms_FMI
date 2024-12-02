class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> candies;
        for (int candy : candyType) {
            candies[candy]++;
        }

        return min(candyType.size() / 2, candies.size());
    }
};