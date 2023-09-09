class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int>ans;
      priority_queue<pair<int ,int>>maxHeap;
      for(int i = 0;i < k;i++){
          maxHeap.push({nums[i],i});
      }  
    ans.push_back(maxHeap.top().first);
    for(int i = k;i < nums.size();i++){
        maxHeap.push({nums[i],i});
        while(maxHeap.top().second <= i - k){
            maxHeap.pop();
        }
        ans.push_back(maxHeap.top().first); 
    }
    return ans;
    }
};