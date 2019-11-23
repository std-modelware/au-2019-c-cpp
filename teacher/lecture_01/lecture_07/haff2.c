int freq[256]; // обнулить

char c; // очередной символ
freq[c]++;

struct Node {
	int freq;
	char symbol;
	int index; // = -1 - не находится в дереве
	int code; // 1 или 0
};

struct Node tree[n + n - 1];

// цикл по freq[]
// создаем Node и кладем в tree
// будут заняты первые n ячеек

// --------------->
// поиск двух мин элементов в tree (у которых node.index == -1)

// создание нового узла
// <-----------------
