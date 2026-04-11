#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int chutarNumero(int *num) {
    printf("\nDigite o token de acesso: ");
          if(scanf("%d", num)!= 1) { //entrada com restrição de caracteres
                printf("Caracteres não reconhecido! Tente novamente! \n"); 
                while(getchar() != '\n');
                return -1;//erro
               // fprintf(log, "Usuario digitou: %d\n", num_user);            
            }
            return *num;
}

int gerarRng(int max,int min) { //função para gerar números pseudos aleatórios
   return (rand() % (max - min + 1)) + min;
   
}

int evitarRng (int firewall,int token, int max,int min) { //evitar rng duplicado
    while(firewall == token) {
     firewall = gerarRng(max, min);
    }
    return firewall;
}
int main() {
    srand(time(NULL)); //usando tempo como seed para rng

    //configuração
    int max = 100;
    int min = 1;
    int saida = 0;

    //variaveis player
    int num_user;
    
    //estado do jogo
    int token = gerarRng(max, min);
    int firewall = gerarRng(max, min);
    firewall = evitarRng(firewall, token, max, min);
    // while(firewall == token) {//para evitar rng iguais
    //     firewall = gerarRng(max, min);
    // }
    int tentativas = 5;

    //interface
    printf("\nIniciando sistema Techcorp... para efetuar o login, digite o token de segurança de  %d a %d\n", min, max);
    printf("Para deslogar do sistema , digite 0. \n\n");
    printf("Atenção! a cada 5 tentativas de acesso, o número do token é regenerado como protocolo de segurança. \n");
    
    //log temporario
    printf("%d \n", token);
    printf("%d \n", firewall);
    //lógica do jogo
    while(true) {//loop principal
        //input
       int resultado = chutarNumero(&num_user);//entrada do player

        //progressão de dificuldade 
        if ( tentativas <= 1) {
             printf("Números de tentativas excedidas! Ativando protocolo de segurança e regeneração do token de acesso... \n");
             printf("Atenção! O firewall de segurança foi duplicado! \n");
             token = gerarRng(max, min);
             firewall = gerarRng(max, min);
             firewall = evitarRng(firewall, token, max, min);

             printf("%d \n", token);
             printf("%d \n", firewall);
             
             tentativas = 5;
        }
        //regras
        if (resultado == -1) {//caso a entrada for invalida, o loop reinicia
            continue;
        }

        if(resultado < saida || resultado > max) {
            printf("Tentativa incorreta! O token de acesso é de %d até %d\n", min, max);
            continue;
        }
        if(resultado == token) { //condição de vitória
            printf("Acesso garantido! o token aleatório era %d \n", token);
            printf("O número do firewall era %d \n", firewall);
            printf("Para continuar tentando acessar o sistema, digite qualquer número, ou digite 0 para deslogar \n");
            
          resultado = chutarNumero(&num_user);
             if(resultado == saida) {//decisão de reinicio do jogo
                 printf("Encerrando sistema... \n");
                 return 3;//saida
             } else {
                 printf("Sistema reiniciado! \n");
                 token = gerarRng(min, max);
                 firewall = gerarRng(min, max);
                 firewall = evitarRng(firewall,token, max, min);
                 continue;
                 printf("%d \n", token);
                 printf("%d \n", firewall);
             }
        }
        
        if(resultado == firewall) {//condição de derrota
            printf("Firewall de proteção ativado! Acesso bloqueado! \n");
            return 2;//2 = derrota
        }

          if(resultado == saida) {//Sair do jogo
            printf("Encerrando sistema... \n");
            break;
        }

        if(resultado > token) {//dicas
             printf("Número errado! O número do token é menor que %d, tentativas restantes: %d \n", num_user,tentativas - 1);
        } else {
            printf("Número errado! O número do token é maior que %d, tentativas restantes: %d \n", num_user,tentativas -1);
        }

        tentativas--;//tentativa ira diminuir a cada loop
    }
    
    //chutarNumero(&num_user);

    return 0;
}



    /*for(int cont = 0; cont < tent; cont++) {
        int restante = tent - cont - 1; // Calcula dinamicamente

        printf("Chute um numero: ");
        
        if (scanf("%d", &num_user) != 1) { 
            printf("Apenas numeros seu neandertal! Perdeu uma tentativa...\n"); 
            while(getchar() != '\n'); 
            continue; 
        }

        if(num_user < min || num_user > max) {
             printf("Apenas numeros de %d a %d! Perdeu tentativa por ser troxa.\n", min, max);
             continue;
        }

        if(num_user == num_sort) {
            printf("Parabens!! Voce acertou! O numero era %d\n", num_sort);
            return 0;
        } else if (num_user > num_sort) {  
            printf("Errado! O numero e MENOR que %d. Tentativas restantes: %d\n", num_user, restante);
        } else {  
            printf("Errado! O numero e MAIOR que %d. Tentativas restantes: %d\n", num_user, restante);
        }
    } 

    printf("\nTodas as tentativas acabaram! O numero era %d. Melhore!\n", num_sort);	
    return 0;
}*/
