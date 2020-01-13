#pragma once

#include <QMainWindow>

#include "gui/widget/HeaderWidget/HeaderWidget.hpp"
#include "gui/widget/BodyWidget/BodyWidget.hpp"
#include "gui/widget/ResponseWidget/ResponseWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace getit::gui::window
{
    class MainWindow: public QMainWindow
    {
        Q_OBJECT

        public:
            MainWindow(QWidget* parent = nullptr);
            ~MainWindow();

        private:
            Ui::MainWindow* ui;

            widget::HeaderWidget* headerController;
            widget::BodyWidget* bodyController;
            widget::ResponseWidget* responseController;
    };
}
