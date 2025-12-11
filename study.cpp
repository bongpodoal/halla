#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TreeNode {
    char data;              
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

TreeNode* createNode(char data) {
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

TreeNode* buildTree(const char* arr, int index, int size) {
    TreeNode* root = NULL;

    if (index < size && arr[index] != '\0') {
        root = createNode(arr[index]);


        root->left = buildTree(arr, 2 * index + 1, size);
        root->right = buildTree(arr, 2 * index + 2, size);
    }
    return root;
}

int searchTree(TreeNode* node, char target, char* path, int depth) {
    if (node == NULL) return 0;

    if (node->data == target) {
        path[depth] = '\0'; 
        return 1; 
    }

    path[depth] = '.';
    if (searchTree(node->left, target, path, depth + 1)) {
        return 1;
    }

    path[depth] = '-';
    if (searchTree(node->right, target, path, depth + 1)) {
        return 1;
    }

    return 0; 
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    const char Data[] =
        " "                
        "ET"              
        "IANM"            
        "SURWDKGO"         
        "HVF L PJBXCYZQ  "  
        "54 3   2       16       7   8 90"; 

    int size = sizeof(Data) - 1;


    TreeNode* root = buildTree(Data, 0, size);

    char input[100];
    char result[20];

    printf("영어 문장이나 숫자를 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    printf("변환 결과: ");
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = toupper(input[i]);

        if (ch == ' ' || ch == '\n') {
            if (ch == ' ') printf("  ");
            continue;
        }

        if (searchTree(root, ch, result, 0)) {
            printf("%s ", result);
        }
    }
    printf("\n");

    freeTree(root);
    return 0;
}