#pragma once
void au_init(size_t sz);
void au_release();

void au_push(char i);
char au_pop();

int au_get_last_error();
void au_print();