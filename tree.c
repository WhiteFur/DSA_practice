#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int key;
  struct node *left;
  struct node *right;
}Node;

typedef Node *Tree;

Tree CreateTree(int x){
  Tree t = malloc(sizeof(Node));
  t->left = t->right = NULL;
  if(!t){
    printf("fatal error");
  }
  t->key = x;
  return t;
}

void MakeEmpty(Tree t){
  if(!t){
    return;
  }
  if(t->left){
    MakeEmpty(t->left);
  }
  if(t->right){
    MakeEmpty(t->right);
  }
  free(t);
}

Tree find(int x, Tree t){
  if(t){
    if(x < t->key){
      return find(x, t->left);
    }
    if(x > t->key){
      return find(x, t->right);
    }
  }
  return t;
}

Tree insert(int x, Tree t){
  if(!t){
    Tree node = malloc(sizeof(Node));
    node->key = x;
    node->left = node->right = NULL;
    return node;
  }
  if(x < t->key){
    t->left = insert(x, t->left);
  }
  if(x > t->key){
    t->right = insert(x, t->right);
  }
  return t;
}

Tree findMin(Tree t){
  if(t->left)
    return findMin(t->left);
  return t;
}

Tree delete(int x, Tree t){
  if(!t){
    return NULL;
  }

  if(x < t->key){
    t->left = delete(x, t->left);
  }
  else if(x > t->key){
    t->right = delete(x, t->right);
  }
  else if(t->left && t->right){
    t->key = findMin(t->right)->key;
    t->right = delete(t->key, t->right);
  }
  else{
    Tree temp = t;
    if(t->left){
      t = t->left;
    }
    else if(t->right){
      t = t->right;
    }
    else{
      free(temp);
      t = NULL;
    }
  }
  return t;
}


void postOrder(Tree t){
  if(t){
    postOrder(t->left);
    postOrder(t->right);
    printf(" %d ", t->key);
  }
}

int main(){

  Tree t = insert(10, NULL);
  t = insert(12, t);
  t = insert(18, t);
  t = insert(8, t);
  t = insert(9, t);
  t = delete(9, t);
  postOrder(t);
  printf("\n");

  Tree minNode = findMin(t);
  printf("min: %d", minNode->key);
  return 0;
}
