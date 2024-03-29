#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void printTree(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        }
       

    }


}
Node* minVal(Node* root){
    Node* temp=root;
   while(temp->left != NULL){
       temp=temp->left;
   }
   return temp;
}
void inorderTraversal(Node* root){
    //base case
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
Node* insertinBST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data > root->data)
        root->right=insertinBST(root->right,data);
    if(data < root->data)
        root->left=insertinBST(root->left,data);
    return root;
}
Node* deleteFromBST(Node* root,int val){
    //base case
    if(root==NULL) return root;
    if(root->data==val){
        //0th child case
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }


        //One child case
    //left child case
    if(root->left != NULL && root->right == NULL){
        Node* temp = root->left;
        delete root;
        return temp;
    }
    //RIGHT CHILD CASE
    else if(root->right !=NULL && root->left == NULL){
        Node* temp=root->right;
        delete root;
        return temp;
    }


        //Two child case
    if(root->left != NULL && root->right != NULL){
        int mini=minVal(root->right)->data;
        root->data=mini;
        root->right=deleteFromBST(root->right,mini);
    }
    }









    }
    else if(root->data > val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data !=-1){
        insertinBST(root,data);
        cin>>data;
    }

}
int main(){
    Node* root=NULL;
    cout<<"Enter data to createwh BST Creating a Binary Search Tree for the good sake please stop!!!" << endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    printTree(root);
    cout<<"Printing the inorder Traversal" <<endl;
    inorderTraversal(root);
    deleteFromBST(root,9);
    cout<<"Printing the BST"<<endl;
    printTree(root);
    cout<<"Printing the inorder Traversal" <<endl;
    cout<<"HEy man why i amnot coding please tell me why is coding boring...i mean wtf man!!!"<<endl;
    return 0;
}