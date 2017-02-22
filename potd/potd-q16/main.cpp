#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

void printList(node *head) {
  // printList function
  node *curr = head;
  int i = 0;
  if (curr == NULL) {
      cout << "Empty list" << endl;
      return;
  }
  while (curr != NULL){
      cout << "Node " << i << ": " << curr->val << endl;
      i++;
      curr = curr->next;
  }
}

int main() {
  // Test 1: An empty list
  node * head = NULL;
  printList(head);

  // Test 2: A list with exactly one node
  node * a = new node;
  a->val = 100;
  a->next = NULL;
  printList(a);

  // Test 3: A list with more than one node
  node * b = new node;
  a->next = b;
  b->val = 200;
  b->next = NULL;

  node * c = new node;
  b->next = c;
  c->val = 300;
  c->next = NULL;
  printList(a);

  delete a;
  delete b;
  delete c;
  a = NULL;
  b = NULL;
  c = NULL;
  return 0;
}
