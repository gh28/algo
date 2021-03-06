#include <assert.h>
#include <stdlib.h>

Iterator * Iterator_malloc() {
    Iterator * self = calloc(1, sizeof(Iterator));
    self->head = LinkNode_malloc(0);
    self->current = self->head;
    return self;
}

void Iterator_free(Iterator * self) {
    assert(self != NULL);
    assert(self->head != NULL);
    while (self->head->next != NULL) {
        LinkNode * p = LinkNode_removeNext(self->head);
        LinkNode_free(p);
    }
    LinkNode_free(self->head);
    self->head = NULL;
    free(self);
    self = NULL;
}

boolean Iterator_hasNext(Iterator * self) {
    assert(self != NULL);
    assert(self->current != NULL);
    return self->current->next != NULL;
}

int64 Iterator_next(Iterator * self) {
    self->current = self->current->next;
    return self->current->value;
}
