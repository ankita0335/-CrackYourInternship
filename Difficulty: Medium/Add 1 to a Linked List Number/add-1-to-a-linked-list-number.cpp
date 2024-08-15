//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    void add(Node*root,int&carry)
    {
        if(root->next==NULL)
        {
            if(root->data==9)
            {
                carry=1;
                root->data=0;
            }
            else{
                root->data=root->data+1;
            }
            return ;
        }
        add(root->next,carry);
        if(carry==1)
        {
            if(root->data+1>9)
            {
                root->data=0;
            }
            else{
                root->data=root->data+1;
                carry=0;
            }
        }
        return ;
    }
    
    Node* addOne(Node* head) {
        int carry;
        add(head,carry);
        if(head->data==0){
            Node*newhead=new Node(1);
            newhead->next=head;
            head=newhead;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends