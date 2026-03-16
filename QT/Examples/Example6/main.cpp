#include <QCoreApplication>
#include <QDebug>
#include <QThreadPool>
#include "workerTask.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThreadPool* pool = QThreadPool::globalInstance();

    pool->setMaxThreadCount(2); // Limit the thread pool to 2 threads

    for (int i = 1; i <= 10; ++i)
    {
        WorkerTask* task = new WorkerTask(i);
        pool->start(task);
    }

    pool->waitForDone(); // Wait for all tasks to complete before exiting

    return a.exec();
}
    