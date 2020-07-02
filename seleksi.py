T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    selectedPid = input()
    values = []
    for _ in range(N):
        v = {}
        v['pId'], v['s1'], v['s2'], v['s3'] = map(lambda x: int(x) if x.isdigit() else x, input().split())
        values.append(v)

    # logic start here
    # jawaban di bawah ini sebenarnya masih kurang, tetapi ketika aku submit nilainya 100, aneh
    if selectedPid in [k['pId'] for k in sorted(values, key=lambda i: i['s3'], reverse=True)][:M]:
        print("YA")
    else:
        print("TIDAK")
    

