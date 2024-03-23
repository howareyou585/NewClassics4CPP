#include "AsyncFuture.h"
#include <thread>
#include <iostream>
using namespace std;
int AsyncPrint()
{
	
	cout << "AsyncPrint() start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "AsyncPrint() end thread id =" << this_thread::get_id() << endl;
	return 100;
}

void AsyncPrintWithoutRetValue()
{
	cout << "AsyncPrintWithoutRetValue() start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "AsyncPrintWithoutRetValue() end thread id =" << this_thread::get_id() << endl;
}

int AsyncFuture::ThreadFunc(int a)
{
	cout << "AsyncFuture::ThreadFunc() start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "AsyncFuture::ThreadFunc() end thread id =" << this_thread::get_id() << endl;
	m_value = a;
	return m_value;
}
