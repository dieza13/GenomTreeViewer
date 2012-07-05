#ifndef TREECREATERCONTEXT_H
#define TREECREATERCONTEXT_H
#include "treebuilder.h"
#include "treedrawer.h"
#include "genomnode.h"

class TreeCreaterContext
{
private:
    std::multimap<int, GenomNode*> * genomByLevelList;
    TreeBuilder * treeBuilderRole;
    TreeDrawer * treeDrawerRole;
public:
    GenomNode *createTree(const char *fileName, QGraphicsView * treeView, bool extended);
    TreeCreaterContext();
    void redrawTree(QGraphicsView * treeView, bool extended);
    ~TreeCreaterContext();
};

#endif // TREECREATERCONTEXT_H
