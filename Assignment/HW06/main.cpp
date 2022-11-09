#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

#define MAX_STACK_SIZE 10009

using namespace std;

vector<string> arr;
vector<long long> num;
vector<char> expression;

typedef struct node {
  string data;
  struct node *leftChild, *rightChild;
} Node;

Node *createTreeNode(int);
Node *createTree(string [], int, int);

void inorder(Node*);
void preorder(Node*);
void postorder(Node*);

long long turnPostorder(long long, string*);

long long cal(string*);

int main(void) {
  cout.tie(0);
  cout.sync_with_stdio(false);

  int height, nums = 1;
  string stack[MAX_STACK_SIZE];
  string temp;
  string polynomial[MAX_STACK_SIZE];

  cin >> height;

  nums = pow(2, height) - 1;

  for (int i = 0; i < nums; i++) {
    cin >> temp;
    if (temp != "-1") {
      stack[i] = temp;
    } else {
      stack[i] = "j";
    }
  }

  Node* root = createTree(stack, 0, nums);


  postorder(root);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr.at(i) << " ";
  }
  cout << endl;

  long long operand1, operand2, result;
  char opr;
  for (int i = 0; i < arr.size(); i++) {
    if (arr.at(i) != "j") {
      if (arr.at(i) <= '9' && arr.at(i) >= '0') {
        num.push_back(arr.at(i) - '0');
      } 

      expression.push_back(arr.at(i));

      operand2 = num.pop_back()
      operand1 = num.pop_back()
      opr = expression.pop_back();
      
      switch (opr) {
      case '+' :
        result = operand1 + operand2;
        break;
      case '-' :
        result = operand1 - operand2;
      case '*' :
        result = operand1 * operand2;
      case '/' :
        result = operand1 / operand2;
      default:
        break;
      }

      num.push_back(result);
    }
  }

  cout << num.push_back() << endl;
  free(root);

  return 0;
}

Node *createTreeNode(string data) {
  Node *treeNode = (Node *) malloc(sizeof(Node));

  treeNode->data = data;
  treeNode->leftChild = NULL;
  treeNode->rightChild = NULL;

  return treeNode;
}

Node *createTree(string stack[], int index, int num) {
  Node *root = NULL;

  if (index < num) {
    root = createTreeNode(stack[index]);
    root->leftChild = createTree(stack, 2 * index + 1, num);
    root->rightChild = createTree(stack, 2 * index + 2, num);
  }

  return root;
}

void postorder(Node *ptr) {   /* postorder tree traversal */
  if (ptr) {
    postorder(ptr->leftChild);
    postorder(ptr->rightChild);
    // cout << ptr->data << " ";
    arr.push_back(ptr->data);
  }

  return;
}