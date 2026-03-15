#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    // QProcess process;
    // process.start("ls",QStringList() << "-l" << "/");
    // process.waitForFinished();
    // QString output = process.readAllStandardOutput();
    // qDebug() << output;


    // QProcess process;
    // process.start("cat");
    // process.write("Hello, World!\n");
    // process.closeWriteChannel();
    // process.waitForFinished();
    // QString output = process.readAllStandardOutput();
    // QProcess process;
    // // qDebug() << output;
    // QObject::connect(&process, &QProcess::started, [&](){
    //     qDebug() << "Process started";
    // });
    // QObject::connect(&process,QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [&](int exitCode, QProcess::ExitStatus exitStatus){
    //     qDebug() << "Process finished";
    //     qDebug() << "Exit code: " << exitCode << ", Exit status: " << exitStatus;
    //     a.quit();
    // });
    // QObject::connect(&process, &QProcess::readyReadStandardOutput, [&](){
    //     qDebug() << "Standard Output: " << process.readAllStandardOutput();
    // });
    // process.start("ping", QStringList() << "-c" << "4" << "www.google.com");


    // QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    // env.insert("NAME", "Mohammed");
    // QProcess process;
    // process.setWorkingDirectory("~/IMT_Scholarship/QT/Examples/Example3");
    // process.setProcessEnvironment(env);

    // process.start("./myScript.sh");
    // process.waitForFinished();
    // QString output = process.readAllStandardOutput();
    // qDebug() << output;


    // QFile file("file.txt");
    // QFile file;
    // file.setFileName("file.txt");
    
    // qDebug() << "File name: " << file.fileName();
    // qDebug() << "File exists: " << file.exists();
    // qDebug() << "File size: " << file.size();
    // QTextStream ss(&file);

    // int count = 1;
    // if(file.exists()){
    //     if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
    //         ss << "\nHello World\n";
    //         ss << "This is an example\n";
    //         ss << "of a text file that has been recently edited.\n";
    //         file.flush();
    //         file.close();
            
    //     }
    //     if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
    //         // file.readAll();
    //         // qDebug() << "File content: " << file.readAll();
    //         while(!file.atEnd()){
    //             count++;
    //             qDebug() << "Line " << count << ": " << file.readLine();
    //         }
    //         file.close();
    //     }
    // }

    // QFileInfo fileInfo(file);
    // qDebug() << "File absolute path: " << fileInfo.absoluteFilePath();
    // qDebug() << "Base name: " << fileInfo.baseName();
    // qDebug() << "Birth time: " << fileInfo.birthTime().toString();
    // qDebug() << "Size: " << fileInfo.size() << " bytes";
    // qDebug() << "Is file: " << fileInfo.isFile();
    // qDebug() << "Is readable: " << fileInfo.isReadable();
    // qDebug() << "Is writable: " << fileInfo.isWritable();
    // qDebug() << "Is executable: " << fileInfo.isExecutable();
    // qDebug() << "Last modified: " << fileInfo.lastModified().toString();
    // qDebug() << "Last read: " << fileInfo.lastRead().toString();
    // qDebug() << "Owner: " << fileInfo.owner();
    // qDebug() << "Group: " << fileInfo.group();
    // qDebug() << "Permissions: " << fileInfo.permissions();
    // qDebug() << "SymLink target: " << fileInfo.symLinkTarget();
    // qDebug() << "Is hidden: " << fileInfo.isHidden();
    // file.copy("file_copy.txt");
    // file.rename("file_renamed.txt");
    // QFileDevice::Permissions permissions = file.permissions();
    // if(permissions & QFileDevice::ReadOwner){
    //     qDebug() << "Owner has read permission";
    // }
    // if(permissions & QFileDevice::WriteOwner){
    //     qDebug() << "Owner has write permission";
    // }
    // if(permissions & QFileDevice::ExeOwner){
    //     qDebug() << "Owner has execute permission";
    // }
    // if(permissions & QFileDevice::ReadUser){
    //     qDebug() << "User has read permission";
    // }
    // if(permissions & QFileDevice::WriteUser){
    //     qDebug() << "User has write permission";
    // }
    // if(permissions & QFileDevice::ExeUser){
    //     qDebug() << "User has execute permission";
    // }
    // if(permissions & QFileDevice::ReadGroup){
    //     qDebug() << "Group has read permission";
    // }
    // if(permissions & QFileDevice::WriteGroup){
    //     qDebug() << "Group has write permission";
    // }
    // if(permissions & QFileDevice::ExeGroup){
    //     qDebug() << "Group has execute permission";
    // }
    // if(permissions & QFileDevice::ReadOther){
    //     qDebug() << "Others have read permission";
    // }
    // if(permissions & QFileDevice::WriteOther){
    //     qDebug() << "Others have write permission";
    // }
    // if(permissions & QFileDevice::ExeOther){
    //     qDebug() << "Others have execute permission";
    // }
    // file.setPermissions(file.permissions() &(~QFileDevice::ReadOwner | QFileDevice::WriteOwner | QFileDevice::ExeOwner));

    

    return a.exec();
}