#pragma once

#include <stdio.h>

void auqueue_init(size_t size);
void auqueue_release();

void auqueue_enqueue(char i);
char auqueue_dequeue();

char auqueue_print();



