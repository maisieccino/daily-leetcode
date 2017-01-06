"""
FIND PEAK ELEMENT (#162)
Runtime: 49 ms

This rather simple algo uses a
binary search to find the element
where the next element is less than it.
Not really a lot more to say about it to
be honest, binary search is fast in most
cases and runs in O(log n) time. Nooo,
of course I didn't look at the spoiler...
"""
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 0:
            return 0
        low = 0
        high = len(nums)-1
        mid = 0
        
        while (low < high):
            mid = (low + high) // 2
            if (nums[mid] > nums[mid + 1]):
                high = mid
            elif (nums[mid] < nums[mid + 1]):
                low = mid + 1
        return low
