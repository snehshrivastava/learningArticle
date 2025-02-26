#include <iostream>
#include <thread>

using namespace std;

void myFunction()
{
    cout << "thread id: " << this_thread::get_id() << endl;
}

int main()
{
    thread thread1(myFunction);
    thread thread2(myFunction);
    // Wait for the new thread to finish execution
    thread1.join();
    thread2.join();

    cout << "Hello from the main thread! "<< this_thread::get_id() << endl;

    return 0;
}
