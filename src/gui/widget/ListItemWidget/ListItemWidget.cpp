#include "gui/widget/ListItemWidget"

using namespace getit::gui::widget;

ListItemWidget::ListItemWidget(QListWidgetItem* listView, QWidget* widget):
    QListWidgetItem(listView)
{
    auto size = widget->size();
    size->setWidget(sizeHint().width());

    setSize(size);
}

ListItemWidget::~ListItemWidget()
{
    
}