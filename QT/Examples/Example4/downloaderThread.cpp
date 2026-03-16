#include "downloaderThread.hpp"

DownloaderThread::DownloaderThread(QObject* parent, QString url)
    : QThread(parent),
    m_stopRequested(false),
    m_url(url)
{
}

void DownloaderThread::requestStop(){
    QMutexLocker locker(&m_mutex);
    m_stopRequested = true;
}

void DownloaderThread::run(){
    qDebug() << "Current thread ID: " << QThread::currentThreadId();
    qDebug() << "Starting download from: " << m_url;
    
    {
        QMutexLocker locker(&m_mutex);
        m_stopRequested = false;
    }

    for (int i = 0; i < 100; i++) {
        QThread::msleep(100);
        {
            QMutexLocker locker(&m_mutex);
            if(m_stopRequested){
                emit errorOccurred("Download stopped by user.");
                return;
            }
        }
        emit progressChanged(i);
        
    }
    emit downloadFinished("Download completed successfully.");
}