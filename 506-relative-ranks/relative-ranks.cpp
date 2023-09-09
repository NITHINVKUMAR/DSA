class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int ,int>>maxheap;
        for(int i = 0;i < score.size();i++){
            maxheap.push({score[i],i});
        }
        vector<string>result(score.size());
        int times = 0;
           while (!maxheap.empty()) {
            int idx = maxheap.top().second;
            maxheap.pop();
            if (times == 0)          result[idx] = "Gold Medal";
            else if (times == 1)     result[idx] = "Silver Medal";
            else if (times == 2)     result[idx] = "Bronze Medal";
            else                     result[idx] = to_string(times + 1);
            times++;
        }
        return result;                           
    }
};