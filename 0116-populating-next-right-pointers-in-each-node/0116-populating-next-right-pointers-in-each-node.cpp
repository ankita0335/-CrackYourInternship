/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        if(!root)   return NULL;
        while(!q.empty())
        {
            int n=q.size();
            if(n==0)
                return root;
            while(n--)
            {
                Node* node;
                if(n>0)
                {
                    node=q.front();
                    q.pop();
                    Node* nextt=q.front();
                    node->next=nextt;
                }
                else
                {
                    node=q.front();
                    q.pop();
                }
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
        }
        return root;
    }
};