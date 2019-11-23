
#define DISK_COUNT 10


int move(int from[], int to[]) {
	// поиск верхнего диска на стержне from
	
	// проверка, что диск не пустой
	if (from[0] == 0) return -1;
	int posFrom = 2; // позиция верхнего диска на стержне from
	int diskFrom = 3; // размер верхнего диск from

	// поиск верхнего диска на стержне to
	int posTo = 4; // позиция верхнего диск на стержне to
	int diskTo = 5; // размер верхнего диск to

	// можно ли сделать перемещение?
	if (diskFrom > diskTo) return -1;

	// перемещение
	from[posFrom] = 0;
	to[posTo + 1] = diskFrom;
}

void main() {

	int stick1[DISK_COUNT];
	int stick2[DISK_COUNT];
	int stick3[DISK_COUNT];

	for (int i = 0; i < DISK_COUNT; i++) {
		stick1[i] = DISK_COUNT - i;
		stick2[i] = 0;
		stick3[i] = 0;
	}

	move(stick1, stick2);
}