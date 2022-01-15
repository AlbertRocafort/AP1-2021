
# from easyinput import read
import turtle


def dibuixa_cercle(n, d):

	for i in range(4):

		# Pintem un quart de cercle
		turtle.circle(d, 90)

		# Comprovem si queden nivells per pintar
		if n > 1:

			# Coloquem el turtle be pq pinti el cercle petit en el canto que toca
			turtle.left(180)

			# Pintem el cercle petit
			dibuixa_cercle(n-1, d/2)

			# Un cop acabada la crida recursiva, el turtle estara mirant cap a la direccio contraria
			# L'hem de recolocar
			turtle.left(180)




def main():

	# n, d = read(int, int)

	s = turtle.getScreen()
	# t = turtle.Turtle()

	dibuixa_cercle(2, 50)

main()