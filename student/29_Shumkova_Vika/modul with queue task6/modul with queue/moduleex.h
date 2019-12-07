#pragma once

#include <stdio.h>

void auqueue_init(size_t size);
void auqueue_release();

void auqueue_enqueuefirst(char a, int prior);
void auqueue_enqueue(char a, int prior);
char auqueue_dequeue();

char auqueue_print();
int auqueue_last_error();