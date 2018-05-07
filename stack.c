#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

extern int
stackInit(intstack_t* self){
    
    if(self == 0){
        fprintf(stderr, "%s" ,"unausreichende Speicher");
        return 1;
    }
    
    (*self).top = NULL;
    
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
 
    return;
}

extern void
stackPush(intstack_t* self, int i){
    intnode_t* newTop = malloc(sizeof(intnode_t));
    
    if(newTop == 0){
        fprintf(stderr, "%s" ,"unausreichende Speicher");
        return;
    }
    
    (*newTop).next = (*self).top;
    (*newTop).value = i;
    
    (*self).top = newTop;
    
    return;
    
}
extern int
stackTop(const intstack_t* self){
    if((*self).top == 0){
        fprintf(stderr, "%s" ,"keine Elemente können aufgerufen werden Stack ist leer");
        exit(EXIT_FAILURE);
    }
    
    return (*(*self).top).value;
}

extern int
stackPop(intstack_t* self){
    if((*self).top == 0){
        fprintf(stderr, "%s" , "keine Elemente können aufgerufen werden Stack ist leer");
        exit(EXIT_FAILURE);
    }
    
    int value = (*(*self).top).value;
    
    intnode_t* oldTop = (*self).top;
        
    (*self).top = (*oldTop).next;
    
    free(oldTop);
    
    return value;
}

extern int
stackIsEmpty(const intstack_t* self){
    if ((*self).top == 0){
        return 1;
    }
    return 0;
}