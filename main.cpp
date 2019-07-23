#include <iostream>

using namespace std;

int main()
{

	int zippo[4][2] = { 0, };
	int(*zippo_ptr)[2] = zippo;
	int(*zippo_pptr)[4][2] = &zippo;

	cout << "zippo_ptr      : " << zippo_ptr << endl;
	cout << "zippo_ptr + 1  : " << zippo_ptr + 1 << endl << endl;

	cout << "zippo_pptr     : " << zippo_pptr << endl;
	cout << "zippo_pptr + 1 : " << zippo_pptr + 1 << endl << endl;	
	
	cout << "&zippo[0][0]	 : " << &zippo[0][0] << endl;
	cout << "&zippo[0][0] + 1: " << &zippo[0][0] + 1 << endl << endl;	
	
	cout << "zippo[0][0]	 : " << zippo[0][0] << endl;
	cout << "zippo[0][0] + 1 : " << zippo[0][0] + 1 << endl << endl;	

	cout << "&zippo[0]     : " << &zippo[0] << endl;
	cout << "&zippo[0] + 1 : " << &zippo[0] + 1 << endl << endl;	
	
	cout << "zippo[0]      : " << zippo[0] << endl;
	cout << "zippo[0] + 1  : " << zippo[0] + 1 << endl << endl;		
	
	cout << "*zippo[0]     : " << *zippo[0] << endl;
	cout << "*zippo[0] + 1 : " << *zippo[0] + 1 << endl << endl;	

	cout << "&zippo        : " << &zippo << endl;
	cout << "&zippo + 1    : " << &zippo + 1 << endl << endl;	
	
	cout << "zippo         : " << zippo << endl;
	cout << "zippo + 1     : " << zippo + 1 << endl << endl;

	cout << "sizeof(int[2]): " << sizeof(int[2]) << endl;
	cout << "sizeof(int(*)[2]): " << sizeof(int(*)[2]) << endl;
	cout << "sizeof(int[4][2]): " << sizeof(int[4][2]) << endl;
	cout << "sizeof(int(*)[4][2]): " << sizeof(int(*)[4][2]) << endl << endl;
	
	cout << "zippo        : " << typeid(zippo).name() << endl;
	cout << "&zippo       : " << typeid(&zippo).name() << endl;
	cout << "*zippo       : " << typeid(*zippo).name() << endl;
	cout << "zippo[i]     : " << typeid(zippo[0]).name() << endl;
	cout << "&zippo[i]    : " << typeid(&zippo[0]).name() << endl;
	cout << "*zippo[i]    : " << typeid(*zippo[0]).name() << endl;
	cout << "zippo[i][j]  : " << typeid(zippo[0][0]).name() << endl;
	cout << "&zippo[i][j] : " << typeid(&zippo[0][0]).name() << endl;

	return 0;
}