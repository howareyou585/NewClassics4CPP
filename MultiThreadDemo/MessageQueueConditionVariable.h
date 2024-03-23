#pragma once
#include<iostream>
#include<list>
#include<mutex>
#include<condition_variable>
using namespace std;
class MessageQueueConditionVariable
{
public:
	MessageQueueConditionVariable();
	~MessageQueueConditionVariable();
	void inMessageRecvQueue();
	void outMessageRecvQueue();
private:
	list<int>m_msgList;
	mutex m_mutex;
	condition_variable m_conditionVariable;

};

