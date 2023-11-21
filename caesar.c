#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 200

void caesar(char *mensagem, int deslocamento)
{
    for (int i = 0; mensagem[i] != '\0'; i++)
    {
        if (isalpha(mensagem[i]))
        {
            if (isupper(mensagem[i]))
            {
                mensagem[i] = (mensagem[i] - 'A' + deslocamento) % 26 + 'A';
            }
            else
            {
                mensagem[i] = (mensagem[i] - 'a' + deslocamento) % 26 + 'a';
            }
        }
    }
}

int main(void)
{
    char mensagem[MAX_LENGTH];
    int deslocamento;

    printf("Digite a mensagem a ser criptografada: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite o deslocamento: ");
    scanf("%d", &deslocamento);

    caesar(mensagem, deslocamento);

    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}
