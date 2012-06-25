#include "treecreatercontext.h"
#include "treebuilder.h"
#include "treedrawer.h"
#include "genomnode.h"

GenomNode * TreeCreaterContext::createTree(const char * fileName, QGraphicsView * treeView)
{
    treeBuilderRole->setFile(fileName);
    genomByLevelList = treeBuilderRole->getGenomMap();
    return treeDrawerRole->drawTree(genomByLevelList,treeBuilderRole->getLevelCount(), treeView);
}

TreeCreaterContext::TreeCreaterContext()
{
    treeBuilderRole = new TreeBuilder();
    treeDrawerRole = new TreeDrawer();
}

TreeCreaterContext::~TreeCreaterContext()
{
    delete treeBuilderRole, treeDrawerRole;
}
