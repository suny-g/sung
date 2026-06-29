// sortdialog.cpp
#include "sortdialog.h"
#include "ui_sortdialog.h"
#include <QDebug>

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
    , _ui(new Ui::tw_SortDialog)
{
    _ui->setupUi(this);

    layout()->setSizeConstraint(QLayout::SetFixedSize);

    connect(_ui->okButton, &QPushButton::clicked, this, &SortDialog::accept);
    connect(_ui->cancelButton, &QPushButton::clicked, this, &SortDialog::reject);

}

SortDialog::~SortDialog()
{
    delete _ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    _ui->primaryColumnComboBox->clear();
    _ui->secondaryColumnComboBox->clear();
    _ui->tertiaryColumnComboBox->clear();

    _ui->secondaryColumnComboBox->addItem("None");
    _ui->tertiaryColumnComboBox->addItem("None");

    QChar ch = first;
    while (ch <= last) {
        QString colName = QString(ch);
        _ui->primaryColumnComboBox->addItem(colName);
        _ui->secondaryColumnComboBox->addItem(colName);
        _ui->tertiaryColumnComboBox->addItem(colName);
        ch = QChar(ch.unicode() + 1);
    }
}

void SortDialog::on_moreButton_toggled(bool checked)
{
    _ui->secondaryGroupBox->setVisible(checked);
    _ui->tertiaryGroupBox->setVisible(checked);
}
