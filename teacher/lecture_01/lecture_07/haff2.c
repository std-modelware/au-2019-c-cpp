int freq[256]; // ��������

char c; // ��������� ������
freq[c]++;

struct Node {
	int freq;
	char symbol;
	int index; // = -1 - �� ��������� � ������
	int code; // 1 ��� 0
};

struct Node tree[n + n - 1];

// ���� �� freq[]
// ������� Node � ������ � tree
// ����� ������ ������ n �����

// --------------->
// ����� ���� ��� ��������� � tree (� ������� node.index == -1)

// �������� ������ ����
// <-----------------
