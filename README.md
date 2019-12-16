# csvToSql
Converting a .csv file to a .txt PostgreSQL insertion values format for large data insertion automation

# Types Mapping
typedef struct Tipo{} defines an char array for each column of the table that the user wants to fill with the .csv data. At "example1", the import file defines 36 columns, in which 3140 tuples are defined. Those variables are defined as char[] in order to favor character analysis on handling exceptions. Since there are 36 columns we want to create/populate on the export file, we define 36 different char[].

# Formatting
Since different types require different formats (ex.: text -> 'hello word', int -> 123), there are 2 ways to convert: with or without Single Quotes.
For single quotes formatting, check lines from 108 to 124 (case 2) on "/example1/tabela1.c":
```c
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
        break;case 1:   //formatacao para inteiro
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
```
For non-quote formatting, check lines from 89 to 106 (case 1) on "/example1/tabela1.c":
```c
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
```
In order to separete different tuples as PostgreSQL does on it's "INSERT INTO (col1, col2, col3) VALUES (col1a, col2a, col3a), (col1b, col2b, col3b);", for example, it's defined at the first and last cases the '(' and ')' characters.

# Handling Exceptions
## 1. NULL data input
In .csv files, we often see NULL data defined as a blank space with no information. For exemple, for (col1, col2, col3) with col2 = NULL, .csv exports this as "data1;;data3". If this script is run without the first exception handler, it generates "(data1,,data3) as an output, which PostgreSQL does not accept as NULL. To deal with this problem, we need to detect null info and add a "NULL" string to it's column. This example is handled in lines from 382 to 389:

```c
  if(caractere == ';'){   //observacao: tratamento de elementos nulos
          tabela.anoEmissaoEmpenho[0] = 'N';
          tabela.anoEmissaoEmpenho[1] = 'U';
          tabela.anoEmissaoEmpenho[2] = 'L';
          tabela.anoEmissaoEmpenho[3] = 'L';
          tabela.anoEmissaoEmpenho[4] = ',';
          tabela.anoEmissaoEmpenho[5] = '\0';
        }
```
This caractere that was read indicates if the situation "data1;;data3" happens, as in there are none characters in the column and the next caractere read is already the one that indicates the end of the data for the column, since we defined that each column data ends with ';', except the last one.

## 2. Decimal Values (ex.: Monetary)
Depending on the .csv file source, monetary values are defined either "1000,00" or "1000.00". Postgres demands the second one. To handle this, in the cases defined fore the columns that these values are presents, the exception is handled, for example, in lines 433 and 434 for case 19:
```c
  if(tabela.pl[i-1] == ',')
          tabela.pl[i-1] = '.';
```

## 3. Escape sequence character
While reading each character of the import .csv file, we are going to have to deal with esc sequence characters. Since the goal of the script is to write a .txt file representing the data values we want to insert on our Postgres DataBase, CR and LF (\r and \n) characters are not useful. So, we often throw away those in several parts of the script, such as lines 77, 91, 111... Since each tuple is defined, ideally, in one line in the import file, in order to scan the last column of each tuple (the one that doesn't end in ';', condition that we were using before), we have to get the characters until the last, which depends on the operating system the file was encoded.

For example1, we have the termination '\r' for each line (check line 751).
For example2, we have the termination '\n' for each line (check line 152).

## 4. Controlling number of columns and number of tuples
Since there is one case for each column of the table, the switch operator size is variable. For each tuple, we analise from column 0 to N, so, in order to keep the loop working properly, it is defined a variable called "contagem", which is incremented every time we go past a column and reset every time we go to the next tuple.

In order for the script to work, the number of columns MUST BE changed at line 780.

Also, in order to read and write ALL the tuples in the new SQL file, there is a variable called id_sql which is also incremented every time we go to the next tuple. 

In order for the script to work, the number of tuples MUST BE changed at line 856.
