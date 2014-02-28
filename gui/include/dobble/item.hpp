
#ifndef ITEM_HPP
#define ITEM_HPP

#include <QObject>
#include <QImage>

namespace Dobble {

class Item : public QObject
{
    Q_OBJECT
    Item(const Item&);
    Item& operator=(const Item&);

  public:
    Item();

  protected:
    QImage _sprite;
};

}

#endif
