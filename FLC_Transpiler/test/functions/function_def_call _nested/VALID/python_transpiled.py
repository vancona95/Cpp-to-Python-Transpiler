def Funzione2():
	print("Funzione 2 corretta")
	return 11
def Funzione1():
	print("Funzione 1 corretta")
	Funzione2()
	return 0
def Funzione3(x):
	print("Funzione 3 corretta")
	print(x)
	return x


def main():
	z = Funzione2()

	Funzione1()
	Funzione3(z)
	return 0

if __name__ == "__main__":
	main()
