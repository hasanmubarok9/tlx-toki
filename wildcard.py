
def wildcard(word, pattern):
    # get the index of asterisk
    indexAsterisk = pattern.find("*")
    # get the prefix and sufix
    prefix = pattern[:indexAsterisk]; sufix = pattern[indexAsterisk+1:]

    # check if the word input is matched the prefix and sufix
    if len(word) >= (len(pattern) - 1): return word[:indexAsterisk] == prefix and word[len(word) - len(sufix):] == sufix
    else: return word[:indexAsterisk] == prefix and word[indexAsterisk:] == sufix

if __name__ == "__main__": 
    pattern = input()
    n = int(input())
    stringToMatch = []
    for i in range(n): stringToMatch.append(input())
    for word in stringToMatch:
        if wildcard(word, pattern):
            print(word)