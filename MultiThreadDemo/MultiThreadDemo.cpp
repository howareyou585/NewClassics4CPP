// MultiThreadDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CallOnce.h" 
#include "MessageQueueConditionVariable.h"
#include "AsyncFuture.h"
#include "PackageTask.h"
#include "PromiseUsage.h"
#include <thread>
#include <future>
using namespace std;
//测试 asyn future的示例
void testAsynFuture()
{
	//1.异步函数是一般函数
	//auto fetureResult = async(AsyncPrint); //AsynPrint有返回值
	//
	//auto res = fetureResult.get();
	//cout << "res = " << res << endl;

	//auto fetureResultWithoutRetVal = async(AsyncPrintWithoutRetValue);
	//AsyncPrintWithoutRetValue 函数没有返回值，不能调用wait / get 方法
	//fetureResultWithoutRetVal.wait(); 
	//2.异步函数是类的成员函数
	/*AsyncFuture af;
	auto fetureObject = std::async(&AsyncFuture::ThreadFunc, ref(af), 5);
	auto fres = fetureObject.get();
	cout << "af.m_val = " << af.GetVal() << endl;*/

	//3.异步函数是lamda 表达是
	/*auto lamdaFeture = std::async([]() {
		cout << "lamda start thread id =" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "lamda end thread id =" << this_thread::get_id() << endl;
		return 200; });
	auto retLamdaFeture = lamdaFeture.get();
	cout << "retLamdaFeture = " << retLamdaFeture << endl;*/
	//4.在一个函数中创建异步线程
	//CreateAsyncThread();


	//5.async额外参数 deferred的用法

	auto fetureDeferred = std::async(std::launch::deferred, AsyncPrint);
	//当额外参数为deferred，如果不调用future.get/future.wait，函数AsyncPrint
	//将永远不被执行。
	//deferred 不会创建子线程，函数AsyncPrint还是在调用线程中执行。
	fetureDeferred.get();
}
//测试 packaged_task的示例
void testPackagedTask()
{
	//1.用线程的方式启动packaged_task
	//packaged_task<int(int)> task1([](int a) {
	//	cout << "lamda start thread id =" << this_thread::get_id() << endl;
	//	this_thread::sleep_for(chrono::milliseconds(3000));
	//	cout << "lamda end thread id =" << this_thread::get_id() << endl;
	//	return 100;
	//	});
	//thread t(ref(task1),52);
	//
	//t.join(); // 如果不调用join的话，程序会崩溃。
	//auto result = task1.get_future();
	//auto ret = result.get();
	//cout << "testPackagedTask 's result = " << ret << endl;
	
	//2.packaged_task用做调用对象

	/*packaged_task<int(int)> ptObject(PrintPackageTask);
	int a = 10;
	thread t2(ref(ptObject), a);
	t2.join();
	auto res2 = ptObject.get_future();
	auto ret2 = res2.get();*/

	//vector<packaged_task<int(int)>> vecTask;
	//packaged_task<int(int)> task2(PrintPackageTask);
	//vecTask.push_back(std::move(task2));
	//for (auto it = vecTask.begin(); it != vecTask.end(); it++)
	//{
	//	auto tempTask = std::move(*it);
	//	tempTask(5);
	//	//要获取结果，则还是要借助get_future()
	//	auto r = tempTask.get_future().get();
	//	cout <<  r << endl;
	//}

	//promise的用法

}
//测试 promise/future的示例
void testPromiseFuture()
{
	promise<int> ps;
	future<int>fe = ps.get_future();
	//线程1中准备返回数据
	thread t1(PromisePrepareDataThreadFunc, ref(ps));
	thread t2(FutureGetDataThreadFunc, ref(fe));
	t1.join();
	t2.join();
}
int main()
{
    
    //CallOneExcute();
    //CallOneSingletonExcute();
	//条件变量
	/*MessageQueueConditionVariable msgQueCVObj;
	thread t1(&MessageQueueConditionVariable::inMessageRecvQueue, &msgQueCVObj);
	thread t2(&MessageQueueConditionVariable::outMessageRecvQueue, &msgQueCVObj);
	t1.join();
	t2.join();*/

	
	cout << "main() start thread id =" << this_thread::get_id() << endl;
	//async  future demo
	//testAsynFuture();

	//packaged_task   demo
	//testPackagedTask();

	//promise的用法
	/*promise<int>ps;
	PromiseFunc(ps);
	int ps_ret = ps.get_future().get();
	cout << "promise ret = " << ps_ret << endl;*/

	//测试promise的示例
	testPromiseFuture();
	std::cout << "Hello World!\n";
	cout << "main() end thread id =" << this_thread::get_id() << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
