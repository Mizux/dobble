
#ifndef CARD_HPP
#define CARD_HPP

#include <QObject>
#include <QSet>
#include <QSharedPointer>
#include <QString>
#include <QGraphicsScene>

namespace Dobble {
class Item;
typedef QSharedPointer<Item> ItemPtr;

class Card : public QObject
{
    Q_OBJECT
    Card(const Card&);
    Card& operator=(const Card&);

  public:
    Card();

    bool addItem(const ItemPtr& item);
    bool removeItem(const ItemPtr& item);

    bool save(const QString& filename);

  protected:
    QGraphicsScene* _scene;
    QSet<ItemPtr> _itemList;
};

}

#endif
