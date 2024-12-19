#ifndef TASKTHREAD_H
#define TASKTHREAD_H

#include <iostream>
#include <thread>
#include <atomic>
#include <QDebug>

class TaskThread
{
public:
    TaskThread();
    virtual ~TaskThread();

public:
    virtual void ThreadTask();
    void runTask(unsigned int period);

    template<typename MyClass, typename MyFunc, typename... Args>
    void runTask(unsigned int period, MyClass* obj, MyFunc func, Args... args);

    void stopTask();
    void stopTaskInLoop();

    bool GetThreadSta();

private:
    std::thread *Thread;
    std::atomic<bool> threadSta;
    bool threadStart;

private:
    void Task(unsigned int period);
    template<typename MyClass, typename MyFunc, typename... Args>
    void funcTask(unsigned int period, MyClass* obj, MyFunc func, Args... args);

};





// 模板函数的实现必须放在头文件中
/**
 * @brief TaskThread::runTask 使用提供的对象的成员函数启动一个具有给定期望周期的任务。
 * @param obj 指向对象的指针，该对象的成员函数将被调用。
 * @param func 要在对象上调用的成员函数。
 * @param period 任务执行的时间间隔，单位为毫秒。
 */
template<typename MyClass, typename MyFunc, typename... Args>
void TaskThread::runTask(unsigned int period, MyClass* obj, MyFunc func, Args... args)
{
    threadSta = true; // 将线程状态设置为 true 以开始任务
    threadStart = true;
    Thread = new std::thread(&TaskThread::funcTask<MyClass, MyFunc, Args...>, this, period, obj, func, std::forward<Args>(args)...); // 创建一个新的线程，该线程将执行 funcTask 方法
}

/**
 * @brief TaskThread::funcTask 内部方法，管理成员函数以固定的时间间隔执行。
 * @param obj 指向对象的指针，该对象的成员函数将被调用。
 * @param func 要在对象上调用的成员函数。
 * @param period 任务执行的时间间隔，单位为毫秒。
 */
template<typename MyClass, typename MyFunc, typename... Args>
void TaskThread::funcTask(unsigned int period, MyClass* obj, MyFunc func, Args... args)
{
    std::chrono::milliseconds target_period(period); // 定义任务的目标周期
    auto last_time = std::chrono::steady_clock::now(); // 记录上次任务执行的时间
    auto boundFunction = std::bind(func, obj, std::forward<Args>(args)...); // 绑定函数到对象

    while(threadSta) // 在循环中执行任务，直到线程状态被设置为 false
    {
        boundFunction(); // 调用绑定的成员函数
        auto next_time = last_time + target_period; // 计算下次执行的时间
        if (next_time > std::chrono::steady_clock::now()) // 如果下次执行时间还未到达
        {
            std::this_thread::sleep_until(next_time); // 睡眠到下次执行时间
            last_time = next_time; // 更新上次执行时间
        }
        else
        {
            last_time = std::chrono::steady_clock::now(); // 更新上次执行时间为当前时间
        }
    }
}


#endif // TASKTHREAD_H
