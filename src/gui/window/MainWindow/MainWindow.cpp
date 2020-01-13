#include "gui/window/MainWindow/MainWindow.hpp"
#include "./ui_MainWindow.h"

#include <iostream>

using namespace getit::gui::window;

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow()),
    headerController(new widget::HeaderWidget(this)),
    bodyController(new widget::BodyWidget(this)),
    responseController(new widget::ResponseWidget(this))
{
    ui->setupUi(this);

    ui->headers->addWidget(headerController);
    ui->body->addWidget(bodyController);
    ui->response->addWidget(responseController);
}

MainWindow::~MainWindow()
{
    delete headerController;
    delete bodyController;
    delete responseController;
    delete ui;
}
