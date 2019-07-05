#pragma once

#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>

struct Node
{
  int value;
  Node* left, * right;

  Node(int value)
  {
    this->value = value;
    left = right = nullptr;
  }
};

void traversePreorder(Node* node)
{
  if (node == NULL)
    return;

  std::cout << node->value << " ";

  traversePreorder(node->left);
  traversePreorder(node->right);
}

void traverseInorder(Node* node)
{
  if (node == NULL)
    return;

  traverseInorder(node->left);

  std::cout << node->value << " ";

  traverseInorder(node->right);
}

void traversePostorder(Node* node)
{
  if (node == NULL)
    return;

  traversePostorder(node->left);
  traversePostorder(node->right);

  std::cout << node->value << " ";
}

void traverseTree()
{
  //             2
  //            / \
  //           3   5
  //          / \
  //         6   4

  struct Node* root = new Node(2);
  root->left = new Node(3);
  root->right = new Node(5);
  root->left->left = new Node(6);
  root->left->right = new Node(4);

  std::cout << "\nPreordine \n";
  traversePreorder(root);

  std::cout << "\nInordine\n";
  traverseInorder(root);

  std::cout << "\nPostordine\n";
  traversePostorder(root);
}
