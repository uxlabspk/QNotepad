#include "high.h"
#include <QTextCharFormat>
#include <QBrush>
#include <QColor>


high::high(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    edgeTagFormat.setForeground(QBrush(QColor("#555")));
    insideTagFormat.setForeground(Qt::red);
    insideTagFormat.setFontWeight(QFont::Normal);
    openTag = QRegExp("<");
    closeTag = QRegExp(">");

    tagsFormat.setForeground(Qt::blue);
    tagsFormat.setFontWeight(QFont::Normal);
    QStringList keywordPatterns;
    keywordPatterns << "<\\ba\\b" << "<\\babbr\\b" << "<\\bacronym\\b" << "<\\baddress\\b" << "<\\bapplet\\b"
                    << "<\\barea\\b" << "<\\barticle\\b" << "<\\baside\\b" << "<\\baudio\\b" << "<\\bb\\b"
                    << "<\\bbase\\b" << "<\\bbasefont\\b" << "<\\bbdi\\b" << "<\\bbdo\\b" << "<\\bbgsound\\b"
                    << "<\\bblockquote\\b" << "<\\bbig\\b" << "<\\bbody\\b" << "<\\bblink\\b" << "<\\bbr\\b"
                    << "<\\bbutton\\b" << "<\\bcanvas\\b" << "<\\bcaption\\b" << "<\\bcenter\\b" << "<\\bcite\\b"
                    << "<\\bcode\\b" << "<\\bcol\\b" << "<\\bcolgroup\\b" << "<\\bcommand\\b" << "<\\bcomment\\b"
                    << "<\\bdata\\b" << "<\\bdatalist\\b" << "<\\bdd\\b" << "<\\bdel\\b" << "<\\bdetails\\b"
                    << "<\\bdfn\\b" << "<\\bdialog\\b" << "<\\bdir\\b" << "<\\bdiv\\b" << "<\\bdl\\b"
                    << "<\\bdt\\b" << "<\\bem\\b" << "<\\bembed\\b" << "<\\bfieldset\\b" << "<\\bfigcaption\\b"
                    << "<\\bfigure\\b" << "<\\bfont\\b" << "<\\bfooter\\b" << "<\\bform\\b" << "<\\bframe\\b"
                    << "<\\bframeset\\b" << "<\\bh1\\b" << "<\\bh2\\b" << "<\\bh3\\b" << "<\\bh4\\b"
                    << "<\\bh5\\b" << "<\\bh6\\b" << "<\\bhead\\b" << "<\\bheader\\b" << "<\\bhgroup\\b"
                    << "<\\bhr\\b" << "<\\bhtml\\b" << "<\\bi\\b" << "<\\biframe\\b" << "<\\bimg\\b"
                    << "<\\binput\\b" << "<\\bins\\b" << "<\\bisindex\\b" << "<\\bkbd\\b" << "<\\bkeygen\\b"
                    << "<\\blabel\\b" << "<\\blegend\\b" << "<\\bli\\b" << "<\\blink\\b" << "<\\blisting\\b"
                    << "<\\bmain\\b" << "<\\bmap\\b" << "<\\bmarquee\\b" << "<\\bmark\\b" << "<\\bmenu\\b"
                    << "<\\bamenuitem\\b" << "<\\bmeta\\b" << "<\\bmeter\\b" << "<\\bmulticol\\b" << "<\\bnav\\b"
                    << "<\\bnobr\\b" << "<\\bnoembed\\b" << "<\\bnoindex\\b" << "<\\bnoframes\\b" << "<\\bnoscript\\b"
                    << "<\\bobject\\b" << "<\\bol\\b" << "<\\boptgroup\\b" << "<\\boption\\b" << "<\\boutput\\b"
                    << "<\\bp\\b" << "<\\bparam\\b" << "<\\bpicture\\b" << "<\\bplaintext\\b" << "<\\bpre\\b"
                    << "<\\bprogress\\b" << "<\\bq\\b" << "<\\brp\\b" << "<\\brt\\b" << "<\\brtc\\b" << "<\\bruby\\b"
                    << "<\\bs\\b" << "<\\bsamp\\b" << "<\\bscript\\b" << "<\\bsection\\b" << "<\\bselect\\b"
                    << "<\\bsmall\\b" << "<\\bsource\\b" << "<\\bspacer\\b" << "<\\bspan\\b" << "<\\bstrike\\b"
                    << "<\\bstrong\\b" << "<\\bstyle\\b" << "<\\bsub\\b" << "<\\bsummary\\b" << "<\\bsup\\b"
                    << "<\\btable\\b" << "<\\btbody\\b" << "<\\btd\\b" << "<\\btemplate\\b" << "<\\btextarea\\b"
                    << "<\\btfoot\\b" << "<\\bth\\b" << "<\\bthead\\b" << "<\\btime\\b" << "<\\btitle\\b"
                    << "<\\btr\\b" << "<\\btrack\\b" << "<\\btt\\b" << "<\\bu\\b" << "<\\bul\\b" << "<\\bvar\\b"
                    << "<\\bvideo\\b" << "<\\bwbr\\b" << "<\\bxmp\\b";

    for (const QString &pattern : keywordPatterns)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = tagsFormat;
        startTagRules.append(rule);
    }

    QStringList keywordPatterns_end;
    keywordPatterns_end << "<!\\bDOCTYPE\\b" << "</\\ba\\b" << "</\\babbr\\b" << "</\\bacronym\\b" << "</\\baddress\\b" << "</\\bapplet\\b"
                        << "</\\barea\\b" << "</\\barticle\\b" << "</\\baside\\b" << "</\\baudio\\b" << "</\\bb\\b"
                        << "</\\bbase\\b" << "</\\bbasefont\\b" << "</\\bbdi\\b" << "</\\bbdo\\b" << "</\\bbgsound\\b"
                        << "</\\bblockquote\\b" << "</\\bbig\\b" << "</\\bbody\\b" << "</\\bblink\\b" << "</\\bbr\\b"
                        << "</\\bbutton\\b" << "</\\bcanvas\\b" << "</\\bcaption\\b" << "</\\bcenter\\b" << "</\\bcite\\b"
                        << "</\\bcode\\b" << "</\\bcol\\b" << "</\\bcolgroup\\b" << "</\\bcommand\\b" << "</\\bcomment\\b"
                        << "</\\bdata\\b" << "</\\bdatalist\\b" << "</\\bdd\\b" << "</\\bdel\\b" << "</\\bdetails\\b"
                        << "</\\bdfn\\b" << "</\\bdialog\\b" << "</\\bdir\\b" << "</\\bdiv\\b" << "</\\bdl\\b"
                        << "</\\bdt\\b" << "</\\bem\\b" << "</\\bembed\\b" << "</\\bfieldset\\b" << "</\\bfigcaption\\b"
                        << "</\\bfigure\\b" << "</\\bfont\\b" << "</\\bfooter\\b" << "</\\bform\\b" << "</\\bframe\\b"
                        << "</\\bframeset\\b" << "</\\bh1\\b" << "</\\bh2\\b" << "</\\bh3\\b" << "</\\bh4\\b"
                        << "</\\bh5\\b" << "</\\bh6\\b" << "</\\bhead\\b" << "</\\bheader\\b" << "</\\bhgroup\\b"
                        << "</\\bhr\\b" << "</\\bhtml\\b" << "</\\bi\\b" << "</\\biframe\\b" << "</\\bimg\\b"
                        << "</\\binput\\b" << "</\\bins\\b" << "</\\bisindex\\b" << "</\\bkbd\\b" << "</\\bkeygen\\b"
                        << "</\\blabel\\b" << "</\\blegend\\b" << "</\\bli\\b" << "</\\blink\\b" << "</\\blisting\\b"
                        << "</\\bmain\\b" << "</\\bmap\\b" << "</\\bmarquee\\b" << "</\\bmark\\b" << "</\\bmenu\\b"
                        << "</\\bamenuitem\\b" << "</\\bmeta\\b" << "</\\bmeter\\b" << "</\\bmulticol\\b" << "</\\bnav\\b"
                        << "</\\bnobr\\b" << "</\\bnoembed\\b" << "</\\bnoindex\\b" << "</\\bnoframes\\b" << "</\\bnoscript\\b"
                        << "</\\bobject\\b" << "</\\bol\\b" << "</\\boptgroup\\b" << "</\\boption\\b" << "</\\boutput\\b"
                        << "</\\bp\\b" << "</\\bparam\\b" << "</\\bpicture\\b" << "</\\bplaintext\\b" << "</\\bpre\\b"
                        << "</\\bprogress\\b" << "</\\bq\\b" << "</\\brp\\b" << "</\\brt\\b" << "</\\brtc\\b" << "</\\bruby\\b"
                        << "</\\bs\\b" << "</\\bsamp\\b" << "</\\bscript\\b" << "</\\bsection\\b" << "</\\bselect\\b"
                        << "</\\bsmall\\b" << "</\\bsource\\b" << "</\\bspacer\\b" << "</\\bspan\\b" << "</\\bstrike\\b"
                        << "</\\bstrong\\b" << "</\\bstyle\\b" << "</\\bsub\\b" << "</\\bsummary\\b" << "</\\bsup\\b"
                        << "</\\btable\\b" << "</\\btbody\\b" << "</\\btd\\b" << "</\\btemplate\\b" << "</\\btextarea\\b"
                        << "</\\btfoot\\b" << "</\\bth\\b" << "</\\bthead\\b" << "</\\btime\\b" << "</\\btitle\\b"
                        << "</\\btr\\b" << "</\\btrack\\b" << "</\\btt\\b" << "</\\bu\\b" << "</\\bul\\b" << "</\\bvar\\b"
                        << "</\\bvideo\\b" << "</\\bwbr\\b" << "</\\bxmp\\b";

    for (const QString &pattern : keywordPatterns_end)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = tagsFormat;
        endTagRules.append(rule);
    }

    multiLineCommentFormat.setForeground(Qt::darkGreen);
    commentStartExpression = QRegExp("<!-");
    commentEndExpression = QRegExp("->");

    quotationFormat.setForeground(Qt::blue);
    quotes = QRegExp("\"");
}

