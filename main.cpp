#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <desk.h>
#include <people.h>
#include <qtserver.h>
#include <qtsocket.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<people>("QmlPeople", 1, 0, "People");
    qmlRegisterType<desk>("QmlDesk", 1, 0, "Desk");
    qmlRegisterType<qtserver>("Qtserver", 1, 0, "Server");
    qmlRegisterType<qtsocket>("Qtsocket", 1, 0, "Socket");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/poker/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
