#include "PackageTask.h"
#include <thread> 
#include <iostream>
using namespace std;
PackageTask::PackageTask()
{
}


PackageTask::~PackageTask()
{
}

int PackageTask::PrintPackageTask(int val)
{
	::PrintPackageTask(val);
	return 0;
}

int PrintPackageTask(int val)
{
	cout << "PrintPackageTask() start thread id =" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "PrintPackageTask() end thread id =" << this_thread::get_id() << endl;
	return 0;
}
