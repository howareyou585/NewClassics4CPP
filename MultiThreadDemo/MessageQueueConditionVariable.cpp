#include "MessageQueueConditionVariable.h"



MessageQueueConditionVariable::MessageQueueConditionVariable()
{
}


MessageQueueConditionVariable::~MessageQueueConditionVariable()
{
}

void MessageQueueConditionVariable::inMessageRecvQueue()
{
	while (true)
	{
		int  i = rand();
		cout << "inMessageRecvQueue()执行,插入一个元素:" << i << endl;
		unique_lock <mutex> ul(m_mutex);
		m_msgList.push_back(i);
		m_conditionVariable.notify_one();//如果另一个线程B被阻塞在wait位置，则B被唤醒，
		//并尝试拿到锁,
		//B 如果那不到锁会一直尝试，直到拿到锁为止。
	}

}

void MessageQueueConditionVariable::outMessageRecvQueue()
{
	while (true)
	{
		unique_lock<mutex>lg(m_mutex); // 只能用这一种
		m_conditionVariable.wait(lg, [this] {
			if(m_msgList.empty())
			{
				return false; //  会解锁并阻塞在此
			}
			return true; }); // 从wait 返回并带着锁，继续往下走

		int ncommand = m_msgList.front();
		m_msgList.pop_front();
		cout << "outMessageRecvQueue()执行了，从容器中取出一个元素:" << ncommand << endl;
		
	}
}
