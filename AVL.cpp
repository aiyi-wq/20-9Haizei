/*************************************************************************
	> File Name: AVL.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Sat 19 Dec 2020 03:49:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define L(n) (n ? l->child : NULL)
#define R(n) (n ? rchild : NULL)
#define H(n) (n->h)

typedef struct Node {
    int key, h;
    struct Node *lchild, rchild;
} Node;

//虚拟空节点
Node __NIL;
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0, NIL->h = 1;

}

Node *getNewNode(int key, ) {
    Node *p = (Node *)malloc(sizeof(Node)) ;
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->h = 1;
    return p;
}

void update_height(Node *root) {
    root->h = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root)));
}


Node *left_rotate(Nnode *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild  = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Nnode *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild  = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->lchild->h < root->lchild->rchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        
    }
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) {
        root->lchild = insert(root->lchild, key);
    } else {
        root->rchild = insert(root->rchild, key);
    }
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return NULL;
    if (key < root->key) {
        root->lchild = erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = key;
            root->h = 
        }
    }
    update_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("(%d[%d], %d, %d)\n", );
}

void output(Node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
}

int main() {
    int op, val; 
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = erase(root, val); break;
            case 1: root = insert(root, val); break;

        }
        ouput(root);
    }
    return 0;
}
