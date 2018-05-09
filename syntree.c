//
// Created by Zhirui Dai on 2018/5/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "syntree.h"

void pointerCheck(void* pointer)
{
    if (pointer == NULL)
    {
        fprintf(stderr, "Der Zeiger soll nicht NULL sein.\n");
        exit(EXIT_FAILURE);
    }
}

extern int
syntreeInit(syntree_t* self)
{
    pointerCheck(self);
    self->root = NULL;
    return 0;
}

void
synnodeInit(synnode_t* node, int number)
{
    pointerCheck(node);
    node->next = NULL;
    node->firstChild = NULL;
    node->content = number;
}

void
synnodeRelease(synnode_t* self)
{
    pointerCheck(self);
    while (self->firstChild != NULL)
    {
        synnode_t* nextChild = self->firstChild->next;
        synnodeRelease(self->firstChild);
        // Now the second child becomes the first one.
        self->firstChild = nextChild;
    }
    free(self);
}

extern void
syntreeRelease(syntree_t* self)
{
    pointerCheck(self);
    if (self->root != NULL)
    {
        synnodeRelease(self->root);
        self->root = NULL;
    }
}

extern syntree_nid
syntreeNodeNumber(syntree_t* self, int number)
{
    pointerCheck(self);
    synnode_t* newNode = (synnode_t*)malloc(sizeof(synnode_t));
    pointerCheck(newNode);
    synnodeInit(newNode, number);
    return newNode;
}

extern syntree_nid
syntreeNodeTag(syntree_t* self, syntree_nid id)
{
    pointerCheck(self);
    pointerCheck(id);

    synnode_t* newListNode = (synnode_t*)malloc(sizeof(synnode_t));
    pointerCheck(newListNode);

    synnodeInit(newListNode, 0);
    newListNode->firstChild = id;
    self->root = newListNode;

    return newListNode;
}

extern syntree_nid
syntreeNodePair(syntree_t* self, syntree_nid id1, syntree_nid id2)
{
    pointerCheck(self);
    pointerCheck(id1);
    pointerCheck(id2);

    synnode_t* newListNode = (synnode_t*)malloc(sizeof(synnode_t));
    pointerCheck(newListNode);

    synnodeInit(newListNode, 0);
    newListNode->firstChild = id1;
    id1->next = id2;
    self->root = newListNode;

    return newListNode;
}

extern syntree_nid
syntreeNodeAppend(syntree_t* self, syntree_nid list, syntree_nid elem)
{
    pointerCheck(self);
    pointerCheck(list);
    pointerCheck(elem);

    synnode_t* lastChild = list->firstChild;
    if (list->firstChild != NULL)
    {
        while (lastChild->next != NULL)
        {
            lastChild = lastChild->next;
        }
        lastChild->next = elem;
    } else {
        list->firstChild = elem;
    }

    return list;
}

extern syntree_nid
syntreeNodePrepend(syntree_t* self, syntree_nid elem, syntree_nid list)
{
    pointerCheck(self);
    pointerCheck(list);
    pointerCheck(elem);

    elem->next = list->firstChild;
    list->firstChild = elem;

    return list;
}

extern void
syntreePrint(const syntree_t* self, syntree_nid root)
{
    pointerCheck((void*)self);
    pointerCheck(root);

    if(root->firstChild != NULL)
    {
        putchar('{');
        synnode_t* childToPrint = root->firstChild;
        while (childToPrint != NULL)
        {
            syntreePrint(self, childToPrint);
            childToPrint = childToPrint->next;
        }
        putchar('}');
    } else {
        printf("(%d)",root->content);
    }
}

extern void
syntreePrintf(const syntree_t* self, syntree_nid root)
{
    static int tabCount = 0;
    pointerCheck((void*)self);
    pointerCheck(root);

    if(root->firstChild != NULL)
    {
        for (int i = 0; i < tabCount; ++i) {
            putchar('\t');
        }
        puts("{");
        tabCount++;
        synnode_t* childToPrint = root->firstChild;
        while (childToPrint != NULL)
        {
            syntreePrintf(self, childToPrint);
            childToPrint = childToPrint->next;
        }
        tabCount--;
        for (int i = 0; i < tabCount; ++i) {
            putchar('\t');
        }
        puts("}");
    } else {
        for (int i = 0; i < tabCount; ++i) {
            putchar('\t');
        }
        printf("(%d)\n",root->content);
    }
}
