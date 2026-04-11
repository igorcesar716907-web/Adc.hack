#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *log = fopen("log.txt", "a");

    if (log == NULL) {
        printf("Erro ao criar log!\n");
        return 1;
    }
    setbuf(log, NULL);

    srand(time(NULL)); 

    // Variáveis de limite - Agora o jogo obedece o que estiver aqui
    int min = 1;
    int max = 50; 
    int tent = 5;

    int num_user = 0;
    // Aplicando a fórmula: (rand() % amplitude) + min
    int token = (rand() % (max - min + 1)) + min;
    int firewall = (rand() % (max - min + 1)) + min; //numero que bloqueia acesso
    fprintf(log, "Token gerado: %d | Firewall: %d\n", token, firewall);//envia o numero gerado pro log

    while( token == firewall) { //para evitar que o token e o firewall sejam o mesmo numero
        firewall = (rand() % (max - min + 1)) + min;
        fprintf(log, "Token gerado: %d | Firewall: %d\n", token, firewall);
    }

    printf("\nIniciando sistema Techcorp... para efetuar o login, digite o token de segurança de  %d a %d\n", min, max);
    printf("Para deslogar do sistema , digite 0. \n\n");
    printf("Atenção! a cada 5 tentativas de acesso, o número do token é regenerado como protocolo de segurança. \n");

    do {  
        tent--;
        if ( tent < 1 ) { //reiniciando o token
        printf("Números de tentativas excedidas! Ativando protocolo de segurança e regeneração do token de acesso... \n");
        while (token == firewall){
            token = (rand() % (max - min + 1)) + min;
            fprintf(log, "Token gerado: %d | Firewall: %d\n", token, firewall);
      }
      tent = 5;
    }
    if ( tent < 3 ) { //reiniciando firewall
        while (firewall == token){
            firewall = (rand() % (max - min + 1)) + min;
            fprintf(log, "Token gerado: %d | Firewall: %d\n", token, firewall);
      }
    }
         printf("\nDigite o token de acesso: ");
         if(scanf("%d", &num_user)!= 1) { //entrada com restrição de caracteres
                printf("Caracteres não reconhecido! Tente novamente! Tentativas restantes: %d \n", tent); //se digitar errado, o loop é interrompido para tentar novamente
                while(getchar() != '\n');
                fprintf(log, "Usuario digitou: %d\n", num_user);
                continue;
            }
        if (num_user == 0) {
            printf("Encerrando o sistema...\n");
            return 0;
            
        }
            
        if (num_user > token) { //dicas
            printf("Número errado! O número do token é menor que %d, tentativas restantes: %d \n", num_user, tent);
            fprintf(log, "Tentativa incorreta\n");
        } else {
           printf("Número errado! O número do token é maior que %d, tentativas restantes %d  \n", num_user, tent); 
           fprintf(log, "Tentativa incorreta\n");
        }

        if(num_user == firewall) { //fim de jogo
            printf("Firewall de proteção ativado! Acesso bloqueado! \n");
            return 0;
        }
        if (num_user == token) { //condiçãpo de vitória
            printf("Acesso garantido! o token aleatório era %d \n", token);
            printf("O número do firewall era %d \n", firewall);
            printf("Para continuar tentando acessar o sistema, digite qualquer número, ou digite 0 para deslogar \n");

            fprintf(log, "Usuario acertou o token!\n");
            if(scanf("%d", &num_user)!= 1) { //verificação para continuar ou encerrar o jogo
                printf("Caracteres não reconhecido! Bloqueando acesso! \n");
                while(getchar() != '\n');
                fprintf(log, "Usuario digitou: %d\n", num_user);
                return 0;
            }
            if(num_user == 0 ) {
                printf("Encerrando sistema... \n");
                return 0;
            } else {
                printf("Sistema reiniciado! \n");
                token = (rand() % (max - min + 1)) + min;
                firewall = (rand() % (max - min + 1)) + min;
                fprintf(log, "Token gerado: %d | Firewall: %d\n", token, firewall);
                tent = 5;
            }
      
        }
        
    } while ( num_user != 0);
fclose(log);
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
