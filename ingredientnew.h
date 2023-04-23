#ifndef INGREDIENTNEW_H
#define INGREDIENTNEW_H

#include "qdebug.h"
#include <QObject>

using std::is_permutation;

enum ActionsPerformed {
    CUT,
    BOIL,
    MIX,
    FRY
};

class IngredientNew
{
public:
    IngredientNew(QString name, QList<ActionsPerformed> actions);

    bool operator==(const IngredientNew& other) const {
        if (m_name != other.m_name) {
            return false;
        }
        if (actions.size() != other.actions.size()) {
            return false;
        }
        return is_permutation(actions.begin(), actions.end(), other.actions.begin(), other.actions.end());
    }

    bool operator<(const IngredientNew& other) const {
        if (m_name != other.m_name) {
            return m_name < other.m_name;
        }
        return actions < other.actions;
    }

    QString getName() const { return m_name; }

    QList<ActionsPerformed> actions;

private:
    QString m_name;
};

#endif // INGREDIENTNEW_H
