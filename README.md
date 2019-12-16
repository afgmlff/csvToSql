# csvToSql
Converting a .csv file to a .txt PostgreSQL insertion values format for large data insertion automation

# types mapping
typedef struct Tipo{} defines an char array for each column of the table that the user wants to fill with the .csv data. At "example1", the import file defines 36 columns, in which 3140 tuples are defined. Those variables are defined as char[] in order to favor character analysis on handling exceptions. Since there are 36 columns we want to create/populate on the export file, we define 36 different char[].

# formatting
Since different types require different formats (ex.: text -> 'hello word', int -> 123), there are 2 ways to convert: with or without Single Quotes.
For single quotes formatting, check lines from 108 to 124 (case 2) on "/example1/tabela1.c".
For non-quote formatting, check lines from 89 to 106 (case 1) on "/example1/tabela1.c".

In order to separete different tuples as PostgreSQL does on it's "INSERT INTO (col1, col2, col3) VALUES (col1a, col2a, col3a), (col1b, col2b, col3b);", for example, it's defined at the first and last cases the '(' and ')' characters.

# handling exceptions
## 1º: NULL data input
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
