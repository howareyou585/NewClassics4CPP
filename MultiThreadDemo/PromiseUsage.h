#pragma once
#include <future>
using namespace std;
void PromiseFunc(promise<int>& ps);
int PrintOfPromise(promise<int>&ps,int &a); // 定义一个带有返回值的线程函数
