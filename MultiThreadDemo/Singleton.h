#pragma once
#include <mutex>
class Singleton
{
private :
	Singleton();
	static Singleton* m_ptrInstance;
	//mutex m_mutex;
	static std::once_flag m_onceFlg;
public:
	static Singleton* getInstance();
	
};

