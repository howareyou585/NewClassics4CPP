#include "PromiseUsage.h"
#include <thread>
#include <iostream>
#include <future>
using namespace std;

void PromiseFunc(promise<int> &ps)
{

	thread t([&]() {
		cout << " start thread id =" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		ps.set_value(100);
		cout << " end thread id =" << this_thread::get_id() << endl;
		});
	
	t.join();//必须要调用join方法，否则程序会崩溃。
	promise<int> tmpps;
	int b = 66;
	thread t2(PrintOfPromise, ref(tmpps), ref(b));
	t2.join(); //必须调用join方法，否则程序崩溃。
	auto myFuture = tmpps.get_future();
	auto retOfPS = myFuture.get();
	cout << "retOfPS = " << retOfPS << endl;
	
}

int PrintOfPromise(promise<int>&ps, int& a)
{
	cout << "PrintOfPromise start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	a++;
	ps.set_value(a); //如果忘记该语句，PrintOfPromise就无法退出。
	cout << "PrintOfPromise end thread id =" << this_thread::get_id() << endl;
	
	return a;
}

void FutureGetDataThreadFunc(future<int>& fe)
{
	cout << "FutureGetDataThreadFunc start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	
	auto ret = fe.get();
	cout << "result of FutureGetDataThreadFunc:" << ret << endl;
	cout << "FutureGetDataThreadFunc end thread id =" << this_thread::get_id() << endl;
}

void PromisePrepareDataThreadFunc(promise<int>& ps)
{
	cout << "PromisePrepareDataThreadFunc start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));

	ps.set_value(1000); //如果忘记该语句，PrintOfPromise就无法退出。
	cout << "PromisePrepareDataThreadFunc end thread id =" << this_thread::get_id() << endl;
}
