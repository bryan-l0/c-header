#define null 0
#include <stdio.h>
#include <stdbool.h>

struct node {
    struct node* next;
    struct node* prev;
    void* value;
};

struct deque {
    struct node* head;
    struct node* tail;
};

bool is_empty(struct deque *d) {
    return d->head == null || d->tail == null;
}

void push_front(struct deque *d, struct node *n) {
    if (is_empty(d)) {
        d->head = d->tail = n;
    } else {
        n->next = d->head;
        d->head->prev = n;
        d->head = n;
    }
}

void push_back(struct deque *d, struct node *n) {
    if (is_empty(d)) {
        d->tail = d->head = n;
    } else {
        n->prev = d->tail;
        d->tail->next = n;
        d->tail = n;
    }
}

void* pop_front(struct deque *d) {
    if (is_empty(d)) {
        return null;
    }
    void* v = d->head->value;
    d->head = d->head->next;
    // if (d->head == null) {
    //     d->tail = null;
    // }
    return v;
}

void* pop_back(struct deque *d) {
    if (is_empty(d)) {
        return null;
    }
    void* v = d->tail->value;
    d->tail = d->tail->prev;
    // if (d->tail == null) {
    //     d->head = null;
    // }
    return v;
}

void* peek_front(struct deque *d) {
    return d->head->value;
}

void* peek_back(struct deque *d) {
    return d->tail->value;
}

int main() {
    struct deque d = {
        .head = null,
        .tail = null,
    };
    struct node n = {
        .next = null,
        .prev = null,
        .value = &(int){5},
    };
    struct node n1 = {
        .next = null,
        .prev = null,
        .value = &(int){7},
    };
    push_front(&d, &n);
    push_front(&d, &n1);
    pop_front(&d);
    pop_back(&d);
    printf("%d\n",*(int*)pop_front(&d));
    // printf("%d\n",is_empty(&d));
    return 1;
}