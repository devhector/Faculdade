#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addName(char **str, int *i, int *index);

int main(){
    char **list;
    int index = 0, i = 1;




    return 0;
}

void addName(char **str, int *i, int *index){

    int length;
    char tmp[128];
    str = malloc((*i) * sizeof(char *));

    fgets(tmp, 128, stdin);

    length = strlen(tmp);

    str[*index] = malloc(length * sizeof(char)); 

    strcpy(str[*index], tmp);

    *index += 1;
    *i += 1;

}