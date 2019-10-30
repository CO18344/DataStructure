class Stack:
	def __init__(self):
		self.data = []

	def push(self, key):
		self.data.append(key)

	def pop(self):
		try:
			return self.data.pop()
		except:
			print("Stack underflow")

	def peep(self):
		try:
			return self.data[len(self.data) - 1]
		except:
			print("Stack underflow")

	def isempty(self):
		return self.data == []

	def __str__(self):
		return str(self.data)

if __name__ == '__main__':
	s = Stack()
	s.push(23)
	s.push(32)
	print(s)
