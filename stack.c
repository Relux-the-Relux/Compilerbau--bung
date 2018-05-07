#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

extern int
stackInit(intstack_t* self){
    
    self = malloc(sizeof(intstack_t));
    
    if(self == 0){
        return 1;
    }
    
    (*self).top = 0;
    
    return 0;
}

static int
nodeInit(intnode_t* self, int value){
    
    self = malloc(sizeof(intstack_t));
    
    if(self == 0){
        return 1;
    }
    
    (*self).next = 0;
    (*self).value = value;
    
    return 0;
    
}

/**
 * @bref Gibt frei die 
 * @param self
 */
extern void
nodeRelease(intnode_t* self) {
    if ( (*self).next != 0) {
        nodeRelease((*self).next);
    }
    free(self);
    return;
}

extern void
stackRelease(intstack_t* self){
    
    if ((*self).top != 0){
        nodeRelease((*self).top);
    }
    
    free(self);
    
    return;
}

extern void
stackPush(intstack_t* self, int i){
    intnode_t* newTop = malloc(sizeof(intnode_t));
    
    nodeInit(newTop, i);
  
    (*newTop).next = (*self).top;
    
    (*self).top = newTop;
    
    return;
    
}
extern int
stackTop(const intstack_t* self){
    if((*self).top == 0){
        fprintf(stderr, "keine Elemente können aufgerufen werden Stack ist leer");
    }
    
    return (*(*self).top).value;
}

extern int
stackPop(intstack_t* self){
    if((*self).top == 0){
        fprintf(stderr, "keine Elemente können aufgerufen werden Stack ist leer");
    }
    
    int value = (*(*self).top).value;
    
    intnode_t* oldTop = (*self).top;
    (*self).top = (*oldTop).next;
    
    free(oldTop);
    
    return value;
}

extern int
stackIsEmpty(const intstack_t* self){
    if (self == 0){
        return 1;
    }
    return 0;
}