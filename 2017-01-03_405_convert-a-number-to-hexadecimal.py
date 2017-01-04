"""
CONVERT A NUMBER TO HEXADECIMAL (#405)
Runtime: 59 ms

Very simply, this algorithm converts the
number to its two's complement if less than
0, then the number is converted to a 32-bit 
binary string.

Finally, I use a dictionary to translate each
4-bit segment into its corresponding hex char.

Complexity? O(n) because of a lack of nested loops.
"""
class Solution(object):
    def toBin(self, num):
        if (num < 0):
            num = (num & 0xffffffff)
        output = ""
        for i in range(31,-1,-1):
            output += str((num >> i) & 1)
        return output
    
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        bin = self.toBin(num)
        output = ""
        hex = {
            '0000': '0',
            '0001': '1',
            '0010': '2',
            '0011': '3',
            '0100': '4',
            '0101': '5',
            '0110': '6',
            '0111': '7',
            '1000': '8',
            '1001': '9',
            '1010': 'a',
            '1011': 'b',
            '1100': 'c',
            '1101': 'd',
            '1110': 'e',
            '1111': 'f',
        }
        for i in range(8):
            c = hex[bin[(i*4):((i+1)*4)]]
            if not (output == "" and c == '0'):
                output += c
        if output == "":
            output = "0"
        return output
