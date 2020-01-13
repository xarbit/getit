#pragma once

#include <QMainWindow>

#include "gui/HeaderWidget/HeaderControllerWidget.hpp"
#include "gui/RequestBody/BodyControllerWidget.hpp"
#include "gui/ResponseControllerWidget/ResponseControllerWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace getit::gui
{
    class MainWindow: public QMainWindow
    {
        Q_OBJECT

        public:
            MainWindow(QWidget* parent = nullptr);
            ~MainWindow();

        private:
            Ui::MainWindow* ui;

            HeaderControllerWidget* headerController;
            requestbody::BodyControllerWidget* bodyController;
            ResponseControllerWidget* responseController;
    };
}
