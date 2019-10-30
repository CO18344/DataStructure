class queue:
	def __init__(self):
		self.data = []

	def isempty(self):
		return self.data == []

	def enqueue(self, key):
		self.data.append(key)

	def dequeue(self):
		try:
			self.data.pop(0)
		except:
			print("Queue is underflow")

	def __str__(self):
		return str(self.data)


if __name__ == '__main__':
	q = queue()
	q.enqueue(32)
	q.enqueue(89)
	print(q)
