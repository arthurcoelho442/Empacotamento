#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* saida;//Arquivo de entrada para o sistema

    //Cria o arquivo de Saida
    saida = fopen("ED2_Trab3_results.txt", "w");

    fprintf(saida, "-------------------------------------------------------------------------------");
    fprintf(saida, "\n                           Number of disks");
    fprintf(saida, "\n\t\tWorst\tBest\tWorst-Fit\tBest-Fit\tRunning time");
    fprintf(saida, "\n\tN\tFit\tFit\tDecreasing\tDecreasing\t(seconds)");
    fprintf(saida, "\n-------------------------------------------------------------------------------");
    
    fclose(saida);    
    return (EXIT_SUCCESS);
}