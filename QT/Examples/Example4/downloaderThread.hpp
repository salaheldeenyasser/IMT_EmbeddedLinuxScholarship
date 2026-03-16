#ifndef DOWNLOADER_THREAD_HPP
#define DOWNLOADER_THREAD_HPP

#include <QThread>
#include <QDebug>
#include <QMutex>

class DownloaderThread : public QThread
{
    Q_OBJECT
public:
    DownloaderThread(QObject* parent = nullptr, QString url);

    Q_INVOKABLE void requestStop();
signals:
    void progressChanged(int progress);
    void downloadFinished(const QString& info);
    void errorOccurred(const QString& error);

protected:
    virtual void run() override;
private:
    bool m_stopRequested;
    QString m_url;
    mutable QMutex m_mutex;
};




#endif // DOWNLOADER_THREAD_HPP