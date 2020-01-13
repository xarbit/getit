#include "gui/MainWindow/MainWindow.hpp"
#include "./ui_MainWindow.h"

#include <iostream>

using namespace getit::gui;

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow()),
    headerController(new HeaderControllerWidget(this)),
    bodyController(new requestbody::BodyControllerWidget(this)),
    responseController(new ResponseControllerWidget(this))
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
