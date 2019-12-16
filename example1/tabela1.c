#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*  O script a seguir formata a inserçao de uma quantitade grande (3140) de valores
**  importados como .csv (ou .txt, no caso, também separados por ';') para exportação
**  em SQL, no caso, Postgresql, no formato txt
**
**  Para adaptaçao para dados inseridos de tabelas com outras colunas, é necessário modificar
**  as variaveis definidas na struct "Tipo" para condizerem com as colunas onde desejam-se inserir
**  dados formatados para SQL
**
**
*/
//Definir o tipo das variáveis dentro do sql do banco (varchar, date, int) para cada variavel na struct
typedef struct Tipo{
    char id[10];                  //[INT]
    char ano[32];                 //[INT]
    char uoCod[128];
    char ugCod[128];
    char ugResponsavel[128];
    char programaCod[128];
    char programa[128];
    char acaoCod[128];
    char acao[128];
    char poCod[128];
    char po[1280];
    char gndCod[128];
    char gnd[128];
    char elementoDespesaCod[128];
    char elementoDespesa[128];
    char subElementoDespesaCod[128];
    char subElementoDespesa[128];
    char anoEmissaoEmpenho[128];
    char empenho[128];
    char pl[128];
    char dotacaoInicial[128];
    char autorizado[128];
    char creditoDisponivel[128];
    char empenhado[128];
    char liquidado[128];
    char pago[128];
    char despesaExecutada[128];
    char contingenciamento[128];
    char rpProcInscrito[128];
    char rpNaoProcInscrito[128];
    char rpProcAPagar[128];
    char rpNaoProcAPagar[128];
    char rpProcPago[128];
    char rpNaoProcPago[128];
    char rpProcCancelado[128];
    char rpNaoProcCancelado[128];
//36 colunas
    }tipo;

