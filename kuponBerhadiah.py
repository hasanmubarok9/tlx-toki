def kuponBerhadiah(x, coupons):
    distances= {}
    for c in coupons:
        distances[c] = abs(x - c)
    return min(distances, key=distances.get)

if __name__ == "__main__": 
    N, X = map(int, input().split())
    coupons = list(map(int, input().split()))
    print(kuponBerhadiah(X, coupons))