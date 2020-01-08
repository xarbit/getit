#include "gui/MainWindow/MainWindow.hpp"
#include "./ui_MainWindow.h"

using namespace getit::gui;

// const requestbody::BodyWidget* MainWindow::bodyWidgets[] = {
//     new getit::gui::requestbody::RawRequestBodyWidget(this)
// };

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow())
{
    ui->setupUi(this);

    // Register all bodies
    // for (auto const& body: this->bodyWidgets) {
    //     this->ui->tabBodies
    // }

    for (int i = 0; i < 10; i++) {
        this->ui->tabBodies->addTab(new getit::gui::requestbody::RawRequestBodyWidget(this), "New");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::registerRequestBodies()
// {

// }
