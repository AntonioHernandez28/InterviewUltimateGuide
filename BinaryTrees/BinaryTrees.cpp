#include<iostream> 
#include<vector>
#include<stack>
#include<queue> 
using namespace std; 

struct TreeNode{
    int val; 
    TreeNode* Left; 
    TreeNode* Right; 
};

TreeNode* root = NULL; 

TreeNode* createNode(int n){
    TreeNode* nuevoNodo = new TreeNode();
    nuevoNodo -> val = n;
    nuevoNodo -> Left = NULL;
    nuevoNodo -> Right = NULL;
    
    return nuevoNodo;
}

void insertNode(TreeNode* &root, int val){
    if(root == NULL) root = createNode(val);
    else{
        if(val < root -> val) insertNode(root->Left, val); 
        else insertNode(root -> Right, val); 
    }
    
}

void MostrarArbol(TreeNode* root, int iContador) {
    if(root == NULL) return;
    else {
        MostrarArbol(root->Right, iContador + 1);
        for(int i = 0; i < iContador; i ++) cout << "  ";
        cout << root -> val << endl;
        MostrarArbol(root->Left, iContador + 1);
    }
}

void BFS(TreeNode* root){
    if(!root) return; 
    queue<TreeNode*> myS; 
    
    myS.push(root); 

    while(!myS.empty()){
        TreeNode* temp; 
        temp = myS.front(); 
        myS.pop(); 
        cout << temp -> val << " "; 
        if(temp -> Left) myS.push(temp -> Left); 
        if(temp -> Right) myS.push(temp -> Right);
    }
}


int main(){

    for(int i = 0; i < 9; i++){
        int temp;
        cin>>temp;
        insertNode(root, temp);
    }

    MostrarArbol(root, 0);
    BFS(root); 
}