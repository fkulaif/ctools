/*
 * aluno.h
 *
 *  Created on: May 24, 2017
 *      Author: Fernando
 */


/* ---------------------------------------------
   Linguagem de Programação II
   Engenharia de Computação
   UNICEP
   2014
   prof. Claudio Vincenzi
   crvincenzi.unicep@gmail.com

   Projeto LP-2-12

   Esta biblioteca contem funcoes para
   o sistema de manipulacao de avaliacoes
   de alunos.

   ---------------------------------------------
*/

/* Esta função deleta o caracter NL presente na string s
 */

void deletaNL(char *s) {
  int i=0;
  while(1) // loop infinito...
  {
           if(s[i]==0) return;  // se s[i] é fim da string, retorne
           if(s[i]=='\n') {     // se s[i] é NL então
                           s[i]=0;   // delete o NL
                           return;   // e retorne
           }
           i++;                      // avance o indice
  };
}

/* Esta função questiona o usuario sobre continuar ou encerrar
 * o processamento de notas de alunos
 */

bool promptRepetir() {
   printf("Novo aluno? [S|n] ");
   char c;
   c=fgetc(stdin);  // leia 1 caracter
   fflush(stdin);   // e limpe o buffer
   if( c=='s' || c=='S' || c=='\n' ) return TRUE;  // repita!
   return FALSE;   // nao repita!
}

/* Esta função calcula a média simples entre n valores x[i]
 * Onde 0 < i < n
 */
float mediaSimplesVetor(int n, float x[]) {
   int i;
   float soma=0.0;
   for(i=0; i<n; i++) soma=soma+x[i];  // calcule somatorio de Xi
   return soma/n;  // retorne a media
}

/*
 * Esta função verifica se os caracateres
 * em linha podem ser convertidos em numero int/float
 */
bool ehNumerica(char *linha) {
   int i;
   int l=strlen(linha);
   for(i=0; i<l; i++) {
            if( isdigit(linha[i]) ) continue; // eh caracter numerico [0-9]
            if( linha[i]=='.'  )    continue; // '.' será ignorado por atoi/atof
            if( linha[i]=='-'  )    continue; // '-' será analisado por atoi/atof
            if( linha[i]=='+'  )    continue; // '+' será analisado por atoi/atof
            if( linha[i]=='\n' )    continue; // NL será ignorado por atoi/atof
            return FALSE;  // string linha contém ao menos 1 caracter invalido
   };
   return TRUE;  // string linha eh valida como numerica
}

/*
 * Esta função verifica se os caracateres
 * em linha sao todos alfabeticos
 */
bool ehAlfabetica(char *linha) {
   int i;
   int l=strlen(linha);
   for(i=0; i<l; i++) {
            if( isalpha(linha[i]) ) continue; // eh caracter numerico [0-9]
            if( linha[i]=='-'  )    continue; // hifen     será considerado alfabetico
            if( linha[i]==' '  )    continue; // branco    será considerado alfabetico
            if( linha[i]=='\'' )    continue; // apostrofe será considerado alfabetico
            return FALSE;  // string linha contém ao menos 1 caracter invalido
   };
   return TRUE;  // string linha eh valida como numerica
}

/*
 * Esta função le e retorna o nome/sobrenome do aluno
 * Aceita apenas caracteres alfabeticos
 */
char * lerNome(char *tipoNome, int numAluno) {
      char *nome;
      static char linha[MAX_COMPRIMENTO_NOME+1];         // linha para leitura dos caracteres
      do {
        printf("Entre com o %-9s do aluno %4d:\t",tipoNome,numAluno);

        fgets(linha,MAX_COMPRIMENTO_NOME+1,stdin);  // leia a linha (entrada do usuario)
        if(feof(stdin))         // se EOF, sinalize com retorno 0
               return 0;
        fflush(stdin);            // limpa o buffer de leitura
        deletaNL(linha);          // remove NL inserido por fgets()
        if(ehAlfabetica(linha))   // se linha eh alfabetica
                 nome=linha;      // atribui nome
        else
                 printf("** Nao-alfabetico! **\n");
      }
      while (strlen(linha)<MIN_COMPRIMENTO_NOME);
      return nome;
}
/*
 * Esta função le e retorna o numero de notas de cada aluno
 * Aceita apenas numeros positivos [1-10]
 */
