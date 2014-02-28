#include <QtGui/QApplication>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>
#include <QGLWidget>
#include "main_window.hpp"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QGraphicsScene scene;
  scene.addText("Hello, world!");
  QGraphicsView view(&scene);
  view.setViewport(new QGLWidget);
  view.show();

  MainWindow w;
  w.show();

  return a.exec();
}
