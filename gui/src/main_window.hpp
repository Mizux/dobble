#include <QtGui/QMainWindow>
#include <QPushButton>
#include "plop.hpp"

class MainWindow : public QMainWindow
{
  Q_OBJECT

  MainWindow(const MainWindow&);
  MainWindow& operator=(const MainWindow&);

  public:
  MainWindow(QWidget *parent = 0);
  virtual ~MainWindow();

  protected:
  PlopWidget * _plopWidget;
  QPushButton * _button;
};
