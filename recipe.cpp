#include "recipe.h"
#include <QFileInfo>

//Andy Tran Added
//void Recipe::resetNeededAmount(){
//    for (int i = 0; i < steps.size(); ++i) {
//        steps[i].resetAmount();
//        qDebug() << i+1 << "/" <<steps[i].toString();
//    }
//}
//QList<Step> Recipe::getSteps(){
//    return steps;
//}

//Recipe:: Recipe(QList<Step> steps){
//    this->steps = steps;
//}

//void Recipe::printSteps(){
//    for (int i = 0; i < steps.size(); ++i) {
//        qDebug() << i+1 << "/" <<steps[i].toString();
//    }
//    qDebug() << 2+1 << "/" <<steps[2].toString();
//}
//-----------------------------------

Recipe::Recipe()
{

}

bool Recipe::loadImageFromFile(const QString &filePath)
{
    if (QFileInfo::exists(filePath)) {
        return image.load(filePath);
    }
    return false;
}
