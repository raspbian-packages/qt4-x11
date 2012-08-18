/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

/* NOTE: This file is AUTO GENERATED by qautomaton2cpp.xsl. */

#ifndef qxslttokenlookup_p_H
#define qxslttokenlookup_p_H

#include <QtCore/QString>

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    class XSLTTokenLookup
    {
        public:
            enum NodeName

            {
                NoKeyword,
                AnalyzeString,
                ApplyTemplates,
                As,
                Attribute,
                AttributeSet,
                ByteOrderMark,
                CallTemplate,
                CaseOrder,
                CdataSectionElements,
                Choose,
                Collation,
                Comment,
                Copy,
                CopyNamespaces,
                CopyOf,
                DataType,
                DefaultCollation,
                DefaultValidation,
                DoctypePublic,
                DoctypeSystem,
                Document,
                Element,
                Elements,
                Encoding,
                EscapeUriAttributes,
                ExcludeResultPrefixes,
                ExtensionElementPrefixes,
                Flags,
                ForEach,
                Format,
                Function,
                Href,
                Id,
                If,
                Import,
                ImportSchema,
                Include,
                IncludeContentType,
                Indent,
                InheritNamespaces,
                InputTypeAnnotations,
                Key,
                Lang,
                Match,
                MatchingSubstring,
                MediaType,
                Message,
                Method,
                Mode,
                Name,
                Namespace,
                NonMatchingSubstring,
                NormalizationForm,
                OmitXmlDeclaration,
                Order,
                Otherwise,
                Output,
                OutputVersion,
                Override,
                Param,
                PerformSort,
                PreserveSpace,
                Priority,
                ProcessingInstruction,
                Regex,
                Required,
                ResultDocument,
                SchemaLocation,
                Select,
                Separator,
                Sequence,
                Sort,
                Stable,
                Standalone,
                StripSpace,
                Stylesheet,
                Template,
                Terminate,
                Test,
                Text,
                Transform,
                Tunnel,
                Type,
                UndeclarePrefixes,
                Use,
                UseAttributeSets,
                UseCharacterMaps,
                UseWhen,
                Validation,
                ValueOf,
                Variable,
                Version,
                When,
                WithParam,
                XpathDefaultNamespace
            };

            static inline NodeName toToken(const QString &value);
            static inline NodeName toToken(const QStringRef &value);
            static NodeName toToken(const QChar *data, int length);
            static QString toString(NodeName token);


        private:
            static inline NodeName classifier2(const QChar *data);
            static inline NodeName classifier3(const QChar *data);
            static inline NodeName classifier4(const QChar *data);
            static inline NodeName classifier5(const QChar *data);
            static inline NodeName classifier6(const QChar *data);
            static inline NodeName classifier7(const QChar *data);
            static inline NodeName classifier8(const QChar *data);
            static inline NodeName classifier9(const QChar *data);
            static inline NodeName classifier10(const QChar *data);
            static inline NodeName classifier11(const QChar *data);
            static inline NodeName classifier12(const QChar *data);
            static inline NodeName classifier13(const QChar *data);
            static inline NodeName classifier14(const QChar *data);
            static inline NodeName classifier15(const QChar *data);
            static inline NodeName classifier17(const QChar *data);
            static inline NodeName classifier18(const QChar *data);
            static inline NodeName classifier20(const QChar *data);
            static inline NodeName classifier21(const QChar *data);
            static inline NodeName classifier22(const QChar *data);
            static inline NodeName classifier23(const QChar *data);
            static inline NodeName classifier26(const QChar *data);

    };

    inline XSLTTokenLookup::NodeName XSLTTokenLookup::toToken(const QString &value)
    {
        return toToken(value.constData(), value.length());
    }

    inline XSLTTokenLookup::NodeName XSLTTokenLookup::toToken(const QStringRef &value)
    {
        return toToken(value.constData(), value.length());
    }

}

QT_END_NAMESPACE

#endif
