#ifndef HIGHJS_H
#define HIGHJS_H
#include <QSyntaxHighlighter>
#include <QRegularExpression>
QT_BEGIN_NAMESPACE
class QTextDocument;
class QTextCharFormat;
QT_END_NAMESPACE



class highjs : public QSyntaxHighlighter
{
public:
    highjs(QTextDocument *parent = 0);

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

#endif // HIGHJS_H
