#include "AtomUsage.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <atomic>
using namespace std;
atomic <int> g_value = 0;
mutex m;
void ReaderAndWriterGV()
{
	thread t1(ReadWriteThread);
	thread t2(ReadWriteThread);
	t1.join();
	t2.join();
	
	cout << "g_value=" << g_value << endl;
}

void ReadWriteThread()
{
	cout << "ReadWriteThread() start thread id =" << this_thread::get_id() << endl;
	for (int i = 0; i < 10000000; i++)
	{
		//lock_guard<mutex>lg(m);
		g_value++;
	}
	cout << "ReadWriteThread() end thread id =" << this_thread::get_id() << endl;
}
