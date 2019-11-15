#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void auqueue_init(size_t size);
void auqueue_release();

void auqueue_enqueue(char a, int p); 
char auqueue_dequeue(); 

char auqueue_print(); 

int getLastError(int i);