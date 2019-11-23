#pragma once
#include <stdio.h>
#include <stdlib.h>

void create_root(int key, int value);

int tryFind(int key); // return 0 - поиск не удачен, 1 - удачи

int find(int key); // return value

int add(int key, int value);

void removeElem(int key);
