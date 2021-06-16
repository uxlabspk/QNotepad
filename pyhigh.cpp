#include "pyhigh.h"
#include <QTextCharFormat>
#include <QBrush>
#include <QColor>


pyhigh::pyhigh(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    keywordFormat.setForeground(Qt::darkGreen);
        keywordFormat.setFontWeight(QFont::DemiBold);
        const QString keywordPatterns[] = {
            QStringLiteral("\\bchar\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"),
            QStringLiteral("\\bdouble\\b"), QStringLiteral("\\benum\\b"), QStringLiteral("\\bexplicit\\b"),
            QStringLiteral("\\bfriend\\b"), QStringLiteral("\\binline\\b"), QStringLiteral("\\bint\\b"),
            QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
            QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"),
            QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
            QStringLiteral("\\bslots\\b"), QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bstruct\\b"),
            QStringLiteral("\\btemplate\\b"), QStringLiteral("\\btypedef\\b"), QStringLiteral("\\basync\\b"),
            QStringLiteral("\\bunion\\b"), QStringLiteral("\\bwith\\b"), QStringLiteral("\\bvirtual\\b"),
            QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bawait\\b"), QStringLiteral("\\bbool\\b") ,
            QStringLiteral("\\busing\\b") , QStringLiteral("\\blambda\\b") , QStringLiteral("\\bstring\\b") , QStringLiteral("\\bdef\\b") ,
            QStringLiteral("\\bimport\\b") , QStringLiteral("\\bfrom\\b")
        };
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
                rule.pattern = QRegularExpression(QStringLiteral("\'.*\'"));
                rule.format = quotationFormat;
                highlightingRules.append(rule);

                //-------------my-----------------//
                QTextCharFormat re;
                re.setForeground(Qt::darkRed);
                rule.pattern = QRegularExpression(QStringLiteral("\\breturn\\b"));
                rule.format = re;
                highlightingRules.append(rule);

                QTextCharFormat console;
                console.setForeground(QBrush("pink"));
                rule.pattern = QRegularExpression(QStringLiteral("\\bprint\\b"));
                rule.format = console;
                highlightingRules.append(rule);


                QTextCharFormat inse;
                inse.setForeground(Qt::darkYellow);
                rule.pattern = QRegularExpression(QStringLiteral("\\b = \\b"));
                rule.format = inse;
                highlightingRules.append(rule);
                QTextCharFormat inse1;
                inse1.setForeground(Qt::darkRed);
                rule.pattern = QRegularExpression(QStringLiteral("="));
                rule.format = inse1;
                highlightingRules.append(rule);

                QTextCharFormat tag;
                tag.setForeground(Qt::darkRed);
                rule.pattern = QRegularExpression(QStringLiteral("\\bfor\\b"));
                rule.format = tag;
                highlightingRules.append(rule);

                QTextCharFormat term;
                term.setForeground(Qt::red);
                rule.pattern = QRegularExpression(QStringLiteral(":"));
                rule.format = term;
                highlightingRules.append(rule);

                QTextCharFormat hash;
                hash.setForeground(QBrush("purple"));
                rule.pattern = QRegularExpression(QStringLiteral("@"));
                rule.format = hash;
                highlightingRules.append(rule);

                QTextCharFormat ins;
                ins.setForeground(QBrush("brown"));
                rule.pattern = QRegularExpression(QStringLiteral("<"));
                rule.format = ins;
                highlightingRules.append(rule);

                QTextCharFormat ins2;
                ins2.setForeground(QBrush("brown"));
                rule.pattern = QRegularExpression(QStringLiteral(">"));
                rule.format = ins2;
                highlightingRules.append(rule);

                QTextCharFormat endl;
                endl.setForeground(QBrush("blue"));
                rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
                rule.format = endl;
                highlightingRules.append(rule);


                //---------------my--------------//

                functionFormat.setFontItalic(true);
                functionFormat.setForeground(QBrush("orange"));        //functions
                rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
                rule.format = functionFormat;
                highlightingRules.append(rule);
                singleLineCommentFormat.setForeground(Qt::gray);        //single line comments
                    rule.pattern = QRegularExpression(QStringLiteral("#[^\n]*"));
                    rule.format = singleLineCommentFormat;
                    highlightingRules.append(rule);

                    multiLineCommentFormat.setForeground(Qt::gray);     //multiline comments

                    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
                    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}


}
void pyhigh::highlightBlock(const QString &text)
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

