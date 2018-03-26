// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ddict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "TFWcut.h"
#include "TFLcut.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *TFWcut_Dictionary();
   static void TFWcut_TClassManip(TClass*);
   static void delete_TFWcut(void *p);
   static void deleteArray_TFWcut(void *p);
   static void destruct_TFWcut(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TFWcut*)
   {
      ::TFWcut *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TFWcut));
      static ::ROOT::TGenericClassInfo 
         instance("TFWcut", "TFWcut.h", 11,
                  typeid(::TFWcut), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TFWcut_Dictionary, isa_proxy, 0,
                  sizeof(::TFWcut) );
      instance.SetDelete(&delete_TFWcut);
      instance.SetDeleteArray(&deleteArray_TFWcut);
      instance.SetDestructor(&destruct_TFWcut);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TFWcut*)
   {
      return GenerateInitInstanceLocal((::TFWcut*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TFWcut*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TFWcut_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TFWcut*)0x0)->GetClass();
      TFWcut_TClassManip(theClass);
   return theClass;
   }

   static void TFWcut_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TFLcut_Dictionary();
   static void TFLcut_TClassManip(TClass*);
   static void delete_TFLcut(void *p);
   static void deleteArray_TFLcut(void *p);
   static void destruct_TFLcut(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TFLcut*)
   {
      ::TFLcut *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TFLcut));
      static ::ROOT::TGenericClassInfo 
         instance("TFLcut", "TFLcut.h", 11,
                  typeid(::TFLcut), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TFLcut_Dictionary, isa_proxy, 0,
                  sizeof(::TFLcut) );
      instance.SetDelete(&delete_TFLcut);
      instance.SetDeleteArray(&deleteArray_TFLcut);
      instance.SetDestructor(&destruct_TFLcut);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TFLcut*)
   {
      return GenerateInitInstanceLocal((::TFLcut*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TFLcut*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TFLcut_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TFLcut*)0x0)->GetClass();
      TFLcut_TClassManip(theClass);
   return theClass;
   }

   static void TFLcut_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TFWcut(void *p) {
      delete ((::TFWcut*)p);
   }
   static void deleteArray_TFWcut(void *p) {
      delete [] ((::TFWcut*)p);
   }
   static void destruct_TFWcut(void *p) {
      typedef ::TFWcut current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TFWcut

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TFLcut(void *p) {
      delete ((::TFLcut*)p);
   }
   static void deleteArray_TFLcut(void *p) {
      delete [] ((::TFLcut*)p);
   }
   static void destruct_TFLcut(void *p) {
      typedef ::TFLcut current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TFLcut

namespace {
  void TriggerDictionaryInitialization_ddict_Impl() {
    static const char* headers[] = {
"TFWcut.h",
"TFLcut.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/root/build/include",
"/Users/deuteron/HallC/simc_deep/TFcut/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ddict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TFWcut.h")))  TFWcut;
class __attribute__((annotate("$clingAutoload$TFLcut.h")))  TFLcut;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ddict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "TFWcut.h"
#include "TFLcut.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TFLcut", payloadCode, "@",
"TFWcut", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ddict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ddict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ddict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ddict() {
  TriggerDictionaryInitialization_ddict_Impl();
}
