#pragma once
#include <future>
using namespace std;
void PromiseFunc(promise<int>& ps);
int PrintOfPromise(promise<int>&ps,int &a); // 定义一个带有返回值的线程函数
void PromisePrepareDataThreadFunc(promise<int>& ps); //线程函数1：使用promise 准备数据
void FutureGetDataThreadFunc(future<int>& fe);//线程函数2：使用future 获取数据