#include "qqresetpswd.h"
#include "ui_qqresetpswd.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "writeAndread.h"
#include "qqresetpd_err.h"

extern user_dyh* CurUser;
extern FriendManager_dyh& userls;
inline const std::string QQUserfile = "D:\\CS\\QtProject\\cpp_dyh\\QQuserlist.json";

QQResetPswd::QQResetPswd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QQResetPswd) {
    ui->setupUi(this);
    err = new qqresetpd_err;
}

QQResetPswd::~QQResetPswd() {
    delete ui;
}

void QQResetPswd::LinkQQDetail(QWidget* p) {
    this->qqdetail = p;
}

void QQResetPswd::on_pushButton_clicked() {
    std::string oringin = ui->oringinLdt->text().toStdString();
    std::string newpd1 = ui->newLdt1->text().toStdString();
    std::string newpd2 = ui->newLdt2->text().toStdString();
    if (oringin == CurUser->getPassword() && newpd1 == newpd2 && !oringin.empty() && !newpd1.empty() && !newpd2.empty()) {
        CurUser->setPassword(newpd1);
        writeUsersToFile(QQUserfile, userls.showUserls());
        this->hide();
        qqdetail->show();
    } else {
        ui->oringinLdt->clear();
        ui->newLdt1->clear();
        ui->newLdt2->clear();
        err->show();
    }
}

void QQResetPswd::initLab() {
    ui->idLab->setText(QString::fromStdString(CurUser->getId()));
    ui->nameLab->setText(QString::fromStdString(CurUser->getNickname()));
}


void QQResetPswd::on_pushButton_2_clicked() {
    this->hide();
    qqdetail->show();
}
