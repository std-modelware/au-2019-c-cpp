class Stick;

class Disk {
	int val;
	Stick stick;
	int diskPos;
	bool move(Stick to) {
		
		// поиск верхнего диска на стержне stick

		// проверка, что диск не пустой
		if (this->stick.isEmpty()) return false;

		Disk d = to.getTopDisk();
		
		// можно ли сделать перемещение?
		if (this->val > d.val) return false;

		// перемещение
		this->stick.removeTopDisk();
		to.addNewDisk(&this);
		//from[posFrom] = 0;
		//to[posTo + 1] = diskFrom;


	}
};

class Stick {
public:
	Disk disks[10];

	bool isEmpty() {
		return true;
	}
	Disk getTopDisk() {
		return Disk();
	}

	void removeTopDisk() {

	}

	void addNewDisk(Disk d) {

	}
};

