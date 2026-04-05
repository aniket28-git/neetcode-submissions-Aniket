class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int,int>> stk;

        for(int i = 0; i < n; i++){
            int t = temperatures[i];
            while(!stk.empty() && t > stk.top().first){
                auto p = stk.top();
                stk.pop();
                res[p.second] = i - p.second;
            }
            stk.push({t, i});
        }

        return res;
    }
};
