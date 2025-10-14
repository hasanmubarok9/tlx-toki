def isPalindrom(str):
    return str == str[::-1]

def changeString(index, char, str):
    listStr = list(str)
    listStr[index] = char
    return "".join(listStr)

def breakPalindrome(palindromeStr):
    lowers = []
    # Write your code here
    for i in range(len(palindromeStr)-1, -1, -1):
        flag = ord(palindromeStr[i])
        while flag > 97:
            flag -= 1            
            lowers.append(changeString(i, chr(flag), palindromeStr))

    candidates = sorted([lower for lower in lowers if not isPalindrom(lower)]) 

    if(len(candidates) == 0):
        return "IMPOSSIBLE"

    return candidates[0]

# print(breakPalindrome("acca"))
# print(breakPalindrome("bab"))
# print(breakPalindrome("aaa"))
print(breakPalindrome("IMPOSSIBLE"))
print(breakPalindrome("aacdefghgfedcba"))