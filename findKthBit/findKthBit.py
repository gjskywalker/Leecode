class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        s = self.build_string(n)
        return s[k-1]

    def build_string(self, n: int) -> str:
        if n == 1:
            return "0"
        else :
            s = self.build_string(n-1) + "1" + self.reverse_string(self.invert(self.build_string(n-1)))
            return s

    def invert(self, s: str) -> str:
        in_s = ""
        for i in range(len(s)):
            if s[i] == '0':
                in_s += '1'
            else :
                in_s += '0'
        return in_s

    def reverse_string(self, s: str) -> str:
        return s[::-1]

if __name__ == "__main__":
    S = Solution()
    S.findKthBit(2, 1)