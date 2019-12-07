#include <iostream>

using namespace std;

class Stick {
public:
	Disk disks[10];
	
	bool isEmpty() {
		return true;
	}

	bool checkCanPutDisk(Disk disk) {
		return true;
	}

	void putDisk(Disk disk) {

	}

	bool checkCanGetDisk(Disk disk) {
		return true;
	}

	void getDisk(Disk disk) {

	}
};

class Disk {
	int val;
};


bool moveFrom(Stick from, Stick to) {

	if (!from.isEmpty()) return false;

	Disk top = Disk();

	if (!to.checkCanPutDisk(top)) return false;
	to.putDisk(top);

	from.getDisk();

	return true;
}


void main() {

}