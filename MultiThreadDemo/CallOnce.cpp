#include <iostream>
#include <thread>
#include <mutex>
#include "CallOnce.h"
#include "Singleton.h"
using namespace std;
std::once_flag flg;
void Initialize()
{
	std::cout << "Run into initialize..." << endl;
}

void Init()
{
	std::call_once(flg, Initialize);
}

void CallOneExcute()
{
	thread t1(Init);
	thread t2(Init);
	thread t3(Init);
	thread t4(Init);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

void CallOneSingletonExcute()
{
	thread t1(SingletonObjTask);
	
	thread t2(SingletonObjTask);
	thread t3(SingletonObjTask);
	thread t4(SingletonObjTask);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
void SingletonObjTask()
{   
	
	//this_thread::sleep_for(std::chrono::microseconds(100));
	Singleton* ptrSingletonObject = Singleton::getInstance();
}