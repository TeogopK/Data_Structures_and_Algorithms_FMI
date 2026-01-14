class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(auto& ticket: tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> result;
        stack<string> st;
        st.push("JFK");
        while(!st.empty()) {
            string current = st.top();
            if(!graph[current].empty()) {
                st.push(graph[current].top());
                graph[current].pop();
            }
            else {
                result.push_back(st.top());
                st.pop();
            }
        }


        reverse(result.begin(), result.end());
        return result;
    }
};
