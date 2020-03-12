
/* Data de submissao:
 * Nome: Lucas Leite Tavares  
 * RA: 156377
 */

#include <stdio.h>
const int tam_buffer=100;

void Inverter(char *buffer){
    char contador = 1, a, b, c = 0, d, aux;

    for(d = 0; buffer[d] != '\0'; d++)
        contador += (buffer[d] == ' '|| buffer[d] == '\n') ? 1 : 0;

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

int main(){
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);
  Inverter(buffer);
  printf("%s", buffer);
  return 0;
}