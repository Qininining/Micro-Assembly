#include "TaskThread.h"

/**
 * @brief TaskThread::TaskThread 默认构造函数。
 *        初始化线程状态为 true。
 */
TaskThread::TaskThread()
{
    threadSta = false; // 初始化线程状态为 true
    threadStart = false;
}

/**
 * @brief TaskThread::~TaskThread 析构函数。
 *        确保在对象销毁前停止并释放线程资源。
 */
TaskThread::~TaskThread()
{
    stopTask(); // 停止任务
    if(threadStart){
        delete Thread; // 释放线程资源
    }
}

/**
 * @brief TaskThread::ThreadTask 虚方法，用于定义任务逻辑。
 *        默认情况下，它输出一条调试信息。
 */
void TaskThread::ThreadTask()
{
    qDebug() << "This is a virtual Fuc" << threadSta; // 输出调试信息
}

/**
 * @brief TaskThread::Task 内部方法，管理 `ThreadTask` 方法以固定的时间间隔执行。
 * @param period 任务执行的时间间隔，单位为毫秒。
 */
void TaskThread::Task(unsigned int period)
{
    std::chrono::milliseconds target_period(period); // 定义任务的目标周期
    auto last_time = std::chrono::steady_clock::now(); // 记录上次任务执行的时间

    while(threadSta) // 在循环中执行任务，直到线程状态被设置为 false
    {
        ThreadTask(); // 执行任务逻辑
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

/**
 * @brief TaskThread::runTask 使用 `ThreadTask` 方法启动一个具有给定期望周期的任务。
 * @param period 任务执行的时间间隔，单位为毫秒。
 */
void TaskThread::runTask(unsigned int period)
{
    threadSta = true; // 将线程状态设置为 true 以开始任务
    threadStart = true;
    Thread = new std::thread(&TaskThread::Task, this, period); // 创建一个新的线程，该线程将执行 Task 方法
}

/**
 * @brief TaskThread::stopTask 停止正在运行的任务，通过将线程状态设置为 false。
 */
void TaskThread::stopTask()
{
    threadSta = false; // 将线程状态设置为 false 以停止任务
    if(threadStart){
        while(Thread->joinable()) // 等待线程完成
        {
            Thread->join(); // 加入线程
        }
    }
}

void TaskThread::stopTaskInLoop(){
    threadSta = false; // 将线程状态设置为 false 以停止任务
}


bool TaskThread::GetThreadSta(){
    return threadSta;
}
