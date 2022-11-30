

def main():
	x = 1
	y = 2
	z = 3
	b = True
	q = 1.1
	w = 2.2
	if x < y:
		print(" if first line ")
		print(x)
		if y < z:
			print(" if second line ")
			print(z)
		elif z < 4:
			print(" else if second line ")
			print(z)
		elif b == True:
			if q < w:
				print(" if third line ")
				print(x)
			else:
				print(" else third line ")
				print(x)
	else:
		print(" else first line")
	return 0

if __name__ == "__main__":
	main()
