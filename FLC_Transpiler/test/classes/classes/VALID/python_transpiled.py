class Class1:
	def __init__(self):
		self.__k = k
		self.__v = v
		self.x = x
		self.y = y

	def __Funzione2(self):
		print("funzione in private")
		print(k)
		return k

	def Funzione1(self):
		w = 1
		print("funzione in public")
		print(w)
		return w


class Class2:
	def __init__(self):
		self.__b = True
		self.a = a

	def Funzione3(self, z):
		z = 3
		print("altra funzione in public")
		print(z)
		return z




def main():
	obj1 = Class1
	obj1.x = 1
	obj1.y = "1"
	obj1.Funzione1(obj1)
	obj2 = Class2
	obj2.a = False
	obj1.Funzione1(obj1)
	obj2.Funzione3(obj2, 10)
	return 0

if __name__ == "__main__":
	main()
