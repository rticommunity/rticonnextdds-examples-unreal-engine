

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from UnrealBasicDDSTypes.idl 
using RTI Code Generator (rtiddsgen) version 4.6.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 

#ifndef dds_c_log_infrastructure_h
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#include "osapi/osapi_atomic.h"
#else
#include "ndds_standalone_type.h"
#endif

#include "UnrealBasicDDSTypes.h"

#ifndef NDDS_STANDALONE_TYPE
#include "UnrealBasicDDSTypesPlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *PositionTYPENAME = "Position";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * Position_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member Position_g_tc_members[3]=
    {

        {
            (char *)"x",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"y",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"z",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Position_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Position", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            Position_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Position*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &Position_g_tc;
    }

    Position_g_tc._data._annotations._allowedDataRepresentationMask = 5;
    Position_g_tc._data._annotations._isNested = RTI_XCDR_TRUE;

    Position_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    Position_g_tc_members[1]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    Position_g_tc_members[2]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;

    /* Initialize the values for member annotations. */
    Position_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[0]._annotations._defaultValue._u.double_value = 0.0;
    Position_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[0]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Position_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[0]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
    Position_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[1]._annotations._defaultValue._u.double_value = 0.0;
    Position_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[1]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Position_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[1]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
    Position_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[2]._annotations._defaultValue._u.double_value = 0.0;
    Position_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[2]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Position_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Position_g_tc_members[2]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

    Position_g_tc._data._sampleAccessInfo =
    Position_get_sample_access_info();
    Position_g_tc._data._typePlugin =
    Position_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &Position_g_tc;
}

#define TSeq PositionSeq
#define T Position
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Position_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Position_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(PositionSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        PositionSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Position_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Position_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    Position *sample;

    static RTIXCdrMemberAccessInfo Position_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Position_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &Position_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Position);
    if (sample == NULL) {
        return NULL;
    }

    Position_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->x - (char *)sample);

    Position_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->y - (char *)sample);

    Position_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->z - (char *)sample);

    Position_g_sampleAccessInfo.memberAccessInfos = 
    Position_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Position);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            Position_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            Position_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Position_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Position_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Position_get_member_value_pointer;

    Position_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &Position_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *Position_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Position_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Position_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Position_finalize_w_return,
        NULL,
        NULL
    };

    return &Position_g_typePlugin;
}
#endif

