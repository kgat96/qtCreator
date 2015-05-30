
//#############################################################################
//# Makefile for building: pro1
//# Generated by qmake (3.0) (Qt 5.4.1)
//# Project:  pro1.pro
//# Template: app
//# Command: qmake -spec linux-g++ CONFIG+=debug -o Makefile pro1.pro
//#############################################################################

#include <QCoreApplication>
#include <QApplication>

#include <QtCore>

#include <QWidget>

#include <QPushButton>

#include "imageview.h"

#include "cmmd.h"

cmmd::cmmd () {
    connect(&ps,SIGNAL(readyReadStandardOutput()), this, SLOT(cmmdOutput()));
    connect(&ps,SIGNAL(readyReadStandardError()), this, SLOT(cmmdError()));
}

void runCmd(QProcess &pls, QStringList arg)
{
    pls.start("ls");

    if (!pls.waitForStarted())
        return;

    pls.closeWriteChannel();

    if (!pls.waitForFinished())
        return;

    QByteArray result = pls.readAll();
    std::cout << result.toStdString();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug()<<"start main thread " << QThread::currentThreadId();

    ImageView mImageView;

    QGuiApplication::setApplicationDisplayName(ImageView::tr("Image Viewer"));
    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption();
    commandLineParser.addPositionalArgument("[file]",ImageView::tr(
                                                "Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());

    mImageView.show();

    class ImageThread *mImageThread = new ImageThread(mImageView, &ImageView::xloadFile);
    mImageThread->start();

    qDebug()<<"entry main loop ...\n";

    return app.exec();
}
