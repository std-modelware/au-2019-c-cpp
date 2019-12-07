#include <stdio.h>

int move(int from[], int to[]) {
	// ��������, ��� ���� ���� �� from
	if (from[0] == 0) return -1;
	// ��������� ��������� � �������� ������ �������� �������� ����� from
	int posFrom = 1;
	int valFrom = 4;


	// ��������, ��� ���� ����� �������� �� to
	// ��������� ��������� � �������� ������ �������� �������� ����� to
	int posTo = 1;
	int valTo = 4;
	if (valTo > valFrom) return -1;
	if (posTo == 10) return -1;

	// ������ �����������
	to[posTo + 1] = valFrom;
	from[posFrom] = 0;
	
	return 0;
}

void main() {
	int stick1[10];
	int stick2[10]; // = {0};
	int stick3[10];

	// ��������� ����������
	for (int j = 1; j <= 10; j++) {
		stick1[j - 1] = j;
		stick2[j - 1] = 0;
		stick3[j - 1] = 0;
	}

	int nsFrom = 1;
	int nsTo = 2;

	move(stick1, stick2);

}