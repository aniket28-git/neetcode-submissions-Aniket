class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int,int>> st;
        int n = heights.size();

        for(int i = 0; i < n; i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                pair<int,int> tp = st.top();
                int index = tp.first;
                int height = tp.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                st.pop();
            }

            st.push({start, heights[i]});
        }

        while(!st.empty()){
            int index = st.top().first;
            int height = st.top().second;
            maxArea = max(maxArea, height * (static_cast<int>(n) - index));
            st.pop();
        }

        return maxArea;
    }
};
