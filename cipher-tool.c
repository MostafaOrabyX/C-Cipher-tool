#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *encrypt(char pltext[] , int encode);
char *decrypt( char citext[] , int decode);
void cleanbuffer();

int main()
{
    while(1)
    {
        char en_or_de ;
        printf("Enter the first letter\nEncrypt(E) or Decrypt(D):");
        if (scanf(" %c", &en_or_de) != 1)
        {
            printf("invalid input\n");
            cleanbuffer();
            continue;
        }
        
        if (toupper(en_or_de) == 'E')
        {
            char plaintext[100] ;
            int ecode ;
            // get the plaintext from the user
            printf("Text:");
            scanf("%s" , plaintext);
            // get the code from the user
            printf("Code:");
            scanf("%i" , &ecode);
            // encrpt the text then print it
            char *ciphered_result = encrypt(plaintext , ecode);
            // check for NULL
            if ( ciphered_result != NULL)
            {
                printf("Ciphertext: %s\n" , ciphered_result);
                free(ciphered_result);
            }
            else
            {
                printf("encryption failed\n");
            }
            
        }

        else if (toupper(en_or_de) == 'D')
        {
            char ciphertext[100];
            int dcode ;
            // get the ciphertext from the user
            printf("Ciphertext:");
            scanf("%s" , ciphertext);
            // get the code from the user
            printf("Code:");
            scanf("%i" , &dcode);
            // decrypt the text then print it
            char *plain_result = decrypt(ciphertext , dcode);
            //check for NULL
            if ( plain_result != NULL )
            {
                printf("plaintext: %s\n" ,plain_result );
                free(plain_result);
            }
            else
            {
                printf("decryption failed\n");
            }

        }

        // if the user want to exit 
        char question ;
        printf("Do you want to encrypt or decrypt anything else (y/n):");
        if (scanf(" %c" , &question) != 1)
        {
            printf("invalid input\n");
            cleanbuffer();
            continue;
        }

        if (toupper(question) == 'N')
        {
           return 0 ;
        }
    }
}



// encryption function
char *encrypt( char pltext[] , int encode)
{
    // get space from the memory for the ciphertext
    char *ciphered_plain_text = malloc((strlen(pltext)+1) * sizeof(char));
    if (ciphered_plain_text == NULL )
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    int len = strlen(pltext);
    ciphered_plain_text[len] = '\0' ;
    // encrypt every char and put it in ciphered_plain_text 
    for(int i = 0 ; i < len ; i++ )
    {
        ciphered_plain_text[i] = pltext[i] + encode ;
    }

    // return the ciphered text
    return ciphered_plain_text ;
}

// decryption function
char *decrypt( char citext[] , int decode)
{
    // get space from the memory for the plaintext
    char *de_ciphered_text = malloc((strlen(citext)+1) * sizeof(char));
    if ( de_ciphered_text == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    int len = strlen(citext);
    de_ciphered_text[len] = '\0';
    // decrypt every char and put it in de_ciphered_text
    for(int n = 0 ; n < len ; n++ )
    {
        de_ciphered_text[n] = citext[n] - decode ;
    }

    // return the deciphered text
    return de_ciphered_text;
}

// clean_buffer function
void cleanbuffer()
{
    while (getchar() != '\n'); // clean the input buffer
}