void high::highlightBlock(const QString &text)
{
    setCurrentBlockState(high::None);

    // TAG
    int startIndex = 0;
    // If you're not within a tag,
    if (previousBlockState() != high::Tag && previousBlockState() != high::Quote)
    {
        // So we try to find the beginning of the next tag
        startIndex = openTag.indexIn(text);
    }

    // Taking the state of the previous text block
    int subPreviousTag = previousBlockState();
    while (startIndex >= 0)
    {
        // We are looking for an end-tag
        int endIndex = closeTag.indexIn(text, startIndex);

        int tagLength;
        // If the end tag is not found, then we set the block state
        if (endIndex == -1)
        {
            setCurrentBlockState(high::Tag);
            tagLength = text.length() - startIndex;
        }
        else
        {
            tagLength = endIndex - startIndex + closeTag.matchedLength();
        }

        // Set the formatting for a tag
        if (subPreviousTag != high::Tag)
        {
            // since the beginning of the tag to the end, if the previous status is not equal Tag
            setFormat(startIndex, 1, edgeTagFormat);
            setFormat(startIndex + 1, tagLength - 1, insideTagFormat);
        }
        else
        {
            // If you're already inside the tag from the start block
            // and before the end tag
            setFormat(startIndex, tagLength, insideTagFormat);
            subPreviousTag = high::None;
        }
        // Format the symbol of the end tag
        setFormat(endIndex, 1, edgeTagFormat);

        /// QUOTES ///////////////////////////////////////
        int startQuoteIndex = 0;
        // If you are not in quotation marks with the previous block
        if (previousBlockState() != high::Quote)
        {
            // So we try to find the beginning of the quotes
            startQuoteIndex = quotes.indexIn(text, startIndex);
        }

        // Highlights all quotes within the tag
        while (startQuoteIndex >= 0 && ((startQuoteIndex < endIndex) || (endIndex == -1)))
        {
            int endQuoteIndex = quotes.indexIn(text, startQuoteIndex + 1);
            int quoteLength;
            if (endQuoteIndex == -1)
            {
                // If a closing quotation mark is found, set the state for the block Quote
                setCurrentBlockState(high::Quote);
                quoteLength = text.length() - startQuoteIndex;
            }
            else
            {
                quoteLength = endQuoteIndex - startQuoteIndex + quotes.matchedLength();
            }

            if ((endIndex > endQuoteIndex) || endIndex == -1)
            {
                setFormat(startQuoteIndex, quoteLength, quotationFormat);
                startQuoteIndex = quotes.indexIn(text, startQuoteIndex + quoteLength);
            }
            else
            {
                break;
            }
        }
        //////////////////////////////////////////////////
        // Again, look for the beginning of the tag
        startIndex = openTag.indexIn(text, startIndex + tagLength);
    }

    // EDGES OF TAGS
    // Processing of color tags themselves, that is, highlight words div, p, strong etc.
    for (const HighlightingRule &rule : startTagRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index + 1, length - 1, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    for (const HighlightingRule &rule : endTagRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index + 1, 1, edgeTagFormat);
            setFormat(index + 2, length - 2, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    // COMMENT
    int startCommentIndex = 0;
    // If the tag is not a previous state commentary
    if (previousBlockState() != high::Comment)
    {
        // then we try to find the beginning of a comment
        startCommentIndex = commentStartExpression.indexIn(text);
    }

    // If a comment is found
    while (startCommentIndex >= 0)
    {
        // We are looking for the end of the comment
        int endCommentIndex = commentEndExpression.indexIn(text, startCommentIndex);
        int commentLength;

        // If the end is not found
        if (endCommentIndex == -1)
        {
            // That set the state Comment
            // The principle is similar to that for conventional tags
            setCurrentBlockState(high::Comment);
            commentLength = text.length() - startCommentIndex;
        }
        else
        {
            commentLength = endCommentIndex - startCommentIndex
                            + commentEndExpression.matchedLength();
        }

        setFormat(startCommentIndex, commentLength, multiLineCommentFormat);
        startCommentIndex = commentStartExpression.indexIn(text, startCommentIndex + commentLength);
    }
}

