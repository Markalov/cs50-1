#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"

int 
main(int argc, char* argv[])
{
    if(argc != 2)
        printf("Usage: ./test2 [dict_file]\n");

    char* dict = argv[1];
    bool loaded = load(dict);
    
    if(loaded)
        printf("Loaded!\n");
}
