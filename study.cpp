#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
TreeNode* createNode(int data) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (!newNode) {
		printf("메모리 할당 오류\n");
		exit(1);
	}
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
TreeNode* insertNode(TreeNode* node, int data)
{
	if (node == NULL) {
		return createNode(data);
	}

	if (data < node->data) {
		node->left = insertNode(node->left, data);
	}

	else if (data > node->data) {
		node->right = insertNode(node->right, data);
	}
	return node;
}

void inorderTraversal(TreeNode* root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}

void freeTree(TreeNode* root) {
	if (root != NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}
int main()
{
	TreeNode* root = NULL;
	int inputData;
	
	printf("정수 10개를 입력하세요 : \n");
	
	for (int i = 0; i < 10; i++) {
		printf("%d번째 숫자: ", i + 1);
		scanf_s("%d", &inputData);
		root = insertNode(root, inputData);
	}

	printf("생성된 트리 중위 순회 결과 : \n");
	inorderTraversal(root);
	printf("\n");


}