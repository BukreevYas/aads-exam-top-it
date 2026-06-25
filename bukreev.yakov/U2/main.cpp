#include "tree.hpp"
#include <cstdlib>

int main()
{
  using namespace bukreev;

  Tree< size_t >* idTree;
  createTree(&idTree);
  deleteTree(idTree);
}
