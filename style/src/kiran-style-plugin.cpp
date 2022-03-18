/**
 * Copyright (c) 2020 ~ 2022 KylinSec Co., Ltd.
 * kiran-qt5-integration is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 *
 * Author:     liuxinhao <liuxinhao@kylinos.com.cn>
 */
#include "kiran-style-plugin.h"
#include "style.h"

#include <QCoreApplication>
#include <QDebug>

KiranStylePlugin::KiranStylePlugin(QObject *parent) : QStylePlugin(parent)
{

}

QStringList KiranStylePlugin::keys() const
{
    return QStringList() << "Kiran"
                         << "Kiran-dark";
}

QStyle *KiranStylePlugin::create(const QString & key)
{
    //TODO:根据情况，后期加入黑名单，屏蔽掉一些不需要加载KiranStyle的Qt程序
    qInfo("create style:%s",key.toStdString().c_str());

    if( key.compare("Kiran",Qt::CaseInsensitive) == 0 ||
        key.compare("Kiran-dark",Qt::CaseInsensitive) == 0 )
    {
        return new Kiran::Style::Style();
    }

    return nullptr;
}
