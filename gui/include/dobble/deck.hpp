
#ifndef DECK_HPP
#define DECK_HPP

#include <QObject>
#include <QSet>
#include <QSharedPointer>

namespace Dobble {
class Card;
typedef QSharedDataPointer<Card> CardPtr;

class Item;
typedef QSharedDataPointer<Item> ItemPtr;

class Deck : public QObject
{
    Q_OBJECT
    Deck(const Deck&);
    Deck& operator=(const Deck&);

  public:
    Deck();

    bool setItemDirectory(const QString& directory);

    bool build();

  protected:
    QSet<CardPtr> _cardList;
    QSet<ItemPtr> _itemList;
};

}

#endif
