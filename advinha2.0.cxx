#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); 

    // Variáveis de limite - Agora o jogo obedece o que estiver aqui
    int min = 1;
    int max = 20; 
    int tent = 3;
    
    int num_user = 0;
    // Aplicando a fórmula: (rand() % amplitude) + min
    int num_sort = (rand() % (max - min + 1)) + min;

    printf("Bem vindo ao jogo de adivinhacao! Adivinhe numeros de %d a %d\n", min, max);
    printf("O limite de tentativas e %d\n\n", tent);

    for(int cont = 0; cont < tent; cont++) {
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
}
