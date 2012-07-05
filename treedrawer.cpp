#include "treedrawer.h"
#include "map"
#include "QTreeView"
#include "iostream"

void TreeDrawer::setCoordLastLevelAndDraw(std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> * lastLevel, QGraphicsView * treeView, int count, int levelCount, bool extended)
{
    int stepY = (treeView->height() - 45) / (count);
    int treeWidth = treeView->width();
    int stepX = (treeView->width() ) / (levelCount + 1);
    int i = 0;
    for (std::multimap<int, GenomNode*>::iterator iter = lastLevel->first; iter != lastLevel->second;++iter)
    {
        GenomNode * node = (iter)->second;
        int x = node->getNodeX();
        int y = node->getNodeY();
        if (extended) {
            node->setNodeX(treeView->width()  - node->genomBody->width()  - 25);
        } else {
            node->setNodeX(node->getLevel() * stepX - node->genomBody->width()  - 25);
        }
        node->setNodeY(i * stepY  + node->genomBody->height());
        node->showGenom(treeView);
        node->genomBody->move(node->getNodeX() ,node->getNodeY());
        i++;
    }
}

TreeDrawer::TreeDrawer()
{
}

GenomNode * TreeDrawer::drawTreeFromChildren(std::multimap<int, GenomNode*> * treeMap, int levelCount, QGraphicsView * treeView, bool extended)
{
    std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> lastLevel = treeMap->equal_range(-1);
    setCoordLastLevelAndDraw(&lastLevel, treeView, treeMap->count(-1), levelCount, extended);
    GenomNode * node = setCoordAndDraw(treeMap,treeView,levelCount);
    return node;
}



GenomNode * TreeDrawer::setCoordAndDraw(std::multimap<int, GenomNode*> * treeMap, QGraphicsView *treeView, int count)
{

    GenomNode * firstNode;
    int height = treeView->height();
    int width = treeView->width();
    int step = (treeView->width()) / (count + 1);
    int displacementX = 100 + 1.40 * step;
    QGraphicsScene * graphScen = new QGraphicsScene();
    graphScen->setSceneRect(0,0, treeView->width(),treeView->height());
//    graphScen->set
    treeView->setScene(graphScen);

    for (int i = count; i > 0; i--) {
        std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> currentLevel = treeMap->equal_range(i);
        for (std::multimap<int, GenomNode*>::iterator iter = currentLevel.first; iter != currentLevel.second;++iter)
        {
            std::cout << "  [" << (*iter).first << ", " << (*iter).second->getGenomName().toAscii().data() << "]" << std::endl;
            GenomNode * node = (iter)->second;            
            node->setNodeX(node->getIndex() * step );
            node->setNodeY((node->getLeftChild()->getNodeY() + node->getRightChild()->getNodeY()) / 2);
            node->showGenom(treeView);
            node->genomBody->move(node->getNodeX(), node->getNodeY() );
            drawLine(node->getNodeX() + node->genomBody->width(), node->getNodeY() + node->getGenomBody()->height() / 2,node->getLeftChild()->getNodeX() + node->getLeftChild()->genomBody->width(), node->getLeftChild()->getNodeY() + node->getLeftChild()->genomBody->height() / 2, graphScen);
            drawLine(node->getNodeX() + node->genomBody->width(), node->getNodeY() + node->getGenomBody()->height() / 2, node->getRightChild()->getNodeX() + node->getRightChild()->genomBody->width(), node->getRightChild()->getNodeY()  + node->getRightChild()->genomBody->height() / 2, graphScen);
            firstNode = node;
        }

    }
    return firstNode;
}

void TreeDrawer::drawLine(int x1, int y1, int x2, int y2, QGraphicsScene * graphScen)
{
    graphScen->addLine(x1 , y1, x1 , y2, QPen(QBrush(Qt::red),1));
    graphScen->addLine(x1 , y2, x2 , y2, QPen(QBrush(Qt::red),1));
}
