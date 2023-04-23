#include "ingredientnew.h"

IngredientNew::IngredientNew(QString name, QList<ActionsPerformed> actions)
    : actions(actions),
      m_name(name)
{

}
