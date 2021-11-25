from typing import List, Tuple
import functools

a = list(map(int, input().split()))
b = list(map(int, input().split()))

n = len(a)
m = len(b)

maxl = 0
maxaa = []
maxbb = []

@functools.lru_cache(maxsize=10000000)
def dfs(i:int, j:int, aa:Tuple[int], bb:Tuple[int]):
	global maxl
	global maxaa
	global maxbb
	
#	print(aa, bb)
	laa = len(aa)
	if laa > 1 and laa == len(bb):
		if all(aa[i]-aa[i-1] == bb[i]-bb[i-1] for i in range(1, laa)):
#			print('found: ', aa, bb)
			if laa >= maxl:
				maxl = laa
				maxaa = aa
				maxbb = bb
	
	if i >= n and j >= m:
		return
	
	if i >= n:
		dfs(i, j+1, aa, bb)
		dfs(i, j+1, aa, bb+(b[j],))
		return
	
	if j >= m:
		dfs(i+1, j, aa, bb)
		dfs(i+1, j, aa+(a[i],), bb)
		return
	
	dfs(i+1, j+1, aa, bb)
	dfs(i+1, j+1, aa+(a[i],), bb)
	dfs(i+1, j+1, aa, bb+(b[j],))
	dfs(i+1, j+1, aa+(a[i],), bb+(b[j],))
	

dfs(0, 0, (), ())

print(maxl)
print(*maxaa)
print(*maxbb)