#include <stdio.h>

const int PASSWORD_BUFFER_SIZE = 23;

/**
 * flushes the current and the last line in stdout
 * allowing to overwrite them
 */
void hideLastCLILine(){
    fputs("\033[A\033[2K", stdout);
    rewind(stdout);
}

/**
 * since "gets()" is very dangerous (unsafe),
 * we are using fgets, and this small wrapper to
 * improve ease of use
 */
char *fgets_wrapper(char *buffer, size_t buflen, FILE *fp)
{
    if (fgets(buffer, buflen, fp) != 0)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        return buffer;
    }
    return 0;
}

int main(void)    
{
    printf("Password Hiding Example Joschka\n");
    
    char passwordBuffer[PASSWORD_BUFFER_SIZE];
    printf("Please enter your password (and press [Enter]):");
    fgets_wrapper(&passwordBuffer, PASSWORD_BUFFER_SIZE, stdin);
    hideLastCLILine();
    printf("Thank you for providing a password.\n");
    fflush(stdout);

    printf("Press [Any Key] to show your password again..");  
    getchar(); 
    puts(passwordBuffer);
    fflush(stdout);

    return 0;
}
