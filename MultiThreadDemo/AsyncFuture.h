#pragma once

int AsyncPrint();
void AsyncPrintWithoutRetValue();
class AsyncFuture
{
public :
	AsyncFuture() { m_value = 100; };
	virtual ~AsyncFuture() {};
	int	ThreadFunc(int a);
	int GetVal() { return m_value; };
private :
	int m_value{};
};

void CreateAsyncThread();
