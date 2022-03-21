#Antes de executar o progama entre na pasta onde 
#o programa esta localizado.
echo = echo

#para executar compile digite no terminal "make compile"
compile:
	gcc -o trab3 *.c	

#para executar run digite no terminal "make run arg=diretoriodo_arquivo"	
run:
	./trab3 $(arg)
	
#para executar compile-run digite no terminal "make compile-run arg=diretoriodo_arquivo"
compile-run: 
	make compile
	make run

#para executar compile-run-all digite no terminal "make compile-run-all"
compile-run-all:
	echo "-------------------------------------------------------------------------------" > ED2_Trab3_results.txt
	echo "                           Number of disks" >> ED2_Trab3_results.txt
	echo "\t\tWorst\tBest\tWorst-Fit\tBest-Fit\tRunning time" >> ED2_Trab3_results.txt
	echo "\tN\tFit\tFit\tDecreasing\tDecreasing\t(seconds)" >> ED2_Trab3_results.txt
	echo "-------------------------------------------------------------------------------" >> ED2_Trab3_results.txt
	make compile
	make run arg=in/5.txt
	make run arg=in/20.txt
	make run arg=in/100.txt
	make run arg=in/1000.txt
	make run arg=in/10000.txt
	make run arg=in/100000.txt
	echo "-------------------------------------------------------------------------------" >> ED2_Trab3_results.txt
	
	echo "(Challenge)" >> ED2_Trab3_results.txt
	gcc -o trab3 challenge/challenge.c disco.c
	make run arg=in/1000000.txt
	echo "-------------------------------------------------------------------------------" >> ED2_Trab3_results.txt
#para executar valgrind digite no terminal "make valgrind arg=diretoriodo_arquivo"
valgrind:
	make compile
	valgrind ./trab3 $(arg)
#para executar clear digite no terminal "make clear"
clean:
	#rm *.o
	rm trab3
	rm ED2_Trab3_results.txt
	clear
#Finalizado
