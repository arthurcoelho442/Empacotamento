#Antes de executar o progama entre na pasta onde 
#o programa esta localizado.


compile:
	gcc -o trab3 *.c	
	
run:
	./trab3 $(arg)
	
compile-run:
	make compile
	make run
	
valgrind:
	make compile
	valgrind ./trab3 $(arg)

#Finalizado
