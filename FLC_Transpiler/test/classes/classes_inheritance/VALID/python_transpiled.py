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


class Class10(Class1):
	def __init__(self):
		self.__k10 = k10
		self.x10 = 10
		self.y10 = "10"

class Class100(Class10):
	def __init__(self):
		self.__k100 = k100
		self.x100 = 100
		self.y100 = "100"



def main():
	obj1 = Class1
	obj10 = Class10
	obj100 = Class100
	obj1.x = 1
	obj1.y = "1"
	obj10.x10 = 11
	obj10.y10 = "11"
	obj10.x = 11
	obj10.y = "11"
	obj10.Funzione1(obj10)
	obj100.x100 = 110
	obj100.y100 = "110"
	obj100.x10 = 111
	obj100.y10 = "111"
	obj100.x = 1110
	obj100.y = "1110"
	obj100.Funzione1(obj100)
	return 0

if __name__ == "__main__":
	main()
