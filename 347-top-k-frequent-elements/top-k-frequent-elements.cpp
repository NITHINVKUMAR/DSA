class Node{
    public:
    int data;
    int count;
    Node(int val,int freq){
        data = val;
        count = freq;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->count < b->count;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<Node*,vector<Node*>,compare>maxHeap;
        map<int,int>mp;
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            Node* temp = new Node(it.first,it.second);
            maxHeap.push(temp);
        }
        vector<int> ans;
    for (int i = 0; i < k; i++) { // Push the top k frequent elements
        Node* top = maxHeap.top();
        ans.push_back(top->data);
        maxHeap.pop();
    }
       return ans; 
    }
};