#include "plop.hpp"

PlopWidget::PlopWidget(QWidget * parent) :
 QLabel(parent),
 _msg("Hello World !"),
 _pos(0)
{}

PlopWidget::~PlopWidget()
{}

void PlopWidget::showNewLetter()
{
 _pos++;
 setText(_msg.left(_pos));
}
