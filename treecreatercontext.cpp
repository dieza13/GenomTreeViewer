#include "treecreatercontext.h"
#include "treebuilder.h"
#include "treedrawer.h"
#include "genomnode.h"

GenomNode * TreeCreaterContext::createTree(const char * fileName, QGraphicsView * treeView, bool extended)
{
    treeBuilderRole->setFile(fileName);
    treeBuilderRole->getTree(0)[1];
    treeBuilderRole->closeFile();
    genomByLevelList = treeBuilderRole->getGenomMap();
    return treeDrawerRole->drawTreeFromChildren(genomByLevelList,treeBuilderRole->getLevelCount(), treeView, extended);
}

TreeCreaterContext::TreeCreaterContext()
{
    treeBuilderRole = new TreeBuilder();
    treeDrawerRole = new TreeDrawer();

}

void TreeCreaterContext::redrawTree(QGraphicsView * treeView, bool extended)
{
    treeDrawerRole->drawTreeFromChildren(genomByLevelList,treeBuilderRole->getLevelCount(), treeView, extended);
}

void TreeCreaterContext::reflectBranch(GenomNode *node, QGraphicsView * treeView, int x, int y)
{
    treeDrawerRole->reflection(node, treeView,x,y,treeBuilderRole->getGenomMap(),treeBuilderRole->getLevelCount());

}

TreeCreaterContext::~TreeCreaterContext()
{
    delete treeBuilderRole;
    delete treeDrawerRole;

}
