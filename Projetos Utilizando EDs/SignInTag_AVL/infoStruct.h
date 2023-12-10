#ifndef INFOSTRUCT_H_INCLUDED
#define INFOSTRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tagSize 9

struct _info
{
    char tag[tagSize];
    int status;
};

typedef struct _info Info;
typedef Info Tipo_Dado;

#endif // INFOSTRUCT_H_INCLUDED
