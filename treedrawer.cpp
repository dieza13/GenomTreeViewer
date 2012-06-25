#include "treedrawer.h"
#include "map"
#include "QTreeView"
#include "iostream"

void TreeDrawer::setCoordLastLevelAndDraw(std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> * lastLevel, QGraphicsView * treeView, int count)
{
    int step = (treeView->height() - 25) / (count);
    int i = 0;
    for (std::multimap<int, GenomNode*>::iterator iter = lastLevel->first; iter != lastLevel->second;++iter)
    {
        GenomNode * node = (iter)->second;
        node->setNodeX(treeView->width() - 100);
        node->setNodeY(i * step + 15);
        node->showGenom(treeView);
        treeView->childAt(0,0)->move(node->getNodeX(),node->getNodeY());
        i++;
    }
}

TreeDrawer::TreeDrawer()
{
}

GenomNode * TreeDrawer::drawTree(std::multimap<int, GenomNode*> * treeMap, int levelCount, QGraphicsView * treeView)
{
    std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> lastLevel = treeMap->equal_range(-1);
    setCoordLastLevelAndDraw(&lastLevel, treeView, treeMap->count(-1));
    GenomNode * node = setCoordAndDraw(treeMap,treeView,levelCount);
    return node;
}

GenomNode * TreeDrawer::setCoordAndDraw(std::multimap<int, GenomNode*> * treeMap, QGraphicsView *treeView, int count)
{

    GenomNode * firstNode;
    int height = treeView->height();
    int width = treeView->width();
    int step = (treeView->width() - 100 ) / (count + 1);
    int displacementX = 100 + 1.40 * step;
    int displacementY = 15;
    QGraphicsScene * graphScen = new QGraphicsScene();
    treeView->setScene(graphScen);

    for (int i = count; i > 0; i--) {
        std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> currentLevel = treeMap->equal_range(i);
        for (std::multimap<int, GenomNode*>::iterator iter = currentLevel.first; iter != currentLevel.second;++iter)
        {
            std::cout << "  [" << (*iter).first << ", " << (*iter).second->getGenomName().toAscii().data() << "]" << std::endl;
            GenomNode * node = (iter)->second;           
            node->setNodeX(node->getLevel() * step);
            node->setNodeY((node->getLeftChild()->getNodeY() + node->getRightChild()->getNodeY()) / 2);
            node->showGenom(treeView);            
            treeView->childAt(0,0)->move(node->getNodeX(),node->getNodeY());
            drawLine(node->getNodeX() - displacementX,node->getNodeY() + displacementY,node->getLeftChild()->getNodeX() - displacementX,node->getLeftChild()->getNodeY() + displacementY,graphScen);
            drawLine(node->getNodeX() - displacementX,node->getNodeY() + displacementY,node->getRightChild()->getNodeX() - displacementX,node->getRightChild()->getNodeY() + displacementY,graphScen);
            firstNode = node;
        }

    }
    return firstNode;
}

void TreeDrawer::drawLine(int x1, int y1, int x2, int y2, QGraphicsScene * graphScen)
{
    graphScen->addLine(x1, y1, x1 , y2, QPen(QBrush(Qt::red),1));
    graphScen->addLine(x1, y2, x2 , y2, QPen(QBrush(Qt::red),1));
}
