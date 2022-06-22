#include <iostream>

using namespace std;

#define NUMBER 15

typedef struct node *nodePointer;
typedef struct node {
    int data;
    nodePointer left, right;
}node;

//전위
void preorder(nodePointer pointer) {
    if(pointer) {
        //pointer가 null이 아니라면
        cout << pointer -> data << ' ';
        preorder(pointer->left);
        preorder(pointer->right);
    }
}

// 중위
void inorder(nodePointer pointer) {
    if(pointer) {
    //pointer가 null이 아니라면
        inorder(pointer->left);
        cout << pointer -> data << ' ';
        inorder(pointer->right);
    }
}

// 후위
void postorder(nodePointer pointer) {
    if(pointer) {
        postorder(pointer->left);
        postorder(pointer->right);
        cout << pointer -> data << ' ';
    }
}


int main(void) {
    node nodes[NUMBER+1];
    for(int i = 1; i<=NUMBER; i++) {
        nodes[i].data = i;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }

    for(int i = 2; i<NUMBER; i++) {
        if(i%2 == 0) {
            nodes[i/2].left = &nodes[i];
        } else {
            nodes[i/2].right = &nodes[i];
        }
    }

    preorder(&nodes[1]);
    cout<<endl;
    inorder(&nodes[1]);
    cout<<endl;
    postorder(&nodes[1]);
    return 0;
}