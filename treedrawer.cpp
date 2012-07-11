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
        setAndShowNode(treeView, node);
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
    QGraphicsScene * graphScen = new QGraphicsScene();
    graphScen->installEventFilter(graphScen);
    graphScen->setSceneRect(0,0, treeView->width(),treeView->height());
    treeView->setScene(graphScen);
    for (int i = count; i > 0; i--) {
        std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> currentLevel = treeMap->equal_range(i);
        for (std::multimap<int, GenomNode*>::iterator iter = currentLevel.first; iter != currentLevel.second;++iter)
        {
            std::cout << "  [" << (*iter).first << ", " << (*iter).second->getGenomName().toAscii().data() << "]" << std::endl;
            GenomNode * node = (iter)->second;            
            node->setNodeX(node->getIndex() * step );
            node->setNodeY((node->getLeftChild()->getNodeY() + node->getRightChild()->getNodeY()) / 2);
            setAndShowNode(treeView, node);
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

void TreeDrawer::reflect(GenomNode *node, int DT, QGraphicsView * treeView)
{
    if (node->getLeftChild() == NULL) {
        node->setNodeY(node->getNodeY() + DT);        
    } else {
        reflect(node->getLeftChild(), DT, treeView);
        reflect(node->getRightChild(), DT, treeView);
    }
    setAndShowNode(treeView, node);

}

void TreeDrawer::setAndShowNode(QGraphicsView * treeView, GenomNode * node)
{
    node->showGenom(treeView);
    node->setTop();
    node->setBottom();
    node->genomBody->move(node->getNodeX(), node->getNodeY() );
}





bool TreeDrawer::reflection(GenomNode *node, QGraphicsView * treeView, int x, int y, std::multimap<int, GenomNode*> * treeMap, int levelCount)
{
    bool result = false;
    if (node->getLeftChild() != NULL) {
        if ( (x < (node->getNodeX() + node->genomBody->width())) && (x > (node->getNodeX())) && (y < (node->getNodeY() + node->genomBody->height())) && (y > (node->getNodeY() - 45))) {
            reflectBranch(node, treeView);
            setCoordAndDraw(treeMap,treeView,levelCount);
            result = true;
        } else {
            if (node->getLeftChild() != NULL) {
                if (!result) result = reflection(node->getLeftChild(), treeView, x, y, treeMap,levelCount);
                if (!result) result = reflection(node->getRightChild(), treeView, x, y, treeMap,levelCount);
            }
        }
    }
    return result;
}

void TreeDrawer::reflectBranch(GenomNode * node, QGraphicsView * treeView)
{    
    int leftDT, rightDT;
    leftDT = node->getTop() - node->getRightChild()->getTop();
    rightDT = node->getBottom() - node->getLeftChild()->getBottom();
    reflect(node->getLeftChild(), rightDT, treeView);
    reflect(node->getRightChild(), leftDT, treeView);
    GenomNode * nd = node->getLeftChild();
    node->setLeftChild(node->getRightChild());
    node->setRightChild(nd);

}


