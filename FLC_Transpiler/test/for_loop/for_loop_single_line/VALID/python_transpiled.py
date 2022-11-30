

def main():
	str = "stringa"
	for x in range(0, 10, 1):
		print("for loop 1 correct")
	for x in range(10, 0, -1):
		print("for loop 2 correct")
	for x in range(10, 0, -1):
		print("for loop 3 correct with X = X -1")
		print(str)
	return 0

if __name__ == "__main__":
	main()
