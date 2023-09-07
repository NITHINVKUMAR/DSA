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
    string reorganizeString(string s) {

    // priority queue
    int freq[26] = {0};
    for (char ch : s) {
            freq[ch - 'a']++;
        }

    priority_queue<Node*,vector<Node*>,compare>maxHeap;
    for(int i = 0;i < 26;i++){
        if(freq[i] != 0){
           Node* temp = new Node(i + 'a', freq[i]);
            maxHeap.push(temp);
        }

    }
    string ans = "";
    while(maxHeap.size() > 1){
        Node* top1 = maxHeap.top();
        maxHeap.pop();
        Node* top2 = maxHeap.top();
        maxHeap.pop();
        ans += top1->data;
        ans += top2->data;
        top1->count--;
        top2->count--;
        if(top1->count > 0){
            maxHeap.push(top1);
        }
        if(top2->count > 0){
            maxHeap.push(top2);
        }

    }
    if(maxHeap.size()==1){
        Node* top = maxHeap.top();
        maxHeap.pop();
        if(top->count == 1){
            ans+=top->data;
        }
        else{
            return "";
        }
    }
    return ans;
    }
};



// brute
//     int hash[26] = {0};
    //   for(int i = 0;i < s.size();i++){
    //       hash[s[i] - 'a']++;
    //   }
    //   int maxi = INT_MIN;
    //   char max_freq_char;
    //   for(int i = 0;i < 26;i++){
    //       if(hash[i]>maxi){
    //           maxi = hash[i];
    //           max_freq_char = i + 'a';
    //       }
    //   }
    //   int index = 0;
    //   while(maxi >0 && index < s.length()){
    //       s[index] = max_freq_char;
    //       index += 2;
    //       maxi--;  
    //   }
    //   if(maxi != 0){
    //       return "";
    //   }
    // hash[max_freq_char - 'a'] =0;
    // for(int i = 0; i < 26;i++){
    //     while(hash[i]>0){
    //     index = index >= s.size()? 1 : index;
    //     s[index] = i+'a';
    //     hash[i]--;
    //     index = index +2; 
    //     }
    // }
    // return s;