int   lerNumeroNotas() {
      int numNotas;

	  do
      {
        printf("Entre com o numero de notas de cada aluno [1-%d]: ",MAX_NUMERO_NOTAS); //12
        char linha[10];            // linha para leitura dos caracteres do valor
        fgets(linha,10,stdin);     // leia a linha (entrada do usuario)
        if(feof(stdin)) return 0;  // se EOF, sinalize com retorno 0
        fflush(stdin);             // limpa o buffer de leitura
        if(ehNumerica(linha))      // se linha eh numerica
                 numNotas = atoi(linha);   // converte  para int
        else
                 printf("** Nao-numerico! **\n");
      }
      while( numNotas<0 || numNotas>MAX_NUMERO_NOTAS );
      return numNotas;
}
/*
 * Esta função le e retorna o numero do aluno
 * Aceita apenas numeros positivos
 */
int   lerNumero() {
      int numero=0; // execute ao menos 1 iteração while()
      while( numero<MIN_NUMERO_ALUNO || numero>MAX_NUMERO_ALUNO ) {
        printf("Entre com o numero do aluno [%d-%d]: ", MIN_NUMERO_ALUNO, MAX_NUMERO_ALUNO);
        char linha[10];         // linha para leitura dos caracteres do valor
        fgets(linha,10,stdin);  // leia a linha (entrada do usuario)
        fflush(stdin);          // limpa o buffer de leitura
        if(ehNumerica(linha))   // se linha eh numerica
                 numero = atoi(linha);   // converte  para int
        else
                 printf("** Nao-numerico! **\n");
      };
      return numero;
}

/*
 * Esta função le e retorna a nota i do aluno numAluno
 * Aceita apenas notas entre 0.0 e 10.0 inclusive
 */
float lerNota(int numAluno, int i) {
      float nota=-1.0; // execute ao menos 1 iteração while()
      while( nota<NOTA_MINIMA	 || nota>NOTA_MAXIMA) {
        printf("Aluno %4d, nota %02d: ",numAluno,i);
        char linha[10];         // linha para leitura dos caracteres do valor
        fgets(linha,10,stdin);  // leia a linha (entrada do usuario)
        fflush(stdin);          // limpa o buffer de leitura
        if(ehNumerica(linha))   // se linha eh numerica
                  nota = atof(linha);   // converte numero na linha para float
        else
                  printf("** Nao-numerico! **\n");
      };
      return nota;
};

/*  Procedimento para processamento repetitivo de alunos
 *  Alunos com n notas cada um
 */

float processaAluno(int n) {

  int   numAluno;

  float somamedias ;

  char *nome;

  char  primNomeAluno[MAX_COMPRIMENTO_NOME+1];                 // primeiro nome do aluno
  char  sobrNomeAluno[MAX_COMPRIMENTO_NOME+1];                 // sobrenome do aluno

  float notaAluno[MAX_NUMERO_NOTAS];   // ate NUM_MAXIMO_NOTAS notas por aluno
  float mediaAluno;                    // media final do aluno

  printf("---------------------------------------------------------------------\n");
  numAluno  = lerNumero();             // ler o numero do aluno

  nome      = lerNome("nome",numAluno);         // ler primeiro nome
  strcpy(primNomeAluno, nome);                  // salve o primeiro nome

  nome      = lerNome("sobrenome",numAluno);    // ler o sobrenome
  strcpy(sobrNomeAluno, nome);                  // salve o sobrenome

  printf("\n");
  printf("Serao processadas agora as notas do aluno %d, \"%s %s\"\n",numAluno, primNomeAluno, sobrNomeAluno);

  int i;
  for(i=0; i<n; i++) {  // para i de 0 até n-1 faça ...
          notaAluno[i] = lerNota(numAluno, i+1);  // ler a nota i
  };

  mediaAluno = mediaSimplesVetor( n, notaAluno );  // calcula a media simples das n notas
  printf("\n");
  printf("Media das %d nota do aluno %d = %5.1f\n", n, numAluno, mediaAluno);

  if ( mediaAluno < NOTA_MINIMA_APROVACAO )
  {
  	printf ( " O Aluno esta REPROVADO! \n") ;

  }
  else
  {
  	printf ( " Aluno APROVADO, Parabens !!!! \n" ) ;
  }



  printf("\n");

  return  mediaAluno ;
}
