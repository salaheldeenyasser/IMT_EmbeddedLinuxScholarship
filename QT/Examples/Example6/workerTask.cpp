#include "workerTask.hpp"

WorkerTask::WorkerTask(int id, QObject* parent)
    : QObject(parent), m_id(id)
{
    setAutoDelete(true);
}

WorkerTask::~WorkerTask()
{
    qDebug() << "WorkerTask with ID" << m_id << "is being destroyed.";
}

void WorkerTask::run(){
    qDebug() << "WorkerTask with ID" << m_id << "is running on thread" << QThread::currentThread();
    QThread::sleep(2); // Simulate work by sleeping for 2 seconds
    qDebug() << "WorkerTask with ID" << m_id << "has finished.";
}