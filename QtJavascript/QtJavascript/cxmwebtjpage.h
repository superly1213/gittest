#ifndef CXMWEBTJPAGE_H
#define CXMWEBTJPAGE_H

#include <QWidget>
#include "ui_cxmwebtjpage.h"

%NAMESPACE_BEGIN%class CXmWebTjPage : public QWidget
{
    Q_OBJECT

public:
    CXmWebTjPage(QWidget *parent = 0);
    ~CXmWebTjPage();

private:
    Ui::CXmWebTjPage ui;
};

%NAMESPACE_END%#endif // CXMWEBTJPAGE_H
