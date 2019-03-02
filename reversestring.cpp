#include<stdio.h>

char* revstring(int len, char str[]){
    while(*str != '\0'){
        str++;
    }
    static char rchar[30];
    int i = 0;
    str--;
    while(*str != '\0'){
        rchar[i] = *str;
        //printf("%c",*str);
        i++;
        str--;
    }
    return rchar;
}




int main(){
    char str[30];
    printf("Enter the String: ");
    scanf("%s",&str);
    int len = sizeof(str);
    printf("%s",revstring(len, str));
}


