n = int(input())

a = input()
b = input()
c = input()

mp = [32] * 26

ok = True

for i in range(n):
    x = ord(a[i]) - ord('A')
    y = ord(b[i]) - ord('A')
    # mp[x] = y
    if (mp[x] != 32 and mp[x] != y):
        ok = False
        break
    mp[x] = y

if (not ok):
    print("Pak Dengklek bingung\n")
else:
    for ch in c:
        x = ord(ch) - ord('A')
        if (mp[x] == 32):
            print('?', end='')
            continue
        print(chr(mp[ord(ch) - ord('A')] + ord('A')), end='')
