class Solution {
public:
class compare{
    public:
    bool operator()(pair<int,int>a,pair<int ,int>b){
        int distA = a.first*a.first + a.second*a.second;
        int distB = b.first*b.first + b.second*b.second;
        return distA > distB;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>minHeap;
        for(int i = 0;i<points.size();i++){
            minHeap.push({points[i][0],points[i][1]});
        }
        while(!minHeap.empty() && k--){
            auto& top = minHeap.top();
            ans.push_back({top.first, top.second});
            minHeap.pop();
        }
        return ans;
    }
};