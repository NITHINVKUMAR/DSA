
class Node{
    public:
    int data;
    int row;
    int col;
    Node(int val,int r,int c){
        data = val;
        row = r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node* ,vector<Node*>,compare>pq;
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0;i < n;i++){
            pq.push(new Node(nums[i][0],i,0));
            mini = min(mini,nums[i][0]);
            maxi = max(maxi,nums[i][0]);
        }
        int start = mini;
        int end = maxi;
        while(!pq.empty()){
            Node* top = pq.top();
            int topdata = top->data;
            int toprow = top->row;
            int topcol = top->col;
            pq.pop();
            mini = topdata;
            int currRange = maxi - mini;
            int ansRange = end - start;
            if(currRange < ansRange){
                start = mini;
                end = maxi;
            }
            if(topcol + 1 < nums[toprow].size()){
                maxi = max(maxi,nums[toprow][topcol + 1]);
                Node* newNode = new Node(nums[toprow][topcol + 1],toprow,topcol+1);
                pq.push(newNode);
            }
            else{
                break;
            }
        }
        return {start,end};
    }
};