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
		cout << "inMessageRecvQueue()ִ��,����һ��Ԫ��:" << i << endl;
		unique_lock <mutex> ul(m_mutex);
		m_msgList.push_back(i);
		m_conditionVariable.notify_one();//�����һ���߳�B��������waitλ�ã���B�����ѣ�
		//�������õ���,
		//B ����ǲ�������һֱ���ԣ�ֱ���õ���Ϊֹ��
	}

}

void MessageQueueConditionVariable::outMessageRecvQueue()
{
	while (true)
	{
		unique_lock<mutex>lg(m_mutex); // ֻ������һ��
		m_conditionVariable.wait(lg, [this] {
			if(m_msgList.empty())
			{
				return false; //  ������������ڴ�
			}
			return true; }); // ��wait ���ز�������������������

		int ncommand = m_msgList.front();
		m_msgList.pop_front();
		cout << "outMessageRecvQueue()ִ���ˣ���������ȡ��һ��Ԫ��:" << ncommand << endl;
		
	}
}
