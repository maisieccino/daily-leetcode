/**
 * Min Stack (#155)
 * Runtime: 25 ms (beats 45.45% of submissions)
 *
 * Solution uses two stacks, one that stores values in the array,
 * another that stores the min value at that point in time. This
 * means that we can easily evaluate the top value in the minStack
 * to find out the minimum value in the stack at any given time.
 * 
 * Therefore, push(), pop(), min() and top() are ALL O(1) time
 * complexity. Storage is O(n) complexity as size increases in a
 * linear fashion. However, because of the two read/writes happening
 * for each push/pop, the solution is a little slower than other C
 * implementations. Also, there's the risk of data inconsistency
 * since data is stored in two places.
 */
 typedef struct {
    int* stack;
    int stackPtr;
    int* minStack;
    int minStackPtr;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* ms = (MinStack*)calloc(1,sizeof(MinStack));
    ms->stack = (int*)calloc(maxSize, sizeof(int));
    ms->stackPtr = -1;
    ms->minStack = (int*)calloc(maxSize, sizeof(int));
    ms->minStackPtr = -1;
    return ms;
}

void minStackPush(MinStack* obj, int x) {
    obj->stack[++(obj->stackPtr)] = x;
    if (obj->minStackPtr >= 0) {
        if (obj->minStack[obj->minStackPtr] >= x) {
            obj->minStack[++(obj->minStackPtr)] = x;
        }
    }
    else {
        obj->minStack[++(obj->minStackPtr)] = x;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->stackPtr >= 0) {
        if (obj->stack[obj->stackPtr] == obj->minStack[obj->minStackPtr]) {
            (obj->minStackPtr)--;
        }
        (obj->stackPtr)--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->stackPtr >= 0) {
        return obj->stack[obj->stackPtr];
    }
    return NULL;
}

int minStackGetMin(MinStack* obj) {
    if (obj->minStackPtr >= 0) {
        return obj->minStack[obj->minStackPtr];
    }
    else return NULL;
}

void minStackFree(MinStack* obj) {
    free(obj->minStack);
    free(obj->stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
