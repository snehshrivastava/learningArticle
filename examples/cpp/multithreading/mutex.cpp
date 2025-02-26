#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1,m2;

int g=0;

void thread1(){
    // lock(m1,m2);
    // lock_guard<mutex> lock1(m1, adopt_lock);
    cout << "thread id: " << this_thread::get_id() << " g: " << g << endl;
    g++;

    this_thread::sleep_for(chrono::seconds(1));
    // g++;

    cout << "thread id: " << this_thread::get_id() << " g: " << g << endl;
    // lock_guard<mutex> lock2(m2, adopt_lock);
    g++;
    
}

void thread2(){
    // lock(m1,m2);

    // lock_guard<mutex> lock2(m2, adopt_lock);
    cout << "thread id: " << this_thread::get_id() << " g: " << g << endl;
    g++;

    this_thread::sleep_for(chrono::seconds(1));
    cout << "thread id: " << this_thread::get_id() << " g: " << g << endl;
    // lock_guard<mutex> lock1(m1, adopt_lock);ß
    g++;
}

int main(){
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    cout<<"completed"<<endl;
    return 0;
}