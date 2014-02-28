#include <QLabel>
#include <QString>

class PlopWidget : public QLabel {
  Q_OBJECT

public:
 PlopWidget(QWidget * parent = 0);
 ~PlopWidget();

public slots:
 void showNewLetter();

protected:
 QString _msg;
 unsigned short _pos;
};
