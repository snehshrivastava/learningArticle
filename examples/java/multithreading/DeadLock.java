package multithreading;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class DeadLock {
    static final Lock lock1 = new ReentrantLock();
    static final Lock lock2 = new ReentrantLock();

    static void thread1() {
        // while (true) {
            if(lock1.tryLock()) {
                // System.out.println("Thread 1 locked lock1");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                // System.out.println("waiting for lock2");
                if(lock2.tryLock()) {
                    // System.out.println("Thread 1 locked lock2");
                }
            // }
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("Thread 1 completed ");
        }
    }

    static void thread2() {
        // while (true) {
            if(lock2.tryLock()) {
                // System.out.println("Thread 2 locked lock2");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                // System.out.println("waiting for lock1");
                if(lock1.tryLock()) {
                    // System.out.println("Thread 2 locked lock1");
                }
            // }
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("Thread 2 completed lock2");
        }
    }

    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            thread1();
        });
        Thread t2 = new Thread(() -> {
            thread2();
        });
        t1.start();
        t2.start();
    }
}