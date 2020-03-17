
/* Data de submissao: 13/03/2020
 * Nome: Lucas Leite Tavares  
 * RA: 156377
 */

#include <stdio.h>

/* Setamos o tamos do vetor buffer*/
const int tam_buffer=100;

/*Chamada da função que verifica a string e inverte as letras*/
void Inverter(char *buffer){
    char contador = 1, a, b, c = 0, d, aux;
    /* O laço abaixo verifica nosso vetor e quando encontra um \0, uma string, incrementa d,
    quando tivermos um espaço ou o final da string, setamos o contador.*/
    for(d = 0; buffer[d] != '\0'; d++)
        contador += (buffer[d] == ' '|| buffer[d] == '\n') ? 1 : 0;
    /* Quando o contador é setado, temos um laço que tem a função de alterar a posição das letras
    ou seja, posição no buffer, assim invertendo as palavras.*/
    do{
        if(contador == 1){
            for(b = c, --d; d > b; d--, b++)
                aux = buffer[b], buffer[b] = buffer[d], buffer[d] = aux;
        }else{
            for(b = a = c; buffer[a] != ' ' && buffer[a] != '\n'; a++);
            c = a + 1;
            for(--a; b < a; a--, b++)
                aux = buffer[b], buffer[b] = buffer[a], buffer[a] = aux;
        }
    }while(--contador);
}
/* Nossa main lê a string, coloca no vetor buffer, chmama a função que inverte,
e por final print o vetor buffer com a frase invertida*/
int main(){
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);
  Inverter(buffer);
  printf("%s", buffer);
  return 0;
}