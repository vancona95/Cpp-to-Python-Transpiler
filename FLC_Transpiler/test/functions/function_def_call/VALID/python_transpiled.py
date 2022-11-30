def Funzione1(x):
	print("Funzione 1 corretta")
	print(x)
	return x
def Funzione2():
	print("Funzione 2 corretta")
	return 0
def Funzione3(x, y, z):
	print("Funzione 1 corretta")
	print(x)
	print(y)
	print(z)
	return 0


def main():
	Funzione1(1)
	Funzione2()
	Funzione3(1, "2", True)
	return 0

if __name__ == "__main__":
	main()
