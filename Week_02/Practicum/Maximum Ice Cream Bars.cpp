class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;

        sort(costs.begin(), costs.end());

        for (int i = 0; i < costs.size(); i++) {
            coins -= costs[i];
            if (coins < 0)
                break;
            count++;
        }
        return count;
    }
};


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const long max = (int)10e5 + 1;
        long sortedCosts[max] = {0};

        for(long i = 0; i < costs.size(); i++) {
            sortedCosts[costs[i]] ++;
        }

        long count = 0;
        for(long i = 0; i < max; i++) {
            
            if(i>coins){
                break;
            }

            long br = sortedCosts[i];

            if(br*i > coins){
                count += coins/i;

                break;
            }
            
            coins -= br*i;
            count += br;
        }

        return count;
    }
};