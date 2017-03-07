class Solution(object):
    def combinationSum(self, candidates, target):
        self.resList = []
        f1 = [0] * len(candidates)
        candidates = sorted(candidates)
        self.dfs(candidates, [], target, f1, 0)
        return self.resList

    def dfs(self, candidates, sublist, target, flaglist, last):
        if target == 0:
            self.resList.append(sublist[:])
        if target < candidates[0]:
            return
        l = None
        for m in range(len(candidates)):
            n = candidates[m]
            if n > target:
                return
            if n < last or flaglist[m] == 1 or l == 1:
                continue
            sublist.append(n)
            flaglist[m] = 1
            self.dfs(candidates, sublist, target - n, flaglist, n)
            flaglist[m] = 0
            l = n
            sublist.pop()
            #因为最后需要继续dfs所以要将上一次加入的元素重新弹出