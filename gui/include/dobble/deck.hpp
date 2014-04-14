
#ifndef DECK_HPP
#define DECK_HPP

#include <set>
#include <string>
#include <boost/shared_ptr.hpp>

namespace Dobble {
  class Card;
  typedef boost::shared_ptr<Card> CardPtr;

  class Item;
  typedef boost::shared_ptr<Item> ItemPtr;

  class Deck
  {
    Deck(const Deck&);
    Deck& operator=(const Deck&);

    public:
    Deck();

    bool setItemDirectory(const std::string& directory);

    bool build();

    protected:
    std::set<CardPtr> _cardList;
    std::set<ItemPtr> _itemList;
  };

}

#endif
