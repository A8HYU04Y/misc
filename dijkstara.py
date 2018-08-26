
import time
class Graph():
	unit=""
	def __init__(self):
		self.network=dict()
	def add_(self,fromLabel,toLabel,weight):
		if(fromLabel not in self.network and toLabel not in self.network):

			self.network[fromLabel]=dict()
			self.network[fromLabel][toLabel]=weight
			self.network[toLabel]=dict()
			self.network[toLabel][fromLabel]=weight
		elif(toLabel not in self.network and fromLabel in self.network):
			self.network[toLabel]=dict()
			self.network[toLabel][fromLabel]=weight
			self.network[fromLabel][toLabel]=weight
		elif(fromLabel not in self.network  and toLabel in self.network):
			self.network[fromLabel]=dict()
			self.network[fromLabel][toLabel]=weight
			self.network[toLabel][fromLabel]=weight
		elif(fromLabel not in self.network[toLabel] and toLabel not in self.network[fromLabel]):
			self.network[fromLabel][toLabel]=weight
			self.network[toLabel][fromLabel]=weight
		else:
			pass
	def show(self):
		for i in self.network:
			for j in self.network[i]:
				print(f"{i} connected to {j}({self.network[i][j]})")
	def add_edge(self,*args):
		for i in args:
			try:
				self.add_(i[0],i[1],i[2])
			except Exception as e:
				print("Incomplete Argument Error :: Incomplete Argument(s) passed")
				exit()	
	def Unit(self,u):
		self.unit=u
	def dijkstara(self,a,b):
		inf =10e100 ##inf
		Space=dict()
		strack=[]
		V=dict()
		V[a]=0
		for i in list(self.network.keys()):
			if i!=a:
				V[i]=inf
			else:
				continue
		Space[a]=0
		strack.append(a)
		while(b not in Space):
			for i in self.network[strack[-1]]:
				if i not in Space :
					V[i]=min(V[i],V[strack[-1]] + self.network[strack[-1]][i])
				else:
					continue
			del V[strack[-1]]
			for _ in V:
				if _ not in Space and V[_]==min(list(V.values())):
					Space[_]=V[_]
					strack.append(_)
					break
			else:
					continue
					
		return Space

	def shortcut(self,a,b):
		if a in self.network and b in self.network:
			s=self.dijkstara(a,b)
			if self.unit=="":
				return f"Shortest distance between {a} and {b} is of {s[b]} units..."
			else:
				return f"Shortest distance between {a} and {b} is of {s[b]} {self.unit}..."
		else:
			return f" Error :: Invailid Vertices"	

##Driver Function
if __name__ == '__main__':
	g=Graph()
	t1=time.time()

	g.add_edge(["A","B",2],["A","D",8],["A","C",4],["B","C",3], ## Kenneth H. Rosen Discrete Mathematics 7ed 8.6 QUE. 4
		       ["C","F",2],["C","E",2],["B","E",1],["D","F",5],
		       ["D","G",4],["G","F",3],["E","H",3],["F","H",3],
		       ["F","I",2],["F","J",4],["G","K",2],["H","L",1],
		       ["I","L",3],["I","J",3],["J","K",6],["K","N",4],
		       ["J","N",3],["J","M",6],["I","M",2],["H","O",8],
		       ["M","L",3],["L","O",6],["M","O",4],["N","M",5],
		       ["K","R",2],["N","R",1],["N","Q",2],["M","P",2],
		       ["O","P",2],["P","Q",1],["Q","R",8],["O","S",6],
		       ["R","T",5],["S","P",2],["P","T",1],["T","Q",3],
		       ["T","Z",8],["S","Z",2])
	
	print(g.shortcut("Z","A"))
	t2=time.time()
	print(t2-t1) ## time
															



