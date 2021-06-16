#include "highcss.h"
#include <QTextCharFormat>
#include <QBrush>
#include <QColor>


highcss::highcss(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    keywordFormat.setForeground(Qt::red);
        keywordFormat.setFontWeight(QFont::Bold);
        const QString keywordPatterns[] = {
            QStringLiteral("\\bmargin\\b"), QStringLiteral("\\bbackground-color\\b"), QStringLiteral("\\btext-decoration\\b"),
            QStringLiteral("\\bpadding\\b"), QStringLiteral("\\bcolor\\b"), QStringLiteral("\\bdisplay\\b"),
            QStringLiteral("\\boverflow\\b"), QStringLiteral("\\bposition\\b") , QStringLiteral("\\bheight\\b") , QStringLiteral("\\bwidth\\b")};
            /*QStringLiteral("\\bint\\b"),
            QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
            QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"),
            QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
            QStringLiteral("\\bslots\\b"), QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bstruct\\b"),
            QStringLiteral("\\btemplate\\b"), QStringLiteral("\\btypedef\\b"), QStringLiteral("\\btypename\\b"),
            QStringLiteral("\\bunion\\b"), QStringLiteral("\\bunsigned\\b"), QStringLiteral("\\bvirtual\\b"),
            QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"), QStringLiteral("\\bbool\\b") ,
            QStringLiteral("\\busing\\b") , QStringLiteral("\\bstd\\b") , QStringLiteral("\\bstring\\b")
        };*/
        for (const QString &pattern : keywordPatterns) {
            rule.pattern = QRegularExpression(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
            classFormat.setFontWeight(QFont::Bold);
                classFormat.setForeground(Qt::darkMagenta);
                rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
                rule.format = classFormat;
                highlightingRules.append(rule);

                quotationFormat.setForeground(Qt::blue);  //inside double encodes
                rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
                rule.format = quotationFormat;
                highlightingRules.append(rule);

                //-------------my-----------------//


                QTextCharFormat term;
                term.setForeground(Qt::red);
                rule.pattern = QRegularExpression(QStringLiteral(";"));
                rule.format = term;
                highlightingRules.append(rule);

                //---------------my--------------//

                functionFormat.setFontItalic(true);
                functionFormat.setForeground(Qt::darkGreen);        //functions
                rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
                rule.format = functionFormat;
                highlightingRules.append(rule);
                singleLineCommentFormat.setForeground(Qt::gray);        //single line comments
                    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
                    rule.format = singleLineCommentFormat;
                    highlightingRules.append(rule);

                    multiLineCommentFormat.setForeground(Qt::gray);     //multiline comments

                    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
                    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}


}
void highcss::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);
    int startIndex = 0;
       if (previousBlockState() != 1)
           startIndex = text.indexOf(commentStartExpression);
       while (startIndex >= 0) {
               QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
               int endIndex = match.capturedStart();
               int commentLength = 0;
               if (endIndex == -1) {
                   setCurrentBlockState(1);
                   commentLength = text.length() - startIndex;
               } else {
                   commentLength = endIndex - startIndex
                                   + match.capturedLength();
               }
               setFormat(startIndex, commentLength, multiLineCommentFormat);
               startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
           }
}

