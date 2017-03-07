class Solution(object):
    def isValid(self , s):
        if len(s) % 2 != 0
            return False
        map  = { ')':'(' , ']':'[' , '}':'{'}

        temp = [ ]
        for c in s:
            if c in map.values():
                temp.append(c)
            else:
                if not temp or temp.pop() != map[c]:
                    return False
        if temp:
            return False
        return True

        #在list中，pop(0)表示弹出的是第一个元素，而pop()弹出的是列表的最后一个元素
