mylist = []
class login:
	def __init__(self, name):
		self.name = name
		mylist.append(self.name)
	def verify(self, name):
		for i in mylist:
			if name == i:
				print "welcome"+ " "+name
			else:
				print "you are unknown"

log = login("Ankit")	
log.verify("Pattu")			
