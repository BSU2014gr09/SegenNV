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
		void sort(bool );
		int amtWordNumb(char *);
		~arrStr()
		{
			for (int i = 0; i < size; i++)
				delete[] arr[i];
			delete[] arr;
		}
};