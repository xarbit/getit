#include "gui/MainWindow/MainWindow.hpp"
#include "./ui_MainWindow.h"

using namespace getit::gui;

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow())
{
    ui->setupUi(this);

    ui->headers->addWidget(new HeaderControllerWidget(this));
    ui->body->addWidget(new requestbody::BodyControllerWidget(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
