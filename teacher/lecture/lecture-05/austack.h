#pragma once
#include <stdio.h>

void au_init(size_t sz);
void au_release();

void au_push(char i);
char au_pop();

void au_print();
int au_get_last_error();