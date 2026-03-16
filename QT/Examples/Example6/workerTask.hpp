#ifndef WORKER_TASK_HPP
#define WORKER_TASK_HPP

#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QThread>

class WorkerTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    WorkerTask(int id, QObject* parent = nullptr);
    ~WorkerTask();

protected:
    void run() override;

private:
    int m_id;
};

#endif // WORKER_TASK_HPP