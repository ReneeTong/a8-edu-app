#ifndef S3COOKING_H
#define S3COOKING_H

#include <QWidget>

namespace Ui {
class s3Cooking;
}

class s3Cooking : public QWidget
{
    Q_OBJECT

public:
    explicit s3Cooking(QWidget *parent = nullptr);
    ~s3Cooking();

public slots:
    void nextPage();

signals:
    void goToPage4();

private:
    Ui::s3Cooking *ui;
};

#endif // S3COOKING_H
