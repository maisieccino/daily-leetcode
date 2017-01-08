/**
 * BINARY TREE PREORDER TRAVERSAL (#144)
 * Runtime: 0 ms
 *
 * This one was rather simple to do. I use the classic
 * iterative algorithm to perform a preorder traversal
 * of a binary tree (node, left, right). however since
 * this is C, we have the joy of writing our own stack
 * and variable-length list, as seen below.
 *
 * To save on memory calls, I opt to have a statically-sized
 * array to represent the return array, which is of a size
 * sufficient for all test cases.
 */
int _STACK_SIZE = 128;

void stack_push(struct TreeNode** stack, int* ptr, struct TreeNode* val) {
    stack[++(* ptr)] = val;
}

void list_push(int* stack, int* ptr, int val) {
    stack[++(* ptr)] = val;
}

struct TreeNode* stack_pop(struct TreeNode** stack, int* ptr) {
    return stack[(* ptr)--];
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int* list = calloc(_STACK_SIZE, sizeof(int));
    int list_ptr = -1;
    struct TreeNode** stack[_STACK_SIZE];
    int stack_ptr = -1;
    
    stack_push(stack,&stack_ptr,root);
    
    while (stack_ptr >= 0) {
        root = stack_pop(stack, &stack_ptr);
        list_push(list, &list_ptr, root->val);
        (*returnSize)++;
        
        if (root->right != NULL) {
            stack_push(stack, &stack_ptr, root->right);
        }
        
        if (root->left != NULL) {
            stack_push(stack, &stack_ptr, root->left);
        }
    }
    return list;
}
