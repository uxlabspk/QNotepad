#ifndef HIGHCSS_H
#define HIGHCSS_H
#include <QSyntaxHighlighter>
#include <QRegularExpression>
QT_BEGIN_NAMESPACE
class QTextDocument;
class QTextCharFormat;
QT_END_NAMESPACE


class highcss : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    highcss(QTextDocument *parent = 0);

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

#endif // HIGHCSS_H
