#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/**
 * @brief Checkt wenn der Zeiger NULL ist.
 * @param pointer der zu checkende Zeiger.
 */
void pointerCheck(void* pointer)
{
    if (pointer == NULL)
    {
        perror("Der Zeiger soll nicht NULL sein.\n");
        exit(EXIT_FAILURE);
    }
}

extern int
stackInit(intstack_t* self)
{
    pointerCheck(self);
    // Das ist wichtig, dass das “next” des erstes Knots leer ist.
    self->top = NULL;
    return 0;
}

extern void
stackRelease(intstack_t* self)
{
    pointerCheck(self);
    intnode_t* nodeToRelease = self->top;
    intnode_t* nextNodeToRelease = NULL;
    while (nodeToRelease != NULL)
    {
        nextNodeToRelease = nodeToRelease->next;
        free(nodeToRelease);
        nodeToRelease = nextNodeToRelease;
    }
}

extern void
stackPush(intstack_t* self, int i)
{
    pointerCheck(self);
    intnode_t* newTop = (intnode_t*)malloc(sizeof(intnode_t));
    pointerCheck(newTop);
    newTop->value = i;
    newTop->next = self->top;
    self->top = newTop;
}

extern int
stackTop(const intstack_t* self)
{
    if (self->top == NULL)
    {
        fprintf(stderr,"<<Fehlermeldung, da intstack_t leer>>");
        exit(EXIT_FAILURE);
    }
    return self->top->value;
}

extern int
stackPop(intstack_t* self)
{
    if (self->top == NULL)
    {
        fprintf(stderr,"<<Fehlermeldung, da intstack_t leer>>");
        exit(EXIT_FAILURE);
    }
    int value = self->top->value;
    intnode_t* newTop = self->top->next;
    free(self->top);
    self->top = newTop;
    return value;
}

extern int
stackIsEmpty(const intstack_t* self)
{
    return (self->top == NULL);
}

extern void
stackPrint(const intstack_t* self)
{
    pointerCheck((void*)self);
    intnode_t* nodeToPrint = self->top;
    unsigned long count = 0;
    while (nodeToPrint != NULL)
    {
        printf("%d\t",nodeToPrint->value);
        count++;
        if(count % 10 == 0)
        {
            puts("");
        }
        nodeToPrint = nodeToPrint->next;
    }
}

extern unsigned long
stackCount(intstack_t* self)
{
    pointerCheck(self);
    intnode_t* nodeToCount = self->top;
    unsigned long count = 0;
    while (nodeToCount != NULL)
    {
        nodeToCount = nodeToCount->next;
        count++;
    }
    return count;
}
