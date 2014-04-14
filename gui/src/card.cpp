#include <dobble/card.hpp>
#include <QGraphicsScene>
#include <QString>
#include <QImage>
#include <QPainter>

namespace Dobble {

Card::Card():
  _itemList()
{
}

bool Card::addItem(const ItemPtr& item)
{
  return _itemList.insert(item).second;
}

bool Card::removeItem(const ItemPtr& item)
{
  return 1 == _itemList.erase(item);
}

bool Card::save(const std::string& filename)
{
  QGraphicsScene scene;
  scene.clearSelection();
  scene.setSceneRect(scene.itemsBoundingRect());

  QImage image(scene.sceneRect().size().toSize(), QImage::Format_ARGB32);
  image.fill(Qt::transparent);
  QPainter painter(&image);
  scene.render(&painter);
  return image.save(QString::fromStdString(filename));
}

}
