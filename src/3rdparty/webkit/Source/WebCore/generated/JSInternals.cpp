/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSInternals.h"

#include "ExceptionCode.h"
#include "Internals.h"
#include "JSDOMBinding.h"
#include "JSDocument.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSInternals);

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSInternalsPrototypeTableValues[3] =
{
    { "setPasswordEchoEnabled", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsInternalsPrototypeFunctionSetPasswordEchoEnabled), (intptr_t)2 THUNK_GENERATOR(0) },
    { "setPasswordEchoDurationInSeconds", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsInternalsPrototypeFunctionSetPasswordEchoDurationInSeconds), (intptr_t)2 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSInternalsPrototypeTable = { 5, 3, JSInternalsPrototypeTableValues, 0 };
const ClassInfo JSInternalsPrototype::s_info = { "InternalsPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSInternalsPrototypeTable, 0 };

JSObject* JSInternalsPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSInternals>(exec, globalObject);
}

bool JSInternalsPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSInternalsPrototypeTable, this, propertyName, slot);
}

bool JSInternalsPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSInternalsPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSInternals::s_info = { "Internals", &JSDOMWrapper::s_info, 0, 0 };

JSInternals::JSInternals(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<Internals> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSInternals::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSInternalsPrototype(exec->globalData(), globalObject, JSInternalsPrototype::createStructure(globalObject->globalData(), globalObject->objectPrototype()));
}

EncodedJSValue JSC_HOST_CALL jsInternalsPrototypeFunctionSetPasswordEchoEnabled(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSInternals::s_info))
        return throwVMTypeError(exec);
    JSInternals* castedThis = static_cast<JSInternals*>(asObject(thisValue));
    Internals* imp = static_cast<Internals*>(castedThis->impl());
    ExceptionCode ec = 0;
    Document* document(toDocument(exec->argument(0)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool enabled(exec->argument(1).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->setPasswordEchoEnabled(document, enabled, ec);
    setDOMException(exec, ec);
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsInternalsPrototypeFunctionSetPasswordEchoDurationInSeconds(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSInternals::s_info))
        return throwVMTypeError(exec);
    JSInternals* castedThis = static_cast<JSInternals*>(asObject(thisValue));
    Internals* imp = static_cast<Internals*>(castedThis->impl());
    ExceptionCode ec = 0;
    Document* document(toDocument(exec->argument(0)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    double durationInSeconds(exec->argument(1).toNumber(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->setPasswordEchoDurationInSeconds(document, durationInSeconds, ec);
    setDOMException(exec, ec);
    return JSValue::encode(jsUndefined());
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, Internals* impl)
{
    return wrap<JSInternals>(exec, globalObject, impl);
}

Internals* toInternals(JSC::JSValue value)
{
    return value.inherits(&JSInternals::s_info) ? static_cast<JSInternals*>(asObject(value))->impl() : 0;
}

}
