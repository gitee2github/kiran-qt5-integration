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
#include "kiran-integration-settings.h"

#include <QCoreApplication>
#include <QDebug>
#include <QStyleFactory>

KiranStylePlugin::KiranStylePlugin(QObject *parent) : QStylePlugin(parent)
{

}

QStyle *KiranStylePlugin::create(const QString & key)
{
    if( key.compare("kiran",Qt::CaseInsensitive) == 0 )
    {
        QStringList disableApps = KiranIntegrationSettings::instance()->getDisableKiranStyleApps();
        QString processName = qAppName();
        if( disableApps.contains(processName) )
        {
            qDebug("%s in black list,create fusion style for it.",processName.toStdString().c_str());
            return QStyleFactory::create("fusion");
        }
        else
        {
            qDebug("create style:%s",key.toStdString().c_str());
            return new Style();
        }
    }
    return nullptr;
}
