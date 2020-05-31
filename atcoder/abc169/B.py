def main():
	n = int(input())
	list1 = [int(t) for t in input().split()]
	list1.sort()
	ans = 1
	b = 0
	for i in range (0, n):
		ans = ans * list1[i]
		if int(ans) > int(1000000000000000000):
			print(-1)
			return
	print(ans)
	return

if __name__ == "__main__":
  #Run as main program
  main()