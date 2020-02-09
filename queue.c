#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

#ifndef strlcpy
#define strlcpy(dst, src, sz) snprintf((dst), (sz), "%s", (src))
#endif

list_ele_t *tmp;

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if (q) {
        q->head = NULL;
        q->tail = NULL;
        q->size = q_size(q);
        return q;
    }

    return NULL;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */

    if (q) {
        if (q->head) {
            while (q->head != NULL) {
                tmp = q->head;
                q->head = q->head->next;

                free(tmp->value);
                free(tmp);
            }
        }

        free(q);
    }
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));

    int s_size = sizeof(s) * sizeof(char *);

    /* TODO: What should you do if the q is NULL? */
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */

    if (newh) {
        newh->next = q->head;
        q->head = newh;

        newh->value = malloc(s_size);

        if (newh->value) {
            /*use strlcpy instead*/
            strlcpy(newh->value, s, s_size);
            q->size += 1;
            if (q->size == 1)
                q->tail = q->head;
            return true;
        }
    }

    return false;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */

    list_ele_t *newl;
    newl = malloc(sizeof(list_ele_t));

    int s_size = sizeof(s) * sizeof(char *);

    if (newl) {
        newl->next = NULL;
        newl->value = malloc(s_size);

        if (q->tail) {
            q->tail->next = newl;
        }

        if (newl->value) {
            q->tail = newl;
            /*use strlcpy instead*/
            strlcpy(newl->value, s, s_size);
            q->size += 1;
            if (q->size == 1)
                q->head = q->tail;
            return true;
        }
    }

    free(newl);

    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */

    if (q && q->head) {
        if (sp) {
            /*using strlcpy instead*/
            strlcpy(sp, q->head->value, bufsize);
        }
        tmp = q->head;
        q->head = q->head->next;
        q->size -= 1;

        if (!(q->head))
            q->tail = q->head;

        free(tmp->value);
        free(tmp);

        return true;
    }

    return false;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q && q->head)
        return q->size;

    return 0;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
    if (q && q->head && q->head != q->tail) {
        list_ele_t *headl = NULL, *headr = q->head->next;

        q->tail = q->head;

        while (headr) {
            q->head->next = headl;
            headl = q->head;
            q->head = headr;
            headr = q->head->next;
        }
        q->head->next = headl;
    }
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
