#ifndef DRAGANDDROP_H
#define DRAGANDDROP_H

#include<QMouseEvent>
#include<QPoint>
#include<QLabel>
#include<QPushButton>
#include<QGraphicsView>
#include<QByteArray>
#include<QDrag>
#include<QMimeData>
#include<QSize>

/**
 * @brief The dragAndDropEvents class This class is a class for custom QLabel and QGraphicsView for Drag and Drop effect
 */
class DragAndDrop
{
public:
    DragAndDrop();
};

/**
 * @brief The DragAndDropLabel class Custom QLabel class
 */
class DragAndDropLabel : public QLabel{
    Q_OBJECT

public:

    /**
    * @brief DragAndDropLabel Constructor
    * @param widget QWidget
    */
   explicit DragAndDropLabel(QWidget *widget = nullptr);

signals:
//    //ruini test
//    void mouseRelease(QPoint pos);

private:

    /**
     * @brief createDrag Creates a drag event.
     * @param pos Position of the mouse
     * @param widget The widget owns this drag
     */
    void createDrag(const QPoint &pos, QWidget *widget );
protected:

    /**
     * @brief mousePressEvent Mouse event for dragging.
     * @param event QMouseEvent
     */
    void mousePressEvent(QMouseEvent *event) override;

    using QLabel::QLabel;


};

///**
// * @brief The DragAndDropGraphicsView class Custom QGraphicsView class
// */
//class DragAndDropWidget : public QWidget{
//    Q_OBJECT

//public:

//    /**
//    * @brief DragAndDropGraphicsView Constructor
//    * @param widget QWidget
//    */
//   explicit DragAndDropWidget(QWidget *parent);

//    /**
//    * @brief dragEnterEvent Drag enters a QGraphicsView event
//    * @param event QDragEnterEvent
//    */
//   void dragEnterEvent(QDragEnterEvent* event) override;

//   /**
//    * @brief dragLeaveEvent Drag leaves a QGraphicsView event
//    * @param event QDragLeaveEvent
//    */
//   void dragLeaveEvent(QDragLeaveEvent* event) override;

//   /**
//    * @brief dragMoveEvent Drag moves event
//    * @param event QDragMoveEvent
//    */
//   void dragMoveEvent(QDragMoveEvent* event) override;

//   /**
//    * @brief dropEvent A drop event
//    * @param event QDropEvent
//    */
//   void dropEvent(QDropEvent* event) override;

//   using QWidget::QWidget;

// signals:

//   /**
//     * @brief itemDrop Item is dropped to a QGraphicsView
//     */
//    void itemDrop(QPoint, QPixmap, QGraphicsView*);


//    //ruini test
//    void mouseRelease(QPoint pos);

//};

#endif // DRAGANDDROP_H
