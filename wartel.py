if __name__ == "__main__": 
    N, Q = map(int, input().split())
    phoneBook = {}
    for _ in range(N):
        name, phonenumber = input().split()
        phoneBook[name] = phonenumber

    searchPhonenumber = []
    for _ in range(Q):
        query = input()
        if query in phoneBook: searchPhonenumber.append(phoneBook[query])
        else: searchPhonenumber.append("NIHIL")

    for phone in searchPhonenumber:
        print(phone)
