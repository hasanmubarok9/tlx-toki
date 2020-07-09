def fpb(A, B):
  if(B == 0): return A 
  return fpb(B , A % B) 

if __name__ == "__main__": 
  A, B = map(int, input().split())
  print(fpb(A, B))