/*
 * main.c
 *
 *  Created on: May 24, 2017
 *      Author: Fernando
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define bool  int

// Parametrização do código ("regras de negócio")

#define MAX_NUMERO_NOTAS          12
#define MIN_COMPRIMENTO_NOME       3
#define MAX_COMPRIMENTO_NOME      20
#define MIN_NUMERO_ALUNO         1
#define MAX_NUMERO_ALUNO        1999
#define NOTA_MINIMA				0.0
#define NOTA_MAXIMA				10.0
#define NOTA_MINIMA_APROVACAO			6.0

#include "aluno.h"

/* ----------------------------
   Linguagem de Programação II
   Engenharia de Computação
   UNICEP
   2017
   prof. Claudio Vincenzi

   Projeto LP-2-12

   ----------------------------
*/

/* Função Principal do programa */

int main(int argc, char *argv[])
{

  printf(
   "---------------------------------\n"
   "Linguagem de Programacao II\n"
   "Engenharia de Computacao\n"
   "UNICEP, 2017\n"
   "prof. Claudio Vincenzi\n"
   "---------------------------------\n"
   "\n"
  );

  printf(
    "----------------------------------\n"
    "Programa LP-2-12\n"
    " * Entrada de notas \n"
    " * Entrada do numero do aluno(a) \n"
    " * Entrada de nomes e sobrenomes dos alunos(a) \n"
    " * Entrada das respectivas notas \n"

    "----------------------------------\n"
    "\n"
  );

  int  contAlunos = 0; // Contador de alunos
  int  numNotas ;

  float somamedias ;

  numNotas = lerNumeroNotas();      // pergunte quantas notas havera' por aluno
  if(numNotas>0)                    // se numNotas>0, inicie processamento
  {

    printf("Serao processadas %d notas por aluno.\n\n",numNotas);

    bool repetir;        // controle do usuario
    do                           // faça...
      {
       somamedias = somamedias + processaAluno(numNotas);  // processe numNotas notas de um aluno, e em seguida
        contAlunos++;             // incremente contador de alunos processados
        repetir=promptRepetir();  // pergunte ao usuario se quer repetir (com novo aluno)
      }
      while(repetir);           // ... enquanto usuario solicitar repetir o processamento.

      printf("\n");
      printf("---------------------------------------------------------------------\n");
      printf("Total de %d alunos processados.\n\n", contAlunos);
  };

     printf ( " Media Geral : %5.3f \n ", somamedias / contAlunos ) ;

  printf("\n// Fim do programa. Bye!! //\n");
  system("PAUSE");
  return 0;

};
