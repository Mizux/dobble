#include <dobble/card.hpp>
#include <QImage>
#include <QPainter>

namespace Dobble {

Card::Card():
  _scene(),
  _itemList()
{
  _scene = new QGraphicsScene(this);
}

bool Card::addItem(const ItemPtr& item)
{
  QSet<ItemPtr>::const_iterator it = _itemList.insert(item);

  if (it == _itemList.end())
    return false;
  else
    return true;
}

bool Card::removeItem(const ItemPtr& item)
{
  return _itemList.remove(item);
}

bool Card::save(const QString& filename)
{
  _scene->clearSelection();
  _scene->setSceneRect(_scene->itemsBoundingRect());

  QImage image(_scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
  image.fill(Qt::transparent);
  QPainter painter(&image);
  _scene->render(&painter);
  return image.save(filename);
}

}
