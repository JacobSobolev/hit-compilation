#include "Vector.h"

void CreateVector(Vector *vec)
{
    vec->index = 0;
    vec->tokens = malloc(sizeof(Token**));;
    vec->size = 0;
}

void DeleteVector(Vector* vec)
{
    int i;
    for(i = 0; i < vec->index; i++){
		if(vec->tokens[i] != NULL) {
            free(vec->tokens[i]);
        }
	}
    free(vec->tokens);
}


void TokenAdd(Vector *vec, Token* value)
{
    vec->index++;
    if (vec->index > vec->size)
    {
        vec->size = (++vec->size) * 2;
        vec->tokens = realloc(vec->tokens, sizeof(Token*) * (vec->size));
    }

    vec->tokens[vec->index-1] = value;
    
}

void TokenDelete(Vector *vec, int index)
{
    int i;
    if (index < 0 || index >= vec->size)
    {
        return;
    }
    for (i = index; i < vec->size - 1; i++)
    {
        vec->tokens[i] = vec->tokens[i + 1];
    }
    free(&vec->tokens[vec->size-1]);
    vec->size--;
    vec->tokens = realloc(vec->tokens, sizeof(Token*) * vec->size);
}
