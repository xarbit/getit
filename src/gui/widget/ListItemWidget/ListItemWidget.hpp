#pragma once

#include <QListWidget>
#include <QListWidgetItem>

namespace getit::gui::widget
{
    class ListItemWidget: public QListWidgetItem
    {
        public:
            ListItemWidget(QListWidget* listview, QWidget* widget);
            ~ListItemWidget() {}
    }
}