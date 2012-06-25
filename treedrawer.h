#ifndef TREEDRAWER_H
#define TREEDRAWER_H
#include "map"
#include "genomnode.h"
#include "QGraphicsView"

class TreeDrawer
{
private:
    void setCoordLastLevelAndDraw(std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> * lastLevel, QGraphicsView * treeView, int count);
    void setCoordLastLevel(std::pair<std::multimap<int, GenomNode*>::iterator, std::multimap<int, GenomNode*>::iterator> * lastLevel, QGraphicsView * treeView, int count);
     GenomNode * setCoordAndDraw(std::multimap<int, GenomNode*> * treeMap, QGraphicsView * treeView, int count);
     void drawLine(int x1, int y1, int x2, int y2, QGraphicsScene  * graphScen);
public:
    TreeDrawer();
    GenomNode * drawTree(std::multimap<int, GenomNode*> * treeMap, int levelCount, QGraphicsView * treeView);

};

#endif // TREEDRAWER_H