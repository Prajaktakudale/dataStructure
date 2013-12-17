#include "stack_without_memcpy.h"
#include <stdlib.h>
#include <memory.h>

void dispose(Stack* p_to_stack){
    free(p_to_stack->base_element);
    free(p_to_stack);
};

Stack* create_stack(int size){
    Stack* p_to_stack = calloc(1,sizeof(Stack));
    p_to_stack->base_element = calloc(size,sizeof(void*));
    p_to_stack->size = size;
    p_to_stack->top = 0;
    return p_to_stack;
};

int isEmpty(Stack* p_to_stack){
    return p_to_stack->top == 0;
};

void* top(Stack* p_to_stack){
    void* top;
    if(isEmpty(p_to_stack)) 
    	return NULL;
    top = *(p_to_stack->base_element + p_to_stack->top-1);
    return top;
};