class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentsQ, sandwichesQ;
        for(auto s: students) {
            studentsQ.push(s);
        }
        for(auto s: sandwiches) {
            sandwichesQ.push(s);
        }
        
        while(true) {
            size_t preIterSize = studentsQ.size();
            
            for(size_t i = 0; i < preIterSize; i++) {
                if(studentsQ.front() == sandwichesQ.front()) {
                    studentsQ.pop();
                    sandwichesQ.pop();
                }
                else {
                    int curr = studentsQ.front();
                    studentsQ.pop();
                    studentsQ.push(curr);
                }
            }
            
            if(preIterSize == studentsQ.size()) {
                return studentsQ.size();
            }
        }
        
        return 0;
    }
};
