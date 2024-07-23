#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int findMin(struct Node* root, int sum, int* min_diff) {
    if (!root) return 0;
    int left = findMin(root->left, sum, min_diff);
    int right = findMin(root->right, sum, min_diff);
    int total = root->data + left + right;
    int diff = abs(sum - 2 * total);
    if (diff < *min_diff) *min_diff = diff;
    return total;
}

int minValue(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int sum = 28, min_diff = INT_MAX;
    findMin(root, sum, &min_diff);
    printf("%d\n", min_diff);
    return 0;
}
