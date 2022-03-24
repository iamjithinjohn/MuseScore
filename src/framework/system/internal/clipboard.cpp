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
#include "clipboard.h"

#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QClipboard>

#include <QApplication>


#ifdef Q_OS_WIN
#include <windows.h>
#endif

#include "systemerrors.h"
#include "log.h"
#include "../../../../engraving/libmscore/textedit.h"


using namespace mu;
using namespace mu::system;

void setText(const Ms::TextEditData* text)
{
#if defined(Q_OS_MAC) || defined(Q_OS_WIN)
    QClipboard::Mode mode = QClipboard::Clipboard;
#else
    QClipboard::Mode mode = QClipboard::Selection;
#endif
    QApplication::clipboard()->setText(text->selectedText, mode);
}