#include "gui/MainWindow/MainWindow.hpp"
#include "./ui_MainWindow.h"

Gui::MainWindow::MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow())
{
    ui->setupUi(this);
}

Gui::MainWindow::MainWindow::~MainWindow()
{
    delete ui;
}
