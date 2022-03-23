/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_SYSTEM_IFILESYSTEM_H
#define MU_SYSTEM_IFILESYSTEM_H

#include <QtCore>
#include "modularity/imoduleexport.h"
#include "retval.h"
#include "io/path.h"

namespace mu::framework {
class IClipboard {
public:
    virtual void setText(const QString& text) = 0;
    virtual QString text() const = 0;
    
    virtual QMimeData* mimeData() const = 0;
    virtual void setMimeData(QMimeData* data) = 0;
};
}

#endif // MU_SYSTEM_IFILESYSTEM_H
