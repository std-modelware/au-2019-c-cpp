#pragma once
#include <stdio.h>

void aupqueue_init(size_t size);
void aupqueue_release();
void aupqueue_enqueue(char elem, int priority);
char aupqueue_dequeue();

char aupqueue_print();
void aupqueue_last_error();