#include "draganddrop.h"

DragAndDrop::DragAndDrop(){

}

DragAndDropGraphicsView::DragAndDropGraphicsView(QWidget *widget): QGraphicsView(widget){
    setAcceptDrops(true);
}

void DragAndDropGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();

}

void DragAndDropGraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();

}

void DragAndDropGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

//This is where we should modify to
//1. get the mouse location
//2. send a signal to s3
//"this" = graphicsView
void DragAndDropGraphicsView::dropEvent(QDropEvent *event)
{
    if(event->source() == this) return;
    QLabel *label =qobject_cast<QLabel*>(event->source());
    QPixmap labelImage = label->pixmap();

    QPoint mousePos = event->pos();
    emit itemDrop(mousePos, labelImage, this);
}

//This is when we press on the graphics view. We can delete it.
void DragAndDropGraphicsView::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    emit customColorIsSelected(this);
}

DragAndDropLabel::DragAndDropLabel(QWidget *widget)
{
    Q_UNUSED(widget)
}


void DragAndDropLabel::createDrag(const QPoint &pos, QWidget *widget)
{
    if(widget ==nullptr) return;
    QByteArray byteArray(reinterpret_cast<char*>(&widget), sizeof(QWidget*));
    QMimeData *mimedata = new QMimeData();
    mimedata->setData("Label", byteArray);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimedata);

    QPoint globalpos = mapToGlobal(pos);
    QPoint p = widget->mapFromGlobal(globalpos);

    drag->setHotSpot(p);
    drag->setPixmap(widget->grab());
    drag->exec();


}

void DragAndDropLabel::mousePressEvent(QMouseEvent *event)
{
    createDrag(event->pos(), this);
    emit mousePress();
}
