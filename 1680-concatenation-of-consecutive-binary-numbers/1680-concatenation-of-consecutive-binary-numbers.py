class Solution:
    def concatenatedBinary(self, n: int) -> int:
        return reduce(lambda s, i: (s << i.bit_length() | i) % 1000000007, range(1, n+1))