#pragma once
#include <future>
using namespace std;
void PromiseFunc(promise<int>& ps);
int PrintOfPromise(promise<int>&ps,int &a); // ����һ�����з���ֵ���̺߳���
void PromisePrepareDataThreadFunc(promise<int>& ps); //�̺߳���1��ʹ��promise ׼������
void FutureGetDataThreadFunc(future<int>& fe);//�̺߳���2��ʹ��future ��ȡ����