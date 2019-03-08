co:
	rm -rf ising.exe
	gcc -o ising.exe main.c ising.c generateNetwork.c networkDisplay.c degreeDistribution.c
cleardata:
	rm -rf data.txt ddx.txt ddy.txt network.net x.txt y.txt 