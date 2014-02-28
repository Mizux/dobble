#include <dobble/deck.hpp>

namespace Dobble {

Deck::Deck()
{}

bool Deck::build()
{
  QList<ItemPtr> list = _itemList.toList();
  qSort(list);

  return true;
}

}
