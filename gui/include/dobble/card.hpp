
#ifndef CARD_HPP
#define CARD_HPP

#include <set>
#include <string>
#include <boost/shared_ptr.hpp>

namespace Dobble {
  class Item;
  typedef boost::shared_ptr<Item> ItemPtr;

  class Card
  {
    Card(const Card&);
    Card& operator=(const Card&);

    public:
    Card();

    bool addItem(const ItemPtr& item);
    bool removeItem(const ItemPtr& item);

    bool save(const std::string& filename);

    protected:
    std::set<ItemPtr> _itemList;
  };

}

#endif
