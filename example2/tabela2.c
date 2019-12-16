#include <stdio.h>
#include <stdint.h>
#include <string.h>

//OBS: FALTA FORMATAR O MODO DE INSERCAO DE VARIAVEL TIPO DATE (YYYYMMDD? YYYY-MM-DD? DD-MM-YYYY? VERIFICAR
//NO POSTGRES DOCUMENTACAO)


//Definir o tipo das variáveis dentro do sql do banco (varchar, date, int) para cada variavel na struct
typedef struct Tipo{
    char id[10];          //[int]
    char uoCod[128];      //[varchar]
    char uo[128];
    char pais[128];
    char uf[128];         //[/varchar]
    char latitude[128];   //[double]
    char longitude[128];  //[double]
//36 colunas
    }tipo;

int main() {
    tipo tabela;                                            //tabela com todos os tipos que serao gerados no postgres
    FILE* arquivo = fopen("Dados-TemaOrcamento_tabela2.txt", "r");     //arquivo de entrada .csv ou .txt
    FILE* SQL = fopen("SQL_Dados-TemaOrcamento_tabela2.txt", "w");              //arquivo de saida SQL
    int id_sql = 0;     //variavel auxiliar para interromper o programa antes do segfault

    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }

    int contagem = 0, i = 0, j;     //contagem dos tipos de cada tupla
    char caractere;


    while(caractere != EOF){
      switch(contagem){
        case 0:
          tabela.id[0] = '(';
//          tabela.id[1] = '\'';
          i = 1;
          //caractere = fgetc(arquivo);
          while(caractere != ';'){
            caractere = fgetc(arquivo);
            tabela.id[i] = caractere;
            i++;
          }
//          tabela.id[i-1] = '\'';
          tabela.id[i-1] = ',';
          tabela.id[i] = '\0';

          break;

        case 1:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.uoCod[i] = caractere;
            if(tabela.uoCod[i-1] == ',')
              tabela.uoCod[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.uoCod[i-1] == ';')
            tabela.uoCod[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.uoCod[i] = ',';
            tabela.uoCod[i+1] = '\0';
          }
        break;

        case 2:
          tabela.uo[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.uo[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.uo[i-1] == ';')
            tabela.uo[i-1] = '\'';
          else{
            tabela.uo[i] = '\'';
            tabela.uo[i+1] = ',';
            tabela.uo[i+2] = '\0';
          }
        break;

        case 3:
          tabela.pais[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.pais[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.pais[i-1] == ';')
            tabela.pais[i-1] = '\'';
          else{
            tabela.pais[i] = '\'';
            tabela.pais[i+1] = ',';
            tabela.pais[i+2] = '\0';
          }
        break;

        case 4:
        tabela.uf[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.uf[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.uf[i-1] == ';')
            tabela.uf[i-1] = '\'';
          else{
            tabela.uf[i] = '\'';
            tabela.uf[i+1] = ',';
            tabela.uf[i+2] = '\0';
          }
        break;

        case 5:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.latitude[i] = caractere;
            if(tabela.latitude[i-1] == ',')
              tabela.latitude[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.latitude[i-1] == ';')
            tabela.latitude[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.latitude[i] = ',';
            tabela.latitude[i+1] = '\0';
          }
        break;

        case 6:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != '\n'){
            tabela.longitude[i] = caractere;
            if(tabela.longitude[i-1] == ',')
              tabela.longitude[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.longitude[i-1] == ';')
            tabela.longitude[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.longitude[i] = ')';
            if(id_sql != 41){
              tabela.longitude[i+1] = ',';
              tabela.longitude[i+2] = '\0';
            }
            else
            {
              tabela.longitude[i+1] = ';';
              tabela.longitude[i+2] = '\0';
            }
          }
        break;


        }
      contagem++;

      //teste de correcao
      if(contagem == 7){
          printf("%s", tabela.id);
          fputs(tabela.id,SQL);
          printf("%s", tabela.uoCod);
          fputs(tabela.uoCod,SQL);
          printf("%s", tabela.uo);
          fputs(tabela.uo,SQL);
          printf("%s", tabela.pais);
          fputs(tabela.pais,SQL);
          printf("%s", tabela.uf);
          fputs(tabela.uf,SQL);
          printf("%s", tabela.latitude);
          fputs(tabela.latitude,SQL);
          printf("%s", tabela.longitude);
          fputs(tabela.longitude,SQL);
          fputc('\r', SQL);
          contagem = 0;
          if(id_sql == 41){
            fclose(arquivo);

            fclose(SQL);
            return 1;
          }
          id_sql++;
      }
    }

//    fclose(arquivo);
//    fclose(SQL);


    return 0;
}
