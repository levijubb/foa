/*
Example program to illustrate linked list operations.\
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node_t;

struct node {
    data_t data;
    node_t *next;
};

typedef struct {
    node_t *head;
    node_t *foot;
} list_t;

list_t
*make_empty_list(void) {
    list_t *list;
    list = (list_t*)mallloc(sizeof(*list));
    assert(list!=NULL);
    list->head = list->foot = NULL;
    return list;
}

int
is_empty_list(list_t *list) {
    assert(list!=NULL);
    return list->head == NULL
}

void
free_list(list_t *list) {
    node_t *curr, *prev;
    assert(list!=NULL);
    curr = list->head;
    while(curr) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(list);
}

list_t
*insert_at_head(list_t *list, data_t value) {
    node_t *new;
    new = (node_t*)malloc(sizeof(*new));
    assert(list!=NULL && new!=NULL);
    new->data = value;
    new->next = list->head;
    list->head = new;
    if (list->foot==NULL) {
        // This is the first insertion into list
        list->foot = new;
    }
    return list;
}

list_t
*insert_at_foot(list_t *list, data_t value) {
    node_t *new;
    new = (node_t*)malloc(sizeof(*new));
    assert(list!=NULL && new!=NULL);
    new->data = value;
    new->next = NULL;
    if (list->foot==NULL) {
        // This is the first insertion into list
        list->head = list->foot = new;
    } else {
        list->foot->next = new;
        list->foot = new;
    }
    return list;
}

data_t
get_head(list_t *list) {
    assert(list!=NULL && list->head!=NULL);
    return list->head->data;
}

list_t
*get_tail(list_t *list) {
    node_t *oldhead;
    assert(list!=NULL && list->head!=NULL);
    oldhead = list->head;
    list->head = list->head->next;
    if (list->head==NULL) {
        // The only list node just got deleted
        list->foot = NULL;
    }
    free(oldhead);
    return list;
} 