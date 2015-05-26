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

#if ENABLE(WEB_AUDIO)

#include "JSDelayNode.h"

#include "AudioParam.h"
#include "DelayNode.h"
#include "JSAudioParam.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSDelayNode);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDelayNodeTableValues[3] =
{
    { "delayTime", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDelayNodeDelayTime), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDelayNodeConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDelayNodeTable = { 4, 3, JSDelayNodeTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDelayNodeConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDelayNodeConstructorTable = { 1, 0, JSDelayNodeConstructorTableValues, 0 };
class JSDelayNodeConstructor : public DOMConstructorObject {
public:
    JSDelayNodeConstructor(JSC::ExecState*, JSC::Structure*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSDelayNodeConstructor::s_info = { "DelayNodeConstructor", &DOMConstructorObject::s_info, &JSDelayNodeConstructorTable, 0 };

JSDelayNodeConstructor::JSDelayNodeConstructor(ExecState* exec, Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSDelayNodePrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSDelayNodeConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDelayNodeConstructor, JSDOMWrapper>(exec, &JSDelayNodeConstructorTable, this, propertyName, slot);
}

bool JSDelayNodeConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSDelayNodeConstructor, JSDOMWrapper>(exec, &JSDelayNodeConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDelayNodePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDelayNodePrototypeTable = { 1, 0, JSDelayNodePrototypeTableValues, 0 };
const ClassInfo JSDelayNodePrototype::s_info = { "DelayNodePrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSDelayNodePrototypeTable, 0 };

JSObject* JSDelayNodePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSDelayNode>(exec, globalObject);
}

const ClassInfo JSDelayNode::s_info = { "DelayNode", &JSAudioNode::s_info, &JSDelayNodeTable, 0 };

JSDelayNode::JSDelayNode(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<DelayNode> impl)
    : JSAudioNode(structure, globalObject, impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSDelayNode::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSDelayNodePrototype(exec->globalData(), globalObject, JSDelayNodePrototype::createStructure(exec->globalData(), JSAudioNodePrototype::self(exec, globalObject)));
}

bool JSDelayNode::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDelayNode, Base>(exec, &JSDelayNodeTable, this, propertyName, slot);
}

bool JSDelayNode::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSDelayNode, Base>(exec, &JSDelayNodeTable, this, propertyName, descriptor);
}

JSValue jsDelayNodeDelayTime(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDelayNode* castedThis = static_cast<JSDelayNode*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    DelayNode* imp = static_cast<DelayNode*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->delayTime()));
    return result;
}


JSValue jsDelayNodeConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDelayNode* domObject = static_cast<JSDelayNode*>(asObject(slotBase));
    return JSDelayNode::getConstructor(exec, domObject->globalObject());
}

JSValue JSDelayNode::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSDelayNodeConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, DelayNode* impl)
{
    return wrap<JSDelayNode>(exec, globalObject, impl);
}


}

#endif // ENABLE(WEB_AUDIO)
