/**************************************************************************
** This file is a part of our work (Siggraph'16 paper, binary, code and dataset):
**
** Roto++: Accelerating Professional Rotoscoping using Shape Manifolds
** Wenbin Li, Fabio Viola, Jonathan Starck, Gabriel J. Brostow and Neill D.F. Campbell
**
** w.li AT cs.ucl.ac.uk
** http://visual.cs.ucl.ac.uk/pubs/rotopp
**
** Copyright (c) 2016, Wenbin Li
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
** -- Redistributions of source code and data must retain the above
**    copyright notice, this list of conditions and the following disclaimer.
** -- Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
**
** THIS WORK AND THE RELATED SOFTWARE, SOURCE CODE AND DATA IS PROVIDED BY
** THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
** WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
** MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
** NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
** INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
** BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
** USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***************************************************************************/

#ifndef SNIPERVIEW_H
#define SNIPERVIEW_H

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QDebug>
#include "DesignScene.hpp"

using namespace std;

class SniperView : public QGraphicsView
{
    Q_OBJECT
private:
    QList<DesignScene*> scenes;
    DesignScene* curScene;
    qreal wid;
    qreal ptScale;
    QImage* img;
    QPointF focus_scene;
    QGraphicsItemGroup* cross;
public:
    //    SniperView(QWidget* parent = NULL): QGraphicsView(parent){}
    bool hasInit;
    SniperView(QWidget* parent = NULL);
    SniperView(QImage*,qreal,qreal);

    void setCurScene(DesignScene*);
    DesignScene* getCurScene(){return curScene;}
    void bacisSettings(qreal w = 200);
    void wheelEvent(QWheelEvent* event);//{Q_UNUSED(event);}
    void initView(QImage*,qreal w=200,qreal s=10);
    QGraphicsItemGroup* initCross(qreal);
public slots:
    void changeImg(QImage*);
    void setCenter(QPointF);
    void initScenes(QList<QImage*>);
    void changeScene(qreal);
};

#endif // SNIPERVIEW_H
