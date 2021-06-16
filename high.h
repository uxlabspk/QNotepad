#ifndef HIGH_H
#define HIGH_H
#include <QSyntaxHighlighter>

QT_BEGIN_NAMESPACE
class QTextDocument;
class QTextCharFormat;
QT_END_NAMESPACE


class high : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    high(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:

    enum States {
        None,
        Tag,
        Comment,
        Quote
    };

    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> startTagRules;
    QVector<HighlightingRule> endTagRules;

    QRegExp openTag;
    QRegExp closeTag;
    QTextCharFormat edgeTagFormat;
    QTextCharFormat insideTagFormat;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QTextCharFormat multiLineCommentFormat;

    QRegExp quotes;
    QTextCharFormat quotationFormat;
    QTextCharFormat tagsFormat;
};


#endif
