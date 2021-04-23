#include"MyVector.h"
template<typename T>
MyVector<T>::MyVector(int i)
{
	this->m_len = i;
	this->m_p = new T[m_len];
}
template<typename T>
MyVector<T>::MyVector(T *mp,int len)//���캯��
{
	this->m_len = len;
	this->m_p = new T[m_len];
	for (int i = 0; i < m_len; i++)
	{
		this->m_p[i] = mp[i];
	}
}
template<typename T>
MyVector<T>::MyVector(MyVector<T> &mv)//�������캯��
{
	this->m_len = mv.m_len;
	this->m_p = new T[m_len];
	for (int i=0;i<mv.m_len;i++)
	{
		this->m_p[i] = mv.m_p[i];
	}
}

template<typename T>
MyVector<T>::~MyVector()//��������
{
	cout << "��������" << endl;
}
///////////////////////////////////////////////////////////////////
template<typename T>
int MyVector<T>::getLen()//��ȡ����
{
	return this->m_len;
}
template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> &mv)//����=
{
	this->m_len = mv.m_len;
	this->m_p = new T[m_len];
	for (int i = 0; i < mv.m_len; i++)
	{
		this->m_p[i] = mv.m_p[i];
	}
	return *this;
}
template<typename T>
T& MyVector<T>::operator[](int i)//����[]
{
	return this->m_p[i];
}
template<typename T>
ostream& operator<<(ostream &out,MyVector<T> &mv)//����<<
{
	out << mv->m_p<<endl;
	return out;
}