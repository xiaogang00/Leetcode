class Solution(object):
    def search(self, nums, target):
        size = len(nums)
        first = 0
        last = size
        while first != last:
            mid = (first + last) /2
            if nums[mid] == target:
                return mid
            if nums[first] <= nums[mid]:
                if nums[first] <= target and target < nums[mid]:
                    last = mid
                else:
                    first = mid + 1

            else:
                if nums[mid] < target and target <= nums[last - 1]:
                  first = mid + 1
                else:
                  last = mid
        return -1
