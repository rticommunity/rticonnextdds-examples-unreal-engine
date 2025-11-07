

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from UnrealBasicDDSTypes.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.7.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef UnrealBasicDDSTypes_795071160_h
#define UnrealBasicDDSTypes_795071160_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *PositionTYPENAME;

}

struct PositionSeq;
class Position 
{
  public:
    typedef struct PositionSeq Seq;

    DDS_Double x;
    DDS_Double y;
    DDS_Double z;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * Position_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Position_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Position_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Position_get_sample_seq_access_info(void);
#endif
DDS_SEQUENCE(PositionSeq, Position);

NDDSUSERDllExport
RTIBool Position_initialize(
    Position* self);

NDDSUSERDllExport
RTIBool Position_initialize_ex(
    Position* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Position_initialize_w_params(
    Position* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Position_finalize_w_return(
    Position* self);

NDDSUSERDllExport
void Position_finalize(
    Position* self);

NDDSUSERDllExport
void Position_finalize_ex(
    Position* self,RTIBool deletePointers);

NDDSUSERDllExport
void Position_finalize_w_params(
    Position* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Position_finalize_optional_members(
    Position* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Position_copy(
    Position* dst,
    const Position* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *VelocityTYPENAME;

}

struct VelocitySeq;
class Velocity 
{
  public:
    typedef struct VelocitySeq Seq;

    DDS_Double x;
    DDS_Double y;
    DDS_Double z;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * Velocity_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Velocity_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Velocity_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Velocity_get_sample_seq_access_info(void);
#endif
DDS_SEQUENCE(VelocitySeq, Velocity);

NDDSUSERDllExport
RTIBool Velocity_initialize(
    Velocity* self);

NDDSUSERDllExport
RTIBool Velocity_initialize_ex(
    Velocity* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Velocity_initialize_w_params(
    Velocity* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Velocity_finalize_w_return(
    Velocity* self);

NDDSUSERDllExport
void Velocity_finalize(
    Velocity* self);

NDDSUSERDllExport
void Velocity_finalize_ex(
    Velocity* self,RTIBool deletePointers);

NDDSUSERDllExport
void Velocity_finalize_w_params(
    Velocity* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Velocity_finalize_optional_members(
    Velocity* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Velocity_copy(
    Velocity* dst,
    const Velocity* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *AttitudeTYPENAME;

}

struct AttitudeSeq;
class Attitude 
{
  public:
    typedef struct AttitudeSeq Seq;

    DDS_Double roll;
    DDS_Double pitch;
    DDS_Double yaw;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * Attitude_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Attitude_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Attitude_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Attitude_get_sample_seq_access_info(void);
#endif
DDS_SEQUENCE(AttitudeSeq, Attitude);

NDDSUSERDllExport
RTIBool Attitude_initialize(
    Attitude* self);

NDDSUSERDllExport
RTIBool Attitude_initialize_ex(
    Attitude* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Attitude_initialize_w_params(
    Attitude* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Attitude_finalize_w_return(
    Attitude* self);

NDDSUSERDllExport
void Attitude_finalize(
    Attitude* self);

NDDSUSERDllExport
void Attitude_finalize_ex(
    Attitude* self,RTIBool deletePointers);

NDDSUSERDllExport
void Attitude_finalize_w_params(
    Attitude* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Attitude_finalize_optional_members(
    Attitude* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Attitude_copy(
    Attitude* dst,
    const Attitude* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *AActorTypeTYPENAME;

}

struct AActorTypeSeq;
#ifndef NDDS_STANDALONE_TYPE
class AActorTypeTypeSupport;
class AActorTypeDataWriter;
class AActorTypeDataReader;
#endif
class AActorType 
{
  public:
    typedef struct AActorTypeSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef AActorTypeTypeSupport TypeSupport;
    typedef AActorTypeDataWriter DataWriter;
    typedef AActorTypeDataReader DataReader;
    #endif

    Position pos;
    Velocity vel;
    Attitude rot;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * AActorType_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *AActorType_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *AActorType_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *AActorType_get_sample_seq_access_info(void);
#endif
DDS_SEQUENCE(AActorTypeSeq, AActorType);

NDDSUSERDllExport
RTIBool AActorType_initialize(
    AActorType* self);

NDDSUSERDllExport
RTIBool AActorType_initialize_ex(
    AActorType* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool AActorType_initialize_w_params(
    AActorType* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool AActorType_finalize_w_return(
    AActorType* self);

NDDSUSERDllExport
void AActorType_finalize(
    AActorType* self);

NDDSUSERDllExport
void AActorType_finalize_ex(
    AActorType* self,RTIBool deletePointers);

NDDSUSERDllExport
void AActorType_finalize_w_params(
    AActorType* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void AActorType_finalize_optional_members(
    AActorType* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool AActorType_copy(
    AActorType* dst,
    const AActorType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *InputCommandTypeTYPENAME;

}

struct InputCommandTypeSeq;
#ifndef NDDS_STANDALONE_TYPE
class InputCommandTypeTypeSupport;
class InputCommandTypeDataWriter;
class InputCommandTypeDataReader;
#endif
class InputCommandType 
{
  public:
    typedef struct InputCommandTypeSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef InputCommandTypeTypeSupport TypeSupport;
    typedef InputCommandTypeDataWriter DataWriter;
    typedef InputCommandTypeDataReader DataReader;
    #endif

    DDS_Float throttle;
    DDS_Float steering;
    DDS_Float brake;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * InputCommandType_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *InputCommandType_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *InputCommandType_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *InputCommandType_get_sample_seq_access_info(void);
#endif
DDS_SEQUENCE(InputCommandTypeSeq, InputCommandType);

NDDSUSERDllExport
RTIBool InputCommandType_initialize(
    InputCommandType* self);

NDDSUSERDllExport
RTIBool InputCommandType_initialize_ex(
    InputCommandType* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool InputCommandType_initialize_w_params(
    InputCommandType* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool InputCommandType_finalize_w_return(
    InputCommandType* self);

NDDSUSERDllExport
void InputCommandType_finalize(
    InputCommandType* self);

NDDSUSERDllExport
void InputCommandType_finalize_ex(
    InputCommandType* self,RTIBool deletePointers);

NDDSUSERDllExport
void InputCommandType_finalize_w_params(
    InputCommandType* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void InputCommandType_finalize_optional_members(
    InputCommandType* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool InputCommandType_copy(
    InputCommandType* dst,
    const InputCommandType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code< Position> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code< Velocity> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code< Attitude> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code< AActorType> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code< InputCommandType> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* UnrealBasicDDSTypes */

