#include "AsyncFuture.h"
#include <thread>
#include <iostream>
#include <future>
using namespace std;
int AsyncPrint()
{
	
	cout << "AsyncPrint() start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "execute AsyncPrint function" << endl;
	cout << "AsyncPrint() end thread id =" << this_thread::get_id() << endl;
	return 100;
}

//没有返回值的函数不能用feture.get() /feture.wait(); 
void AsyncPrintWithoutRetValue()
{
	cout << "AsyncPrintWithoutRetValue() start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "AsyncPrintWithoutRetValue() end thread id =" << this_thread::get_id() << endl;
}

void CreateAsyncThread()
{	
	cout<<"CreateAsyncThread() start thread id =" << this_thread::get_id() << endl; 
	auto resultAsync = async(AsyncPrint);
	auto ret = resultAsync.get();
	cout << "result of CreateAsyncThread : " << ret << endl;
	cout <<"CreateAsyncThread() end thread id =" << this_thread::get_id() << endl;
	
}

int AsyncFuture::ThreadFunc(int a)
{
	cout << "AsyncFuture::ThreadFunc() start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "AsyncFuture::ThreadFunc() end thread id =" << this_thread::get_id() << endl;
	m_value = a;
	return m_value;
}
