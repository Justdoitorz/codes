#pragma once
#include<iostream>
using namespace std;
template <typename T>
class MyVector
{
public:
	MyVector(int i);
	MyVector(T *mp,int len);
	MyVector(MyVector &mv);
	~MyVector();
	MyVector& operator=(MyVector &mv);
	friend ostream& operator << (ostream& out,MyVector &mv);
	T& operator[](int i);
public:
	int getLen();
private:
	int m_len;
	T *m_p;
};