RTIBool Position_initialize(
    Position* sample)
{
    return Position_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool Position_initialize_w_params(
    Position *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->x = 0.0;

    sample->y = 0.0;

    sample->z = 0.0;

    return RTI_TRUE;
}
RTIBool Position_initialize_ex(
    Position *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Position_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool Position_finalize_w_return(
    Position* sample)
{
    Position_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void Position_finalize(
    Position* sample)
{  
    Position_finalize_ex(
        sample, 
        RTI_TRUE);
}

void Position_finalize_ex(
    Position *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Position_finalize_w_params(
        sample,
        &deallocParams);
}

void Position_finalize_w_params(
    Position *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void Position_finalize_optional_members(
    Position* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Position_copy(
    Position* dst,
    const Position* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyDouble (
            &dst->x, 
            &src->x)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyDouble (
            &dst->y, 
            &src->y)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyDouble (
            &dst->z, 
            &src->z)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Position' sequence class.
*/
#define T Position
#define TSeq PositionSeq

#define T_initialize_w_params Position_initialize_w_params

#define T_finalize_w_params   Position_finalize_w_params
#define T_copy       Position_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *VelocityTYPENAME = "Velocity";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * Velocity_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member Velocity_g_tc_members[3]=
    {

        {
            (char *)"x",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"y",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"z",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Velocity_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Velocity", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            Velocity_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Velocity*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &Velocity_g_tc;
    }

    Velocity_g_tc._data._annotations._allowedDataRepresentationMask = 5;
    Velocity_g_tc._data._annotations._isNested = RTI_XCDR_TRUE;

    Velocity_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    Velocity_g_tc_members[1]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    Velocity_g_tc_members[2]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;

    /* Initialize the values for member annotations. */
    Velocity_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[0]._annotations._defaultValue._u.double_value = 0.0;
    Velocity_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[0]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Velocity_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[0]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
    Velocity_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[1]._annotations._defaultValue._u.double_value = 0.0;
    Velocity_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[1]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Velocity_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[1]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
    Velocity_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[2]._annotations._defaultValue._u.double_value = 0.0;
    Velocity_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[2]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Velocity_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Velocity_g_tc_members[2]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

    Velocity_g_tc._data._sampleAccessInfo =
    Velocity_get_sample_access_info();
    Velocity_g_tc._data._typePlugin =
    Velocity_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &Velocity_g_tc;
}

#define TSeq VelocitySeq
#define T Velocity
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Velocity_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Velocity_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(VelocitySeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        VelocitySeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Velocity_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Velocity_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    Velocity *sample;

    static RTIXCdrMemberAccessInfo Velocity_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Velocity_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &Velocity_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Velocity);
    if (sample == NULL) {
        return NULL;
    }

    Velocity_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->x - (char *)sample);

    Velocity_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->y - (char *)sample);

    Velocity_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->z - (char *)sample);

    Velocity_g_sampleAccessInfo.memberAccessInfos = 
    Velocity_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Velocity);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            Velocity_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            Velocity_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Velocity_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Velocity_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Velocity_get_member_value_pointer;

    Velocity_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &Velocity_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *Velocity_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Velocity_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Velocity_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Velocity_finalize_w_return,
        NULL,
        NULL
    };

    return &Velocity_g_typePlugin;
}
#endif

RTIBool Velocity_initialize(
    Velocity* sample)
{
    return Velocity_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool Velocity_initialize_w_params(
    Velocity *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->x = 0.0;

    sample->y = 0.0;

    sample->z = 0.0;

    return RTI_TRUE;
}
RTIBool Velocity_initialize_ex(
    Velocity *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Velocity_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool Velocity_finalize_w_return(
    Velocity* sample)
{
    Velocity_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void Velocity_finalize(
    Velocity* sample)
{  
    Velocity_finalize_ex(
        sample, 
        RTI_TRUE);
}

void Velocity_finalize_ex(
    Velocity *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Velocity_finalize_w_params(
        sample,
        &deallocParams);
}

void Velocity_finalize_w_params(
    Velocity *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void Velocity_finalize_optional_members(
    Velocity* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Velocity_copy(
    Velocity* dst,
    const Velocity* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyDouble (
            &dst->x, 
            &src->x)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyDouble (
            &dst->y, 
            &src->y)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyDouble (
            &dst->z, 
            &src->z)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Velocity' sequence class.
*/
#define T Velocity
#define TSeq VelocitySeq

#define T_initialize_w_params Velocity_initialize_w_params

#define T_finalize_w_params   Velocity_finalize_w_params
#define T_copy       Velocity_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *AttitudeTYPENAME = "Attitude";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * Attitude_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member Attitude_g_tc_members[3]=
    {

        {
            (char *)"roll",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"pitch",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"yaw",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Attitude_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Attitude", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            Attitude_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Attitude*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &Attitude_g_tc;
    }

    Attitude_g_tc._data._annotations._allowedDataRepresentationMask = 5;
    Attitude_g_tc._data._annotations._isNested = RTI_XCDR_TRUE;

    Attitude_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    Attitude_g_tc_members[1]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;
    Attitude_g_tc_members[2]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_double_w_new;

    /* Initialize the values for member annotations. */
    Attitude_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[0]._annotations._defaultValue._u.double_value = 0.0;
    Attitude_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[0]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Attitude_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[0]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
    Attitude_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[1]._annotations._defaultValue._u.double_value = 0.0;
    Attitude_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[1]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Attitude_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[1]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
    Attitude_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[2]._annotations._defaultValue._u.double_value = 0.0;
    Attitude_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[2]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Attitude_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Attitude_g_tc_members[2]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

    Attitude_g_tc._data._sampleAccessInfo =
    Attitude_get_sample_access_info();
    Attitude_g_tc._data._typePlugin =
    Attitude_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &Attitude_g_tc;
}

#define TSeq AttitudeSeq
#define T Attitude
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Attitude_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Attitude_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(AttitudeSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        AttitudeSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Attitude_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Attitude_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    Attitude *sample;

    static RTIXCdrMemberAccessInfo Attitude_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Attitude_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &Attitude_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Attitude);
    if (sample == NULL) {
        return NULL;
    }

    Attitude_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->roll - (char *)sample);

    Attitude_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->pitch - (char *)sample);

    Attitude_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->yaw - (char *)sample);

    Attitude_g_sampleAccessInfo.memberAccessInfos = 
    Attitude_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Attitude);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            Attitude_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            Attitude_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Attitude_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Attitude_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Attitude_get_member_value_pointer;

    Attitude_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &Attitude_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *Attitude_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Attitude_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Attitude_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Attitude_finalize_w_return,
        NULL,
        NULL
    };

    return &Attitude_g_typePlugin;
}
#endif