int main() {
    tipo tabela;                                            //tabela com todos os tipos que serao gerados no postgres
    FILE* arquivo = fopen("Dados-TemaOrcamento_tabela1.txt", "r");     //arquivo de entrada .csv ou .txt
    FILE* SQL = fopen("SQL_Dados-TemaOrcamento_tabela1.txt", "w");              //arquivo de saida SQL
    int id_sql = 0;     //variavel auxiliar para interromper o programa antes do segfault

    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }

    int contagem = 0, i = 0, j;     //contagem dos tipos de cada tupla
    char caractere;


    while(caractere != EOF){
      switch(contagem){
        case 0:   //formatacao para inteiro
          tabela.id[0] = '(';

          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            caractere = fgetc(arquivo);
            tabela.id[i] = caractere;
            i++;
          }
//          tabela.id[i-1] = '\'';
          tabela.id[i-1] = ',';
          tabela.id[i] = '\0';

          break;

        case 1:   //formatacao para inteiro
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.ano[i] = caractere;
            if(tabela.ano[i-1] == ',')
              tabela.ano[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.ano[i-1] == ';')
            tabela.ano[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.ano[i] = ',';
            tabela.ano[i+1] = '\0';
          }
        break;

        case 2:     //formatacao para varchar
          tabela.uoCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.uoCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.uoCod[i-1] == ';')
            tabela.uoCod[i-1] = '\'';
          else{
            tabela.uoCod[i] = '\'';
            tabela.uoCod[i+1] = ',';
            tabela.uoCod[i+2] = '\0';
          }
        break;

        case 3:
          tabela.ugCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.ugCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.ugCod[i-1] == ';')
            tabela.ugCod[i-1] = '\'';
          else{
            tabela.ugCod[i] = '\'';
            tabela.ugCod[i+1] = ',';
            tabela.ugCod[i+2] = '\0';
          }
        break;

        case 4:
          tabela.ugResponsavel[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.ugResponsavel[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.ugResponsavel[i-1] == ';')
            tabela.ugResponsavel[i-1] = '\'';
          else{
            tabela.ugResponsavel[i] = '\'';
            tabela.ugResponsavel[i+1] = ',';
            tabela.ugResponsavel[i+2] = '\0';
          }
        break;

        case 5:
          tabela.programaCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.programaCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.programaCod[i-1] == ';')
            tabela.programaCod[i-1] = '\'';
          else{
            tabela.programaCod[i] = '\'';
            tabela.programaCod[i+1] = ',';
            tabela.programaCod[i+2] = '\0';
          }
        break;

        case 6:
          tabela.programa[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.programa[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.programa[i-1] == ';')
            tabela.programa[i-1] = '\'';
          else{
            tabela.programa[i] = '\'';
            tabela.programa[i+1] = ',';
            tabela.programa[i+2] = '\0';
          }
        break;

        case 7:
          tabela.acaoCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.acaoCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.acaoCod[i-1] == ';')
            tabela.acaoCod[i-1] = '\'';
          else{
            tabela.acaoCod[i] = '\'';
            tabela.acaoCod[i+1] = ',';
            tabela.acaoCod[i+2] = '\0';
          }
        break;

        case 8:
          tabela.acao[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.acao[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.acao[i-1] == ';')
            tabela.acao[i-1] = '\'';
          else{
            tabela.acao[i] = '\'';
            tabela.acao[i+1] = ',';
            tabela.acao[i+2] = '\0';
          }
        break;

        case 9:
          tabela.poCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.poCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.poCod[i-1] == ';')
            tabela.poCod[i-1] = '\'';
          else{
            tabela.poCod[i] = '\'';
            tabela.poCod[i+1] = ',';
            tabela.poCod[i+2] = '\0';
          }
        break;

        case 10:
          tabela.po[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.po[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.po[i-1] == ';')
            tabela.po[i-1] = '\'';
          else{
            tabela.po[i] = '\'';
            tabela.po[i+1] = ',';
            tabela.po[i+2] = '\0';
          }
        break;

        case 11:
          tabela.gndCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.gndCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.gndCod[i-1] == ';')
            tabela.gndCod[i-1] = '\'';
          else{
            tabela.gndCod[i] = '\'';
            tabela.gndCod[i+1] = ',';
            tabela.gndCod[i+2] = '\0';
          }
        break;

        case 12:
          tabela.gnd[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.gnd[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.gnd[i-1] == ';')
            tabela.gnd[i-1] = '\'';
          else{
            tabela.gnd[i] = '\'';
            tabela.gnd[i+1] = ',';
            tabela.gnd[i+2] = '\0';
          }
        break;

        case 13:
          tabela.elementoDespesaCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.elementoDespesaCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.elementoDespesaCod[i-1] == ';')
            tabela.elementoDespesaCod[i-1] = '\'';
          else{
            tabela.elementoDespesaCod[i] = '\'';
            tabela.elementoDespesaCod[i+1] = ',';
            tabela.elementoDespesaCod[i+2] = '\0';
          }
        break;

        case 14:
          tabela.elementoDespesa[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.elementoDespesa[i] = caractere;
            caractere = fgetc(arquivo);
            if (caractere )
            i++;
          }
          if(tabela.elementoDespesa[i-1] == ';')
            tabela.elementoDespesa[i-1] = '\'';
          else{
            tabela.elementoDespesa[i] = '\'';
            tabela.elementoDespesa[i+1] = ',';
            tabela.elementoDespesa[i+2] = '\0';
          }
        break;

        case 15:
          tabela.subElementoDespesaCod[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.subElementoDespesaCod[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.subElementoDespesaCod[i-1] == ';')
            tabela.subElementoDespesaCod[i-1] = '\'';
          else{
            tabela.subElementoDespesaCod[i] = '\'';
            tabela.subElementoDespesaCod[i+1] = ',';
            tabela.subElementoDespesaCod[i+2] = '\0';
          }
        break;

        case 16:
          tabela.subElementoDespesa[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.subElementoDespesa[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.subElementoDespesa[i-1] == ';')
            tabela.subElementoDespesa[i-1] = '\'';
          else{
            tabela.subElementoDespesa[i] = '\'';
            tabela.subElementoDespesa[i+1] = ',';
            tabela.subElementoDespesa[i+2] = '\0';
          }
        break;

        case 17:      //formatacao para inteiro
        i = 0;
        caractere = fgetc(arquivo);
        if(caractere == ';'){   //observacao: tratamento de elementos nulos
          tabela.anoEmissaoEmpenho[0] = 'N';
          tabela.anoEmissaoEmpenho[1] = 'U';
          tabela.anoEmissaoEmpenho[2] = 'L';
          tabela.anoEmissaoEmpenho[3] = 'L';
          tabela.anoEmissaoEmpenho[4] = ',';
          tabela.anoEmissaoEmpenho[5] = '\0';
        }
        else{
        while(caractere != ';'){
          tabela.anoEmissaoEmpenho[i] = caractere;
          if(tabela.anoEmissaoEmpenho[i-1] == ',')
            tabela.anoEmissaoEmpenho[i-1] = '.';
          caractere = fgetc(arquivo);
          i++;
        }
        if(tabela.anoEmissaoEmpenho[i-1] == ';')
          tabela.anoEmissaoEmpenho[i-1] = ',';
        else{
        //          tabela.PLOA[i] = '\'';
          tabela.anoEmissaoEmpenho[i] = ',';
          tabela.anoEmissaoEmpenho[i+1] = '\0';
        }
      }
        break;

        case 18:
          tabela.empenho[0] = '\'';
          i = 1;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.empenho[i] = caractere;
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.empenho[i-1] == ';')
            tabela.empenho[i-1] = '\'';
          else{
            tabela.empenho[i] = '\'';
            tabela.empenho[i+1] = ',';
            tabela.empenho[i+2] = '\0';
          }
        break;

        //A PARTIR DAQUI, VALORES DECIMAIS PARA REPRESENTACAO MONETARIA COM TROCA DO ',' POR '.' PARA INSERCAO NO POSTGRES
        case 19:

          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.pl[i] = caractere;
            if(tabela.pl[i-1] == ',')
              tabela.pl[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.pl[i-1] == ';')
            tabela.pl[i-1] = ',';
          else{
  //          tabela.PLOA[i] = '\'';
            tabela.pl[i] = ',';
            tabela.pl[i+1] = '\0';
          }
        break;

        case 20:
//          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.dotacaoInicial[i] = caractere;
            if(tabela.dotacaoInicial[i-1] == ',')
              tabela.dotacaoInicial[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.dotacaoInicial[i-1] == ';')
            tabela.dotacaoInicial[i-1] = ',';
          else{
  //          tabela.PLOA[i] = '\'';
            tabela.dotacaoInicial[i] = ',';
            tabela.dotacaoInicial[i+1] = '\0';
          }
        break;

        case 21:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.autorizado[i] = caractere;
            if(tabela.autorizado[i-1] == ',')
              tabela.autorizado[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.autorizado[i-1] == ';')
            tabela.autorizado[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.autorizado[i] = ',';
            tabela.autorizado[i+1] = '\0';
          }
        break;

        case 22:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.creditoDisponivel[i] = caractere;
            if(tabela.creditoDisponivel[i-1] == ',')
              tabela.creditoDisponivel[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.creditoDisponivel[i-1] == ';')
            tabela.creditoDisponivel[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.creditoDisponivel[i] = ',';
            tabela.creditoDisponivel[i+1] = '\0';
          }
        break;

        case 23:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.empenhado[i] = caractere;
            if(tabela.empenhado[i-1] == ',')
              tabela.empenhado[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.empenhado[i-1] == ';')
            tabela.empenhado[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.empenhado[i] = ',';
            tabela.empenhado[i+1] = '\0';
          }
        break;

        case 24:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.liquidado[i] = caractere;
            if(tabela.liquidado[i-1] == ',')
              tabela.liquidado[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.liquidado[i-1] == ';')
            tabela.liquidado[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.liquidado[i] = ',';
            tabela.liquidado[i+1] = '\0';
          }
        break;

        case 25:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.pago[i] = caractere;
            if(tabela.pago[i-1] == ',')
              tabela.pago[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.pago[i-1] == ';')
            tabela.pago[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.pago[i] = ',';
            tabela.pago[i+1] = '\0';
          }
        break;

        case 26:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.despesaExecutada[i] = caractere;
            if(tabela.despesaExecutada[i-1] == ',')
              tabela.despesaExecutada[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.despesaExecutada[i-1] == ';')
            tabela.despesaExecutada[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.despesaExecutada[i] = ',';
            tabela.despesaExecutada[i+1] = '\0';
          }
        break;

        case 27:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.contingenciamento[i] = caractere;
            if(tabela.contingenciamento[i-1] == ',')
              tabela.contingenciamento[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.contingenciamento[i-1] == ';')
            tabela.contingenciamento[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.contingenciamento[i] = ',';
            tabela.contingenciamento[i+1] = '\0';
          }
        break;

        case 28:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.rpProcInscrito[i] = caractere;
            if(tabela.rpProcInscrito[i-1] == ',')
              tabela.rpProcInscrito[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpProcInscrito[i-1] == ';')
            tabela.rpProcInscrito[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpProcInscrito[i] = ',';
            tabela.rpProcInscrito[i+1] = '\0';
          }
        break;

        case 29:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.rpNaoProcInscrito[i] = caractere;
            if(tabela.rpNaoProcInscrito[i-1] == ',')
              tabela.rpNaoProcInscrito[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpNaoProcInscrito[i-1] == ';')
            tabela.rpNaoProcInscrito[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpNaoProcInscrito[i] = ',';
            tabela.rpNaoProcInscrito[i+1] = '\0';
          }
        break;

        case 30:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.rpProcAPagar[i] = caractere;
            if(tabela.rpProcAPagar[i-1] == ',')
              tabela.rpProcAPagar[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpProcAPagar[i-1] == ';')
            tabela.rpProcAPagar[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpProcAPagar[i] = ',';
            tabela.rpProcAPagar[i+1] = '\0';
          }
        break;

        case 31:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.rpNaoProcAPagar[i] = caractere;
            if(tabela.rpNaoProcAPagar[i-1] == ',')
              tabela.rpNaoProcAPagar[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpNaoProcAPagar[i-1] == ';')
            tabela.rpNaoProcAPagar[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpNaoProcAPagar[i] = ',';
            tabela.rpNaoProcAPagar[i+1] = '\0';
          }
        break;

        case 32:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.rpProcPago[i] = caractere;
            if(tabela.rpProcPago[i-1] == ',')
              tabela.rpProcPago[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpProcPago[i-1] == ';')
            tabela.rpProcPago[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpProcPago[i] = ',';
            tabela.rpProcPago[i+1] = '\0';
          }
        break;

        case 33:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.rpNaoProcPago[i] = caractere;
            if(tabela.rpNaoProcPago[i-1] == ',')
              tabela.rpNaoProcPago[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpNaoProcPago[i-1] == ';')
            tabela.rpNaoProcPago[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpNaoProcPago[i] = ',';
            tabela.rpNaoProcPago[i+1] = '\0';
          }
        break;

        case 34:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != ';'){
            tabela.rpProcCancelado[i] = caractere;
            if(tabela.rpProcCancelado[i-1] == ',')
              tabela.rpProcCancelado[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpProcCancelado[i-1] == ';')
            tabela.rpProcCancelado[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpProcCancelado[i] = ',';
            tabela.rpProcCancelado[i+1] = '\0';
          }
        break;

        case 35:
        //          tabela.PLOA[0] = '\'';
          i = 0;
          caractere = fgetc(arquivo);
          while(caractere != '\r'){
            tabela.rpNaoProcCancelado[i] = caractere;
            if(tabela.rpNaoProcCancelado[i-1] == ',')
              tabela.rpNaoProcCancelado[i-1] = '.';
            caractere = fgetc(arquivo);
            i++;
          }
          if(tabela.rpNaoProcCancelado[i-1] == ';')
            tabela.rpNaoProcCancelado[i-1] = ',';
          else{
        //          tabela.PLOA[i] = '\'';
            tabela.rpNaoProcCancelado[i] = ')';
            if(id_sql != 3139){         //caso nao seja a ultima tupla, separa por virgula o proximo elemento da tabela
              tabela.rpNaoProcCancelado[i+1] = ',';
              tabela.rpNaoProcCancelado[i+2] = '\0';
            }
            else          //caso seja o ultimo elemento, encerra com ';'
            {
              tabela.rpNaoProcCancelado[i+1] = ';';
              tabela.rpNaoProcCancelado[i+2] = '\0';
            }
          }
        break;


        }
      contagem++;   //contagem altera o switch case para qual coluna esta sendo inserido o dado (col1, col2, ..., col36) [0,35]

      //teste de correcao: mostrar no terminal o que esta sendo inserido no arquivo .txt do sql
      if(contagem == 36){//alterar de acordo com o numero de colunas. Ao chegar na coluna x = 36, a contagem é resetada para o proximo elemento (prox. tupla)
          printf("%s", tabela.id);
          fputs(tabela.id,SQL);
          printf("%s", tabela.ano);
          fputs(tabela.ano,SQL);
          printf("%s", tabela.uoCod);
          fputs(tabela.uoCod,SQL);
          printf("%s", tabela.ugCod);
          fputs(tabela.ugCod,SQL);
          printf("%s", tabela.ugResponsavel);
          fputs(tabela.ugResponsavel,SQL);
          printf("%s", tabela.programaCod);
          fputs(tabela.programaCod,SQL);
          printf("%s", tabela.programa);
          fputs(tabela.programa,SQL);
          printf("%s", tabela.acaoCod);
          fputs(tabela.acaoCod,SQL);
          printf("%s", tabela.acao);
          fputs(tabela.acao,SQL);
          printf("%s", tabela.poCod);
          fputs(tabela.poCod,SQL);
          printf("%s", tabela.po);
          fputs(tabela.po,SQL);
          printf("%s", tabela.gndCod);
          fputs(tabela.gndCod,SQL);
          printf("%s", tabela.gnd);
          fputs(tabela.gnd,SQL);
          printf("%s", tabela.elementoDespesaCod);
          fputs(tabela.elementoDespesaCod,SQL);
          printf("%s", tabela.elementoDespesa);
          fputs(tabela.elementoDespesa,SQL);
          printf("%s", tabela.subElementoDespesaCod);
          fputs(tabela.subElementoDespesaCod,SQL);
          printf("%s", tabela.subElementoDespesa);
          fputs(tabela.subElementoDespesa,SQL);
          printf("%s", tabela.anoEmissaoEmpenho);
          fputs(tabela.anoEmissaoEmpenho,SQL);
          printf("%s", tabela.empenho);
          fputs(tabela.empenho,SQL);
          printf("%s", tabela.pl);
          fputs(tabela.pl,SQL);
          printf("%s", tabela.dotacaoInicial);
          fputs(tabela.dotacaoInicial,SQL);
          printf("%s", tabela.autorizado);
          fputs(tabela.autorizado,SQL);
          printf("%s", tabela.creditoDisponivel);
          fputs(tabela.creditoDisponivel,SQL);
          printf("%s", tabela.empenhado);
          fputs(tabela.empenhado,SQL);
          printf("%s", tabela.liquidado);
          fputs(tabela.liquidado,SQL);
          printf("%s", tabela.pago);
          fputs(tabela.pago,SQL);
          printf("%s", tabela.despesaExecutada);
          fputs(tabela.despesaExecutada,SQL);
          printf("%s", tabela.contingenciamento);
          fputs(tabela.contingenciamento,SQL);
          printf("%s", tabela.rpProcInscrito);
          fputs(tabela.rpProcInscrito,SQL);
          printf("%s", tabela.rpNaoProcInscrito);
          fputs(tabela.rpNaoProcInscrito,SQL);
          printf("%s", tabela.rpProcAPagar);
          fputs(tabela.rpProcAPagar,SQL);
          printf("%s", tabela.rpNaoProcAPagar);
          fputs(tabela.rpNaoProcAPagar,SQL);
          printf("%s", tabela.rpProcPago);
          fputs(tabela.rpProcPago,SQL);
          printf("%s", tabela.rpNaoProcPago);
          fputs(tabela.rpNaoProcPago,SQL);
          printf("%s", tabela.rpProcCancelado);
          fputs(tabela.rpProcCancelado,SQL);
          printf("%s", tabela.rpNaoProcCancelado);
          fputs(tabela.rpNaoProcCancelado,SQL);
          fputc('\r', SQL);       //formatacao: 1 tupla por linha
          contagem = 0;           //reseta a coluna para a insercao do proximo elemento começando da coluna 0

          if(id_sql == 3139){     //ao chegar no ultimo elemento, termina a execução do programa
            fclose(arquivo);

            fclose(SQL);
            return 1;
          }
          id_sql++;         //controle de quantos elementos já foram inseridos, para o trigger de ultimo elemento (condicao acima)
      }
    }

//    fclose(arquivo);
//    fclose(SQL);


    return 0;
}
