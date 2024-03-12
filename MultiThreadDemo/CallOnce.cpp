#include <iostream>
#include <thread>
#include <mutex>
#include "CallOnce.h"
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
