

# def min_Max(M):

# 	n = len(M)
# 	mM = []

# 	for i in range(n):

# 		# Minim de la fila i
# 		minim = min(M[i])

# 		# Maxim de la columna i
# 		columna = [M[j][i] for j in range(n)]
# 		columna = []
# 		for j in range(n):
# 			columna.append(M[j][i])
# 		maxim = max(columna)

# 		# Afegim la fila a la matriu final
# 		fila_mM = [minim, maxim]
# 		mM.append(fila_mM)

# 	return mM

# def main():
# 	print(min_Max([[1, 2, 3], [3, 1, 2], [2, 3, 1]]))

# main()

llista = [i*2 for i in range(5)]
print(llista)