RTIBool Attitude_initialize(
    Attitude* sample)
{
    return Attitude_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool Attitude_initialize_w_params(
    Attitude *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->roll = 0.0;

    sample->pitch = 0.0;

    sample->yaw = 0.0;

    return RTI_TRUE;
}
RTIBool Attitude_initialize_ex(
    Attitude *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Attitude_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool Attitude_finalize_w_return(
    Attitude* sample)
{
    Attitude_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void Attitude_finalize(
    Attitude* sample)
{  
    Attitude_finalize_ex(
        sample, 
        RTI_TRUE);
}

void Attitude_finalize_ex(
    Attitude *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Attitude_finalize_w_params(
        sample,
        &deallocParams);
}

void Attitude_finalize_w_params(
    Attitude *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void Attitude_finalize_optional_members(
    Attitude* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Attitude_copy(
    Attitude* dst,
    const Attitude* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyDouble (
            &dst->roll, 
            &src->roll)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyDouble (
            &dst->pitch, 
            &src->pitch)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyDouble (
            &dst->yaw, 
            &src->yaw)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Attitude' sequence class.
*/
#define T Attitude
#define TSeq AttitudeSeq

#define T_initialize_w_params Attitude_initialize_w_params

#define T_finalize_w_params   Attitude_finalize_w_params
#define T_copy       Attitude_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *AActorTypeTYPENAME = "AActorType";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * AActorType_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member AActorType_g_tc_members[3]=
    {

        {
            (char *)"pos",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"vel",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"rot",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode AActorType_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"AActorType", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            AActorType_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for AActorType*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &AActorType_g_tc;
    }

    AActorType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    AActorType_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)Position_get_typecode();
    AActorType_g_tc_members[1]._representation._typeCode =  (RTICdrTypeCode *)Velocity_get_typecode();
    AActorType_g_tc_members[2]._representation._typeCode =  (RTICdrTypeCode *)Attitude_get_typecode();

    /* Initialize the values for member annotations. */

    AActorType_g_tc._data._sampleAccessInfo =
    AActorType_get_sample_access_info();
    AActorType_g_tc._data._typePlugin =
    AActorType_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &AActorType_g_tc;
}

#define TSeq AActorTypeSeq
#define T AActorType
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *AActorType_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo AActorType_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(AActorTypeSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        AActorTypeSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &AActorType_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *AActorType_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    AActorType *sample;

    static RTIXCdrMemberAccessInfo AActorType_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo AActorType_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &AActorType_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        AActorType);
    if (sample == NULL) {
        return NULL;
    }

    AActorType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->pos - (char *)sample);

    AActorType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->vel - (char *)sample);

    AActorType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->rot - (char *)sample);

    AActorType_g_sampleAccessInfo.memberAccessInfos = 
    AActorType_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(AActorType);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            AActorType_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            AActorType_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    AActorType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    AActorType_g_sampleAccessInfo.getMemberValuePointerFcn = 
    AActorType_get_member_value_pointer;

    AActorType_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &AActorType_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *AActorType_get_type_plugin_info()
{
    static RTIXCdrTypePlugin AActorType_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        AActorType_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        AActorType_finalize_w_return,
        NULL,
        NULL
    };

    return &AActorType_g_typePlugin;
}
#endif

RTIBool AActorType_initialize(
    AActorType* sample)
{
    return AActorType_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool AActorType_initialize_w_params(
    AActorType *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!Position_initialize_w_params(
        &sample->pos,
        allocParams)) {
        return RTI_FALSE;
    }
    if (!Velocity_initialize_w_params(
        &sample->vel,
        allocParams)) {
        return RTI_FALSE;
    }
    if (!Attitude_initialize_w_params(
        &sample->rot,
        allocParams)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}
RTIBool AActorType_initialize_ex(
    AActorType *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return AActorType_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool AActorType_finalize_w_return(
    AActorType* sample)
{
    AActorType_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void AActorType_finalize(
    AActorType* sample)
{  
    AActorType_finalize_ex(
        sample, 
        RTI_TRUE);
}

void AActorType_finalize_ex(
    AActorType *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    AActorType_finalize_w_params(
        sample,
        &deallocParams);
}

void AActorType_finalize_w_params(
    AActorType *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    Position_finalize_w_params(
        &sample->pos,
        deallocParams);

    Velocity_finalize_w_params(
        &sample->vel,
        deallocParams);

    Attitude_finalize_w_params(
        &sample->rot,
        deallocParams);

}

void AActorType_finalize_optional_members(
    AActorType* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool AActorType_copy(
    AActorType* dst,
    const AActorType* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!Position_copy(
            &dst->pos,
            (const Position*)&src->pos)) {
            return RTI_FALSE;
        } 
        if (!Velocity_copy(
            &dst->vel,
            (const Velocity*)&src->vel)) {
            return RTI_FALSE;
        } 
        if (!Attitude_copy(
            &dst->rot,
            (const Attitude*)&src->rot)) {
            return RTI_FALSE;
        } 

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'AActorType' sequence class.
*/
#define T AActorType
#define TSeq AActorTypeSeq

#define T_initialize_w_params AActorType_initialize_w_params

#define T_finalize_w_params   AActorType_finalize_w_params
#define T_copy       AActorType_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *InputCommandTypeTYPENAME = "InputCommandType";

#ifndef NDDS_STANDALONE_TYPE

DDS_TypeCode * InputCommandType_get_typecode(void)
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    static DDS_TypeCode_Member InputCommandType_g_tc_members[3]=
    {

        {
            (char *)"throttle",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"steering",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"brake",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode InputCommandType_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"InputCommandType", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            InputCommandType_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for InputCommandType*/

    if (RTIOsapiAtomic_load32(&is_initialized, RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return &InputCommandType_g_tc;
    }

    InputCommandType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    InputCommandType_g_tc_members[0]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    InputCommandType_g_tc_members[1]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    InputCommandType_g_tc_members[2]._representation._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */
    InputCommandType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
    InputCommandType_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    InputCommandType_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;
    InputCommandType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    InputCommandType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    InputCommandType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;
    InputCommandType_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    InputCommandType_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    InputCommandType_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    InputCommandType_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    InputCommandType_g_tc._data._sampleAccessInfo =
    InputCommandType_get_sample_access_info();
    InputCommandType_g_tc._data._typePlugin =
    InputCommandType_get_type_plugin_info();    

    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);

    return &InputCommandType_g_tc;
}

#define TSeq InputCommandTypeSeq
#define T InputCommandType
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *InputCommandType_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo InputCommandType_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(InputCommandTypeSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        InputCommandTypeSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &InputCommandType_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *InputCommandType_get_sample_access_info()
{
    static RTI_ATOMIC(RTIBool) is_initialized;

    InputCommandType *sample;

    static RTIXCdrMemberAccessInfo InputCommandType_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo InputCommandType_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (RTIOsapiAtomic_load32(
        &is_initialized,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_ACQUIRE)) {
        return (RTIXCdrSampleAccessInfo*) &InputCommandType_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        InputCommandType);
    if (sample == NULL) {
        return NULL;
    }

    InputCommandType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->throttle - (char *)sample);

    InputCommandType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->steering - (char *)sample);

    InputCommandType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->brake - (char *)sample);

    InputCommandType_g_sampleAccessInfo.memberAccessInfos = 
    InputCommandType_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(InputCommandType);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            InputCommandType_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            InputCommandType_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    InputCommandType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    InputCommandType_g_sampleAccessInfo.getMemberValuePointerFcn = 
    InputCommandType_get_member_value_pointer;

    InputCommandType_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    RTIOsapiAtomic_store32(
        &is_initialized,
        RTI_TRUE,
        RTI_OSAPI_ATOMIC_MEMORY_ORDER_RELEASE);
    return (RTIXCdrSampleAccessInfo*) &InputCommandType_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *InputCommandType_get_type_plugin_info()
{
    static RTIXCdrTypePlugin InputCommandType_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        InputCommandType_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        InputCommandType_finalize_w_return,
        NULL,
        NULL
    };

    return &InputCommandType_g_typePlugin;
}
#endif

RTIBool InputCommandType_initialize(
    InputCommandType* sample)
{
    return InputCommandType_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool InputCommandType_initialize_w_params(
    InputCommandType *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->throttle = 0.0f;

    sample->steering = 0.0f;

    sample->brake = 0.0f;

    return RTI_TRUE;
}
RTIBool InputCommandType_initialize_ex(
    InputCommandType *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return InputCommandType_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool InputCommandType_finalize_w_return(
    InputCommandType* sample)
{
    InputCommandType_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void InputCommandType_finalize(
    InputCommandType* sample)
{  
    InputCommandType_finalize_ex(
        sample, 
        RTI_TRUE);
}

void InputCommandType_finalize_ex(
    InputCommandType *sample,
    RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    InputCommandType_finalize_w_params(
        sample,
        &deallocParams);
}

void InputCommandType_finalize_w_params(
    InputCommandType *sample,
    const struct DDS_TypeDeallocationParams_t *deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void InputCommandType_finalize_optional_members(
    InputCommandType* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool InputCommandType_copy(
    InputCommandType* dst,
    const InputCommandType* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyFloat (
            &dst->throttle, 
            &src->throttle)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->steering, 
            &src->steering)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->brake, 
            &src->brake)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'InputCommandType' sequence class.
*/
#define T InputCommandType
#define TSeq InputCommandTypeSeq

#define T_initialize_w_params InputCommandType_initialize_w_params

#define T_finalize_w_params   InputCommandType_finalize_w_params
#define T_copy       InputCommandType_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code< Position>::get() 
        {
            return (const RTIXCdrTypeCode *) Position_get_typecode();
        }

        const RTIXCdrTypeCode * type_code< Velocity>::get() 
        {
            return (const RTIXCdrTypeCode *) Velocity_get_typecode();
        }

        const RTIXCdrTypeCode * type_code< Attitude>::get() 
        {
            return (const RTIXCdrTypeCode *) Attitude_get_typecode();
        }

        const RTIXCdrTypeCode * type_code< AActorType>::get() 
        {
            return (const RTIXCdrTypeCode *) AActorType_get_typecode();
        }

        const RTIXCdrTypeCode * type_code< InputCommandType>::get() 
        {
            return (const RTIXCdrTypeCode *) InputCommandType_get_typecode();
        }

    } 
}
#endif
