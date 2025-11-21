

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from UnrealBasicDDSTypes.idl
using RTI Code Generator (rtiddsgen) version 4.6.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef UnrealBasicDDSTypesPlugin_795071791_h
#define UnrealBasicDDSTypesPlugin_795071791_h

#include "UnrealBasicDDSTypes.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if defined(NDDS_USER_DLL_EXPORT) && defined(RTI_WIN32)
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#if !defined(RTI_WIN32) && defined(NDDS_USER_SYMBOL_EXPORT)
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __attribute__((visibility("default")))
#endif

extern "C"{

    #define PositionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define PositionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define PositionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define PositionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define PositionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Position*
    PositionPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Position*
    PositionPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Position*
    PositionPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    PositionPluginSupport_copy_data(
        Position *out,
        const Position *in);

    NDDSUSERDllExport extern void 
    PositionPluginSupport_destroy_data_w_params(
        Position *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    PositionPluginSupport_destroy_data_ex(
        Position *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    PositionPluginSupport_destroy_data(
        Position *sample);

    NDDSUSERDllExport extern void 
    PositionPluginSupport_print_data(
        const Position *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    PositionPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Position *out,
        const Position *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    PositionPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Position *sample); 

    NDDSUSERDllExport extern RTIBool
    PositionPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Position *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    PositionPlugin_deserialize_from_cdr_buffer(
        Position *sample,
        const char * buffer,
        unsigned int length);    
    #if !defined (NDDS_STANDALONE_TYPE)
    NDDSUSERDllExport extern DDS_ReturnCode_t
    PositionPlugin_data_to_string(
        const Position *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    PositionPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    PositionPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    PositionPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    PositionPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    PositionPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Position ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *cdrStream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * PositionPlugin_get_programs(void);

    #define VelocityPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define VelocityPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define VelocityPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define VelocityPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define VelocityPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Velocity*
    VelocityPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Velocity*
    VelocityPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Velocity*
    VelocityPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    VelocityPluginSupport_copy_data(
        Velocity *out,
        const Velocity *in);

    NDDSUSERDllExport extern void 
    VelocityPluginSupport_destroy_data_w_params(
        Velocity *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    VelocityPluginSupport_destroy_data_ex(
        Velocity *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    VelocityPluginSupport_destroy_data(
        Velocity *sample);

    NDDSUSERDllExport extern void 
    VelocityPluginSupport_print_data(
        const Velocity *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    VelocityPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Velocity *out,
        const Velocity *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    VelocityPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Velocity *sample); 

    NDDSUSERDllExport extern RTIBool
    VelocityPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Velocity *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    VelocityPlugin_deserialize_from_cdr_buffer(
        Velocity *sample,
        const char * buffer,
        unsigned int length);    
    #if !defined (NDDS_STANDALONE_TYPE)
    NDDSUSERDllExport extern DDS_ReturnCode_t
    VelocityPlugin_data_to_string(
        const Velocity *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    VelocityPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    VelocityPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    VelocityPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    VelocityPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    VelocityPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Velocity ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *cdrStream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * VelocityPlugin_get_programs(void);

    #define AttitudePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define AttitudePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define AttitudePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define AttitudePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define AttitudePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Attitude*
    AttitudePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Attitude*
    AttitudePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Attitude*
    AttitudePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    AttitudePluginSupport_copy_data(
        Attitude *out,
        const Attitude *in);

    NDDSUSERDllExport extern void 
    AttitudePluginSupport_destroy_data_w_params(
        Attitude *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    AttitudePluginSupport_destroy_data_ex(
        Attitude *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    AttitudePluginSupport_destroy_data(
        Attitude *sample);

    NDDSUSERDllExport extern void 
    AttitudePluginSupport_print_data(
        const Attitude *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    AttitudePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Attitude *out,
        const Attitude *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    AttitudePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Attitude *sample); 

    NDDSUSERDllExport extern RTIBool
    AttitudePlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Attitude *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    AttitudePlugin_deserialize_from_cdr_buffer(
        Attitude *sample,
        const char * buffer,
        unsigned int length);    
    #if !defined (NDDS_STANDALONE_TYPE)
    NDDSUSERDllExport extern DDS_ReturnCode_t
    AttitudePlugin_data_to_string(
        const Attitude *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    AttitudePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    AttitudePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    AttitudePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    AttitudePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    AttitudePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Attitude ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *cdrStream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * AttitudePlugin_get_programs(void);

    #define AActorTypePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define AActorTypePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define AActorTypePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define AActorTypePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define AActorTypePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern AActorType*
    AActorTypePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern AActorType*
    AActorTypePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern AActorType*
    AActorTypePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    AActorTypePluginSupport_copy_data(
        AActorType *out,
        const AActorType *in);

    NDDSUSERDllExport extern void 
    AActorTypePluginSupport_destroy_data_w_params(
        AActorType *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    AActorTypePluginSupport_destroy_data_ex(
        AActorType *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    AActorTypePluginSupport_destroy_data(
        AActorType *sample);

    NDDSUSERDllExport extern void 
    AActorTypePluginSupport_print_data(
        const AActorType *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    AActorTypePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    AActorTypePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    AActorTypePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    AActorTypePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    AActorTypePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        AActorType *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    AActorTypePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        AActorType *out,
        const AActorType *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    AActorTypePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const AActorType *sample); 

    NDDSUSERDllExport extern RTIBool
    AActorTypePlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const AActorType *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    AActorTypePlugin_deserialize_from_cdr_buffer(
        AActorType *sample,
        const char * buffer,
        unsigned int length);    
    #if !defined (NDDS_STANDALONE_TYPE)
    NDDSUSERDllExport extern DDS_ReturnCode_t
    AActorTypePlugin_data_to_string(
        const AActorType *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    AActorTypePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    AActorTypePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    AActorTypePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    AActorTypePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    AActorTypePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        AActorType ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *cdrStream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * AActorTypePlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    AActorTypePlugin_new(void);

    NDDSUSERDllExport extern void
    AActorTypePlugin_delete(struct PRESTypePlugin *);

    #define InputCommandTypePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define InputCommandTypePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define InputCommandTypePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define InputCommandTypePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define InputCommandTypePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern InputCommandType*
    InputCommandTypePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern InputCommandType*
    InputCommandTypePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern InputCommandType*
    InputCommandTypePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    InputCommandTypePluginSupport_copy_data(
        InputCommandType *out,
        const InputCommandType *in);

    NDDSUSERDllExport extern void 
    InputCommandTypePluginSupport_destroy_data_w_params(
        InputCommandType *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    InputCommandTypePluginSupport_destroy_data_ex(
        InputCommandType *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    InputCommandTypePluginSupport_destroy_data(
        InputCommandType *sample);

    NDDSUSERDllExport extern void 
    InputCommandTypePluginSupport_print_data(
        const InputCommandType *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    InputCommandTypePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    InputCommandTypePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    InputCommandTypePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    InputCommandTypePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    InputCommandTypePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        InputCommandType *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    InputCommandTypePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        InputCommandType *out,
        const InputCommandType *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    InputCommandTypePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const InputCommandType *sample); 

    NDDSUSERDllExport extern RTIBool
    InputCommandTypePlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const InputCommandType *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    InputCommandTypePlugin_deserialize_from_cdr_buffer(
        InputCommandType *sample,
        const char * buffer,
        unsigned int length);    
    #if !defined (NDDS_STANDALONE_TYPE)
    NDDSUSERDllExport extern DDS_ReturnCode_t
    InputCommandTypePlugin_data_to_string(
        const InputCommandType *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    InputCommandTypePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    InputCommandTypePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    InputCommandTypePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    InputCommandTypePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    InputCommandTypePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        InputCommandType ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *cdrStream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * InputCommandTypePlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    InputCommandTypePlugin_new(void);

    NDDSUSERDllExport extern void
    InputCommandTypePlugin_delete(struct PRESTypePlugin *);

}

#if defined(NDDS_USER_DLL_EXPORT) || defined(NDDS_USER_SYMBOL_EXPORT)
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* UnrealBasicDDSTypesPlugin_795071791_h */
