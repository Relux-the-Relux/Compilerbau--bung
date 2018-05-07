
#include "stack.h"


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

stackRelease(intstack_t* self){
    
    if ((*self).top != 0){
        nodeRelease(intnode_t* (*self).top);
    }
    
    free(self);
    
    return;
}

/**
 * @bref Gibt frei die 
 * @param self
 */
static void
nodeRelease(intnode_t* self) {
    if ( (*self).next != 0) {
        nodeRelease((*self).next);
    }
    free(self);
    return;
}

stackPush(intstack_t* self, int i){
    intnode_t* newTop = malloc(sizeof(intnode_t));
    
    nodeInit(newTop, i);
  
    (*newTop).next = (*self).top;
    
    (*self).top = newTop;
    
    return;
    
}

stackTop(const intstack_t* self){
    if((*self).top = 0){
        fprintf(stderr, "keine Elemente können aufgerufen werden Stack ist leer");
    }
    
    return (*(*self).top).value;
}

stackPop(intstack_t* self){
    if((*self).top = 0){
        fprintf(stderr, "keine Elemente können aufgerufen werden Stack ist leer");
    }
    
    int value = (*(*self).top).value;
    
    intnode_t* oldTop = (*self).top;
    (*self).top = (*oldTop).next;
    
    free(oldTop);
    
    return value;
}

stackIsEmpty(const intstack_t* self){
    if (self == 0){
        return 1;
    }
    return 0;
}