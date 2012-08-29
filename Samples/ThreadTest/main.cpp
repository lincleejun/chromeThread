#include <string>
#include <iostream>
#include "base/message_loop.h"
#include "base/at_exit.h"
#include "base/memory/scoped_ptr.h"
#include "base/bind.h"
#include "base/threading/thread.h"

class Foo : public base::RefCounted<Foo>
{
public:
    Foo() : test_count_(0) {}

    void Test0() {
        ++test_count_;
        std::cout << "test0" << std::endl;
    }
private:
    ~Foo() {}
    int test_count_;
    const std::string result_;
private:
    friend class base::RefCounted<Foo>;
};

#pragma comment(lib, "../../debug/thread.lib")

void Test1()
{
    std::cout <<"Test1" << std::endl;
}
void ThreadInfo(base::Thread& thread)
{
    std::cout << "Thread Name : " << thread.thread_name() << std:: endl;
    std::cout << "Thread ID : " << thread.thread_id() << std:: endl;
    std::cout << "Thread IsRunning : " << thread.IsRunning() << std:: endl;
}
#pragma comment(lib, "dbghelp.lib")
int main(int argc, char** argv)
{
    base::AtExitManager atexit;

    base::Thread thread("hello");
    thread.Start();
    thread.message_loop()->PostTask(FROM_HERE, base::Bind(&Test1));

    ThreadInfo(thread);
    thread.Stop();

    return 0;
}