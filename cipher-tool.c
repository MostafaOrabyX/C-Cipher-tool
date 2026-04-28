#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *encrypt(char pltext[] , int encode);
char *decrypt( char citext[] , int decode);

int main()
{
    while(1)
    {
        char enorde ;
        printf("Enter the first letter\nEncrypt(E) or Decrypt(D):");
        scanf(" %c", &enorde);
        if (toupper(enorde) == 'E')
        {
            char plaintext[100] ;
            int ecode ;
            printf("Text:");
            scanf("%s" , plaintext);
            printf("Code:");
            scanf("%i" , &ecode);
            char *ciphered_result = encrypt(plaintext , ecode);
            printf("Ciphertext: %s\n" , ciphered_result);
            free(ciphered_result);
            
        }

        else if (toupper(enorde) == 'D')
        {
            char ciphertext[100];
            int dcode ;
            printf("Ciphertext:");
            scanf("%s" , ciphertext);
            printf("Code:");
            scanf("%i" , &dcode);
            char *plain_result = decrypt(ciphertext , dcode);
            printf("plaintext: %s\n" ,plain_result );
            free(plain_result);
        }

        char question ;
        printf("do you want to encrypt or decrypt anything else (Y/N) ? ");
        scanf(" %c" , &question);
        if (toupper(question) == 'N')
        {
            return 0 ;
        }
    }
}



char *encrypt( char pltext[] , int encode)
{
    char *cipltext = malloc((strlen(pltext)+1) * sizeof(char));
    int len = strlen(pltext);
    cipltext[len] = '\0' ;
    for(int i = 0 ; i < len ; i++ )
    {
        cipltext[i] = pltext[i] + encode ;
    }
    return cipltext ;
}
char *decrypt( char citext[] , int decode)
{
    char *plcitext = malloc((strlen(citext)+1) * sizeof(char));
    int len = strlen(citext);
    plcitext[len] = '\0';
    for(int n = 0 ; n < len ; n++ )
    {
        plcitext[n] = citext[n] - decode ;
    }
    return plcitext;
}