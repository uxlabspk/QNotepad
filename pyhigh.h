#ifndef PYHIGH_H
#define PYHIGH_H
#include <QSyntaxHighlighter>
#include <QRegularExpression>
QT_BEGIN_NAMESPACE
class QTextDocument;
class QTextCharFormat;
QT_END_NAMESPACE


class pyhigh : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    pyhigh(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};
#endif // PYHIGH_H
