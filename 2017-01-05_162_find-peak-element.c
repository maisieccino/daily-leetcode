/**
 * FIND PEAK ELEMENT (#162)
 * Runtime: 3 ms (46.5% of submissions)
 * 
 * This rather simple algo uses a
 * binary search to find the element
 * where the next element is less than it.
 * Not really a lot more to say about it to
 * be honest, binary search is fast in most
 * cases and runs in O(log n) time. Nooo,
 * of course I didn't look at the spoiler...
 *
 * Yeah of course it runs faster than the Python
 * implementation. Python has overhead, it's
 * dynamically typed, and for these tests I
 * don't think it's even compiled to bytecode.
 */
int findPeakElement(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    
    int low = 0;
    int high = numsSize - 1;
    int mid = 0;
    
    while (low < high) {
        mid = (low + high) / 2;
        if (nums[mid] > nums[mid + 1])
            high = mid;
        else if (nums[mid] < nums[mid + 1])
            low = mid + 1;
    }
    return low;
}
