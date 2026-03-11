#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>

void func(QTextStream& qout, QString name, int age){
    QString str = QString("Your name is %1 and your age is %2").arg(name).arg(age);
    qout << str << Qt::endl;
}

int main(int argc, char* argv[]){
    QCoreApplication a(argc,argv);

    QTextStream qout(stdout);
    QTextStream qin(stdin);

    // QString name;
    // quint8 age;

    // qout << "Enter your name: ";
    // qout.flush();

    // name = qin.readLine();

    // qout << "Enter your age: ";
    // qout.flush();

    // bool ok
    // age = qin.readLine().toInt(&ok);
    // if (!ok){
    //     qout << "Invalid...." << QT::endl;
    // } else{
    //     qout << "Your name is " << name << " and your age is " << age << QT::endl;
    // }

    // QString str;
    // QTextStream ss(&str);

    // // ss << "Hello" << ", How are you?" << QT::endl;
    // ss << "Hello" << " " << 10 << " "  << 5.5;
    // int num1;
    // double num2;
    // QString data;

    // ss >> data >> num1 >> num2;

    // qout << "Data: " << data << ", Number 1: " << num1 << ", Number 2: " << num2 << QT::endl;
    // qout << ss.readAll() << QT::endl;


    // QString str = "mohammed";
    // // str.remove("ham");
    // str = str.toUpper();

    // if(str.isUpper()){
    //     qout << "String is uppercase" << QT::endl;
    // } else{
    //     qout << "String is not uppercase" << QT::endl;
    // }
    // qout << str << QT::endl;
    // str.insert(0, "Hello ");
    // qout << str << QT::endl;
    // str.replace("MOHAMMED", "WORLD");
    // qout << str << QT::endl;
    // str.append("!!!");
    // qout << str << QT::endl;
    // str.prepend("Welcome ");
    // qout << str << QT::endl;
    // str.append("   ");
    // qout << "Before trim: '" << str << "'" << QT::endl;
    // str.trimmed();
    // qout << "After trim: '" << str << "'" << QT::endl;

    // func(qout, "Alice", 30);
    // func(qout, "Bob", 25);
    // func(qout, "Charlie", 35);
    // func(qout, "David", 28);

    QString data = "username:Mohanad;password:12345;email:mohanad@example.com";
    QString name = data.split(":")[1].split(";")[0];
    QString password = data.split(":")[2].split(";")[0];
    QString email = data.split(":")[3];

    qout << "Name: " << name << Qt::endl;
    qout << "Password: " << password << Qt::endl;
    qout << "Email: " << email << Qt::endl;

    if(!name.compare("Mohanad")){
        qout << "Name is correct" << Qt::endl;
    } else{
        qout << "Name is incorrect" << Qt::endl;
    }
    
    QTimer::singleShot(5000, [&](){
        a.quit();
    });

    a.exec();
}