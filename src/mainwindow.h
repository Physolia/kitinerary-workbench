/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KItinerary/Uic9183Parser>

#include <KCalendarCore/Calendar>

#include <KXmlGuiWindow>

#include <memory>

namespace KItinerary {
class HtmlDocument;
class PdfDocument;
}

namespace KPkPass {
class Pass;
}

namespace KMime {
class Message;
}

namespace KTextEditor {
class Document;
class View;
}

namespace Ui
{
class MainWindow;
}

class AttributeModel;
class DOMModel;
class QStandardItemModel;

class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum Type {
        PlainText,
        Html,
        Pdf,
        PkPass,
        IataBcbp,
        JsonLd,
        Uic9183,
        Image,
        ICal,
        Mime,
        Vdv
    };
    Q_ENUM(Type)

    static Type typeFromName(const QString &name);

    Type type() const;
    void setType(Type type);

    void openFile(const QString &file);

private:
    enum InputTab {
        ExtractorEditorTab = 0,
        InputTab = 1,
        TextTab = 2,
        ImageTab = 3,
        DomTab = 4,
        Uic9183Tab = 5
    };

    enum OutputTab {
        ExtractorOutputTab = 0,
        PostprocessorTab = 1,
        ValidatedTab = 2,
        ICalTab = 3,
        ConsoleTab = 4
    };

    void typeChanged();
    void sourceChanged();
    void urlChanged();
    void imageContextMenu(QPoint pos);

private:
    std::unique_ptr<Ui::MainWindow> ui;

    KTextEditor::Document *m_sourceDoc = nullptr;
    KTextEditor::Document *m_preprocDoc = nullptr;
    KTextEditor::Document *m_outputDoc = nullptr;
    KTextEditor::Document *m_postprocDoc = nullptr;
    KTextEditor::Document *m_validatedDoc = nullptr;
    KTextEditor::Document *m_icalDoc = nullptr;
    KTextEditor::View *m_sourceView = nullptr;

    QStandardItemModel *m_imageModel;
    DOMModel *m_domModel;
    AttributeModel *m_attrModel;

    std::unique_ptr<KPkPass::Pass> m_pkpass;
    std::unique_ptr<KItinerary::HtmlDocument> m_htmlDoc;
    std::unique_ptr<KItinerary::PdfDocument> m_pdfDoc;
    QImage m_image;
    KCalendarCore::Calendar::Ptr m_calendar;
    std::unique_ptr<KMime::Message> m_mimeMessage;

    KItinerary::Uic9183Parser m_ticketParser;
};

#endif // MAINWINDOW_H
