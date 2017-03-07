class Solution:
    def searchRange(self, nums, target):
        left = 0
        right = len(nums) - 1
        result = [-1, -1]

        while left <= right:
            mid = (left + right) / 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                result[0] = mid
                result[1] = mid
                i = mid - 1
                while i >= 0 and nums[i]==target:
                    result[0] = i
                    i -= 1
                i = mid + 1
                while i < len(nums) and nums[i]==target:
                    result[1] = i
                    i += 1
                break
        return result
