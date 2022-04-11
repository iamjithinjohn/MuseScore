#include <QClipboard>
#include <QApplication>

#include "lyricseditormodel.h"

mu::instrumentsscene::LyricsEditorModel::LyricsEditorModel()
{
    context()->currentNotationChanged().onNotify(this, [this]() {
        auto notation = context()->currentNotation();
        auto interaction = notation->interaction();
        interaction->textEditingChanged().onNotify(this, [this]() {
            updateLyrics();
            emit lyricsUpdated();
        });
        updateLyrics();
    });
}

QString mu::instrumentsscene::LyricsEditorModel::updateLyrics()
{
    auto notation = context()->currentNotation();
    auto interaction = notation->interaction();
    // #if defined(Q_OS_MAC) || defined(Q_OS_WIN)
    //     QClipboard::Mode mode = QClipboard::Clipboard;
    //     #else
    //     QClipboard::Mode mode = QClipboard::Selection;
    //     #endif
    // QString txt = QGuiApplication::clipboard()->text(mode);
    // return txt;

    interaction->copyLyrics();
    return QApplication::clipboard()->text();
}