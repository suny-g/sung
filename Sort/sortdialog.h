// sortdialog.h
#pragma once

#include <QDialog>

namespace Ui { class tw_SortDialog; }

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = nullptr);
    virtual ~SortDialog() override;

    void setColumnRange(QChar first, QChar last);

private slots:
    void on_moreButton_toggled(bool checked);

private:
    Ui::tw_SortDialog *_ui;
};
