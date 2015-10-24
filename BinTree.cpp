#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *parent, *left, *right;
    Node(int v = 0,Node *p = NULL, Node* l = NULL, Node* r = NULL ): data(v), parent(p), left(l), right(r){}
    Node* insertAsLC( const int &e){
        return left = new Node(e, this) ;
    }
    Node* insertAsRC(const int &e){
        return right = new Node(e, this);
    }
};

class Tree{
    protected:
        Node *root;
        int _size;
     public:
        Tree(Node *r = NULL, int s = 0): root(r), _size(s){}
        void buildTree(const vector<int> &L);
        void printTree();
};
//build a binary tree;
void Tree::buildTree(const std::vector<int> &L){

    if(L.empty())
        return ;

    std::queue<Node*> parentQueue;
    std::queue<Node*> childQueue;

    root = new Node(L[0]);

    parentQueue.push(root);

    std::size_t times = 1;
    while(times < L.size()){
        Node *parent = parentQueue.front();
        parentQueue.pop();
        
        parent->insertAsLC(L[times++]);
        childQueue.push(parent->left);
        
        if(times == L.size())
            break;

        parent->insertAsRC(L[times++]);
        childQueue.push(parent->right);
        
        if(parentQueue.empty()){
            parentQueue = childQueue;
            std::queue<Node*> empty;
            std::swap(childQueue, empty);
        }
       
    }
    
}

void Tree::printTree(){

    Node *node = root;
    std::queue<Node*> temp1;
    std::queue<Node*> temp2;

    temp1.push(node);

    while(!temp1.empty()){
        node = temp1.front();
        if(node->left != NULL)
            temp2.push(node->left);
        if(node->right != NULL)
            temp2.push(node->right);

        temp1.pop();

        std::cout << node->data << " ";
        if(temp1.empty()){
            std::cout << std::endl;
            temp1 = temp2;
            std::queue<Node*> empty;
            std::swap(temp2, empty);
        }
    }

}
/* 
//preorder traversal by recursion
void preTraversal1(Node *root){
    if(root == NULL)
        return;
    printf("%d", root->data);
    preTraversal1(root->left);
    preTreversal1(root->right);
}
//inorder traversal by resursion
void inTraversal1(Node *root){
    if(root == NULL)
        return;
    inTraversal1(root->left);
    printf("%d", root->data);
    inTraversal1(root->right);
}
//postorder traversal by recursion
void postTraversal1(Node *root){
    if(root == NULL)
        return;
    postTraversal1(root->left);
    postTraversal1(root->right);
    printf("%d", root->data);
}
*/

int main(){

    vector<int> v;
    for(int i = 0; i < 21; ++i)
        v.push_back(i + 1);
     
    Tree tree;
    tree.buildTree(v);
    tree.printTree();
   
    return 0;  

    
}
