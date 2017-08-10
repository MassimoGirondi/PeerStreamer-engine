/*
 *
 *  copyright (c) 2017 luca baldesi
 *
 */

#ifndef __ORD_SET__
#define __ORD_SET__

#define ORD_SET_INC_SIZE 10

#include<stdint.h>

#define ord_set_for_each(iter, set)\
	for((iter) = NULL; ((iter) = ord_set_iter((set), (iter)));)

#define ord_set_for_each_safe(iter, set, tmp)\
	for((tmp) = NULL, (iter) = NULL; ((iter) = ord_set_iter_safe((set), (iter), &(tmp)));)

typedef uint32_t ord_set_size;

typedef int8_t (*cmp_func_t)(const void *, const void *);

struct ord_set;

struct ord_set * ord_set_new(ord_set_size size, cmp_func_t cmp);

void ord_set_destroy(struct ord_set ** os, uint8_t free_elements);

/* ord_set_insert
 * if element el is present it is overridden if override = 1
 * it returns the element in the set for the given equivalence class
 */
void * ord_set_insert(struct ord_set * os, void * el, uint8_t override);

const void * ord_set_iter(const struct ord_set * os, const void * iter);

void * ord_set_iter_safe(struct ord_set * os, void * iter, void ** tmp);

ord_set_size ord_set_length(const struct ord_set * os);

void * ord_set_find(const struct ord_set * os, const void * el);

uint8_t ord_set_remove(struct ord_set * os, const void * el, uint8_t free_element);

int8_t ord_set_dummy_cmp(const void * p1, const void * p2);

#endif
