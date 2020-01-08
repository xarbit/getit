#pragma once

#include <QMainWindow>

#include "gui/RequestBody/BodyWidget.hpp"
#include "gui/RequestBody/RawRequestBody/RawRequestBodyWidget.hpp"

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
            // void registerRequestBodies();

            Ui::MainWindow* ui;
            // const getit::gui::requestbody::BodyWidget* bodyWidgets[];
    };
}
