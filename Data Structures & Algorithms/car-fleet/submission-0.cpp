class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p;
        for(int i = 0; i < position.size(); i++){
            p.push_back({position[i], speed[i]});
        }

        sort(p.rbegin(), p.rend());

        vector<double> stk;
        for(auto &p1 : p){
            stk.push_back((double)(target - p1.first)/p1.second);
            if(stk.size() >= 2 && stk.back() <= stk[stk.size() - 2]){
                stk.pop_back();
            }
        }
        return stk.size();
    }
};
