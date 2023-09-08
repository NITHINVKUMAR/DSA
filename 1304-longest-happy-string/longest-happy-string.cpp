
class Node{
    public:
    char data;
    int count;
    Node(char val,int freq){
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
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Node*,vector<Node*>,compare>maxHeap;
        if (a > 0) {
        Node* temp = new Node('a', a); 
        maxHeap.push(temp);
}
if (b > 0) {
    Node* temp = new Node('b', b);
    maxHeap.push(temp);
}
if (c > 0) {
    Node* temp = new Node('c', c);
    maxHeap.push(temp);
}
        string ans="";
        while(maxHeap.size() > 1){
        Node* top1 = maxHeap.top();
        maxHeap.pop();
        Node* top2 = maxHeap.top();
        maxHeap.pop();
        if(top1->count >= 2){
            ans+=top1->data;
            ans+=top1->data;
            top1->count -=2;
        }
        else{
            ans+=top1->data;
            top1->count--;
        }
        if(top2->count >= 2 && top2->count >= top1->count){
            ans+=top2->data;
            ans+=top2->data;
            top2->count -=2;
        }
        else{
            ans+=top2->data;
            top2->count--;
        }
        if(top1->count >0){
            maxHeap.push(top1);
        }
        if(top2->count > 0){
            maxHeap.push(top2);
        }
        }
        if(maxHeap.size() == 1){
            Node* top = maxHeap.top();
            maxHeap.pop();
            if(top->count >= 2){
            ans+=top->data;
            ans+=top->data;
            top->count -=2;
        }
        else{
            ans+=top->data;
            top->count--;
        }
        }
        return ans;
    }
};