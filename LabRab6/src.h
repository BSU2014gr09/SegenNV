#pragma once

class arrStr
{
	private:
		char ** arr;
		int size;
	public:
		arrStr() : arr(nullptr) {}
		bool setStr(int);
		void getStr();
		void sort();
		int amtWordNumb(char *);
};