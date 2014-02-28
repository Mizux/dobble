#include "main_window.hpp"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent):
  QMainWindow(parent),
  _plopWidget(),
  _button()
{
 // Making a central Widget for our Window
 setCentralWidget(new QWidget(this));

 // Building our widgets
 _plopWidget = new PlopWidget(this);
 _button = new QPushButton(this);
 _button->setText("++");

 connect(_button, SIGNAL(clicked()), _plopWidget, SLOT(showNewLetter()));

 // Setting the content and disposition of our central Widget
 centralWidget()->setLayout(new QVBoxLayout(this));
 centralWidget()->layout()->addWidget(_plopWidget);
 centralWidget()->layout()->addWidget(_button);
}

MainWindow::~MainWindow()
{}
