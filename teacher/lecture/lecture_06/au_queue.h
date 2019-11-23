#pragma once
#include <stdio.h>

void au_init(size_t sz);
void au_release();

void au_enqueue(char i);
char au_dequeue();

void au_print();