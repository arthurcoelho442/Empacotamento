#Antes de executar o progama entre na pasta onde 
#o programa esta localizado.


compile:
	gcc -o trab3 *.c	
	
run:
	./trab3 $(arg)
	
compile-run:
	make compile
	make run
	
compile-run-all:
	gcc -o trab3 print-all/cabecario.c
	./trab3
	
	make compile
	
	make run arg=in/5.txt
	make run arg=in/20.txt
	make run arg=in/100.txt
	make run arg=in/1000.txt
	make run arg=in/10000.txt
	make run arg=in/100000.txt
	
	gcc -o trab3 print-all/challenge.c disco.c
	make run arg=in/1000000.txt
	
valgrind:
	make compile
	valgrind ./trab3 $(arg)

#Finalizado
