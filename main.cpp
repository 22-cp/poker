#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <desk.h>
#include <people.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<people>("QmlPeople", 1, 0, "People");
    qmlRegisterType<desk>("QmlDesk", 1, 0, "Desk");

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
