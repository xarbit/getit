#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qputenv("QT_QUICK_CONTROLS_STYLE", "material");


    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
