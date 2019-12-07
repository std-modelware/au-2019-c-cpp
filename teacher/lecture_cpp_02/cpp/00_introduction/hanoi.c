
#define DISK_COUNT 10


int move(int from[], int to[]) {
	// ����� �������� ����� �� ������� from
	
	// ��������, ��� ���� �� ������
	if (from[0] == 0) return -1;
	int posFrom = 2; // ������� �������� ����� �� ������� from
	int diskFrom = 3; // ������ �������� ���� from

	// ����� �������� ����� �� ������� to
	int posTo = 4; // ������� �������� ���� �� ������� to
	int diskTo = 5; // ������ �������� ���� to

	// ����� �� ������� �����������?
	if (diskFrom > diskTo) return -1;

	// �����������
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