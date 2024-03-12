#include "Singleton.h"
#include<iostream>
#include<mutex>
using namespace std;
Singleton* Singleton::m_ptrInstance = nullptr;
std::once_flag Singleton::m_onceFlg;
Singleton* Singleton::getInstance()
{
	//lock_guard<mutex>lg(this->m_mutex);
	std::call_once(m_onceFlg, []() {if (!m_ptrInstance)
	{
		m_ptrInstance = new Singleton();
	}});
	
	return m_ptrInstance;
}
Singleton::Singleton()
{
	cout << "create singleton object" << endl;
}