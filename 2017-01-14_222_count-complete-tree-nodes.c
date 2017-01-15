/**
 * COUNT COMPLETE TREE NODES (#222)
 * Passed 17/18 tests.
 * 
 * So what crime did I commit in this problem? Apparently my program
 * can't handle trees of up to 2^16 nodes (which is a ludicrous number
 * anyway). Apparently my solution works, although it could be a lot
 * simpler. I saw some very nice recursive solutions which I didn't think
 * to use. this one basically does DFS on the rightmost path as far as
 * possible, calculating the no. of elements up till then. Then, I use
 * a binary search across the breadth of the array until we reach the
 * jump between a leaf node present and one not present. However, when
 * you're running this on 2^15 elements, it's definitely gonna take a while.
 * Runtime for my algorithm is estimated at O(n log n), but apparently that's
 * still not good enough.
 */
 
// finds whether leaf node 'n' from right exists. returns boolean
// 1 if exists
// 0 if not
int leafNodeNExists(struct TreeNode* root, int height, int index) {
    if (index > (pow(2,height)-1))
        return 0;
    
    int* bits = calloc(height, sizeof(int));
    // printf("index: %i\n",index);
    // printf("height: %i\n",height);
    for (int i = 0; i < height; i++) {
        bits[i] = ((index >> (height-i-1)) & 1);
        // printf("  bit %i: %i\n", i, bits[i]);)
    }
    
    // printf("bits: [%i", *bits);
    // for (int i = 1; i < height; i++)
        // printf(",%i",bits[i]);
    // printf("]\n");
    
    bool res = 1;
    // printf("path: ");
    for (int i = 0; i < height; i++) {
        if (bits[i] == 0) {
            // printf("r");
            if (root->right == NULL) {
                // printf("-nope");
                res = 0;
                break;
            }
            root = root->right;
        }
        else {
            // printf("l");
            if (root->left == NULL) {
                // printf("-nope");
                res= 0;
                break;
            }
            root = root->left;
        }
    }
    // printf("\n");
    printf("pow(h:%i, i:%i) = %i\n",height,index,res);
    free(bits);
    return res;
}

int countNodes(struct TreeNode* root) {
    // consider only right hand branch until
    // we hit empty pointer. then explore
    // breadth (binary search style) until we reach empty node
    // at same level.
    // best case: O(log n)
    // worst case: O(n log n) ?
    
    if (root == NULL)
        return 0;
        
    if (root->left == NULL)
        return 1;
    
    int height = 1;
    int count = 1;
    
    struct TreeNode* ptr = root;
    while (ptr->right != NULL) {
        ptr = ptr->right;
        count += pow(2,height);
        height++;
    }
    printf("count: %i\n",count);
    printf("height: %i\n",height);
    
    // binary search along breadth of tree until we find last element.
    //easy way to do this, consider root->right = 0, root->left = 1.
    
    int low = 0;
    int high = pow(2,height)-1;
    int med;
    
    if (leafNodeNExists(root,height,0))
        return count + pow(2,height);
    
    int highest0 = 0;
    int lowest1 = high;
    
    if (leafNodeNExists(root,height,high)) {
        // if leftmost leaf exists
        while (highest0 != lowest1 - 1) {
            med = (highest0 + lowest1) / 2;
            int curr = leafNodeNExists(root,height,med);
            if (curr == 1) {
                lowest1 = med;
            }
            else if (curr == 0) {
                highest0 = med;
            }
        }
    }
    else {
        return count;
    }
    
    printf("highest0 %i\n",highest0);
    printf("lowest1 %i\n",lowest1);
    count += pow(2,height) - lowest1;
    // int max = pow(2,height+1);
    // printf("max: %i\n",max);
    // for (int i = max-1; i >= 0; i--) {
    //     if (leafNodeNExists(root,height,i)) {
    //         count++;
    //     }
    //     else {
    //         break;
    //     }
    // }
    
    return count;
}
