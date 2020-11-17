#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main(){

    void *pBuffer = createList();

    menu(pBuffer);

    clear(pBuffer);    
    
    return 0;

}
