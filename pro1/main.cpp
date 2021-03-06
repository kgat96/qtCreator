
//#############################################################################
//# Makefile for building: pro1
//# Generated by qmake (3.0) (Qt 5.4.1)
//# Project:  pro1.pro
//# Template: app
//# Command: qmake -spec linux-g++ CONFIG+=debug -o Makefile pro1.pro
//#############################################################################

#include <QCoreApplication>
#include "cmmd.h"

cmmd::cmmd () {
    connect(&ps,SIGNAL(readyReadStandardOutput()), this, SLOT(cmmdOutput()));
    connect(&ps,SIGNAL(readyReadStandardError()), this, SLOT(cmmdError()));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cmmd cmd;

    QProcess &pls = cmd.ps;

    QStringList arguments;

    arguments.append("123");

//  arguments.append("ls");
//  arguments.append("-al");

//  arguments << "ls" << "-al";

//  cmd.connect(&pls,SIGNAL(readyReadStandardError()), &cmd,SLOT(cmd.cmmdError));

    pls.start("ls", arguments);

    std::cout << "Quit a stata:" << pls.state() << std::endl;

    if (!pls.waitForStarted())
        return false;

    std::cout << "Quit v stata:" << pls.state() << std::endl;

//    pls.write("ls");
//    if (!pls.waitForBytesWritten())
//        return false;

    pls.closeWriteChannel();

    if (!pls.waitForFinished())
        return false;

    std::cout << "Quit 1 stata:" << pls.state() << std::endl;

    QByteArray result = pls.readAll();
    std::cout << result.toStdString();

    std::cout << "Quit 2 stata:" << pls.state() << std::endl;

    return a.exec();
}

//#include "main.moc"
