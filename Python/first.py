#coding = utf-8#
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        start = 0
        maxlen = 0
        hashtable = [-1 for i in range(256)] #对256个元组的进行初始化，且初始化的值为-1
        for i in range(len(s)):
            if hashtable[ord(s[i])] != -1:  #ord函数返回字符的ASCII值
                while start <= hashtable[ord(s[i])]:
                    hashtable[ord(s[start])] = -1
                    start += 1
            if i - start + 1 > maxlen:
                maxlen = i - start + 1
            hashtable[ord(s[i])] = i
        return maxlen


if __name__ == '__main__':
    a = Solution()
    print a.lengthOfLongestSubstring("hell0")