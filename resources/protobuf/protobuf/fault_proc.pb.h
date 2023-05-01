// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fault_proc.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_fault_5fproc_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_fault_5fproc_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_fault_5fproc_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_fault_5fproc_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_fault_5fproc_2eproto;
namespace IBUS {
class FaultProcInfo;
class FaultProcInfoDefaultTypeInternal;
extern FaultProcInfoDefaultTypeInternal _FaultProcInfo_default_instance_;
class FaultProcMsg;
class FaultProcMsgDefaultTypeInternal;
extern FaultProcMsgDefaultTypeInternal _FaultProcMsg_default_instance_;
}  // namespace IBUS
PROTOBUF_NAMESPACE_OPEN
template<> ::IBUS::FaultProcInfo* Arena::CreateMaybeMessage<::IBUS::FaultProcInfo>(Arena*);
template<> ::IBUS::FaultProcMsg* Arena::CreateMaybeMessage<::IBUS::FaultProcMsg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace IBUS {

// ===================================================================

class FaultProcInfo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:IBUS.FaultProcInfo) */ {
 public:
  FaultProcInfo();
  virtual ~FaultProcInfo();

  FaultProcInfo(const FaultProcInfo& from);
  FaultProcInfo(FaultProcInfo&& from) noexcept
    : FaultProcInfo() {
    *this = ::std::move(from);
  }

  inline FaultProcInfo& operator=(const FaultProcInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline FaultProcInfo& operator=(FaultProcInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FaultProcInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FaultProcInfo* internal_default_instance() {
    return reinterpret_cast<const FaultProcInfo*>(
               &_FaultProcInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FaultProcInfo& a, FaultProcInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(FaultProcInfo* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FaultProcInfo* New() const final {
    return CreateMaybeMessage<FaultProcInfo>(nullptr);
  }

  FaultProcInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FaultProcInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FaultProcInfo& from);
  void MergeFrom(const FaultProcInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FaultProcInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "IBUS.FaultProcInfo";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_fault_5fproc_2eproto);
    return ::descriptor_table_fault_5fproc_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFaultNameFieldNumber = 1,
    kFaultLevelFieldNumber = 2,
  };
  // string fault_name = 1;
  void clear_fault_name();
  const std::string& fault_name() const;
  void set_fault_name(const std::string& value);
  void set_fault_name(std::string&& value);
  void set_fault_name(const char* value);
  void set_fault_name(const char* value, size_t size);
  std::string* mutable_fault_name();
  std::string* release_fault_name();
  void set_allocated_fault_name(std::string* fault_name);

  // int32 fault_level = 2;
  void clear_fault_level();
  ::PROTOBUF_NAMESPACE_ID::int32 fault_level() const;
  void set_fault_level(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:IBUS.FaultProcInfo)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr fault_name_;
  ::PROTOBUF_NAMESPACE_ID::int32 fault_level_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_fault_5fproc_2eproto;
};
// -------------------------------------------------------------------

class FaultProcMsg :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:IBUS.FaultProcMsg) */ {
 public:
  FaultProcMsg();
  virtual ~FaultProcMsg();

  FaultProcMsg(const FaultProcMsg& from);
  FaultProcMsg(FaultProcMsg&& from) noexcept
    : FaultProcMsg() {
    *this = ::std::move(from);
  }

  inline FaultProcMsg& operator=(const FaultProcMsg& from) {
    CopyFrom(from);
    return *this;
  }
  inline FaultProcMsg& operator=(FaultProcMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FaultProcMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FaultProcMsg* internal_default_instance() {
    return reinterpret_cast<const FaultProcMsg*>(
               &_FaultProcMsg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(FaultProcMsg& a, FaultProcMsg& b) {
    a.Swap(&b);
  }
  inline void Swap(FaultProcMsg* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FaultProcMsg* New() const final {
    return CreateMaybeMessage<FaultProcMsg>(nullptr);
  }

  FaultProcMsg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FaultProcMsg>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FaultProcMsg& from);
  void MergeFrom(const FaultProcMsg& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FaultProcMsg* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "IBUS.FaultProcMsg";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_fault_5fproc_2eproto);
    return ::descriptor_table_fault_5fproc_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFaultListFieldNumber = 3,
    kMaxLevelFaultFieldNumber = 2,
    kHasFaultFieldNumber = 1,
  };
  // repeated .IBUS.FaultProcInfo fault_list = 3;
  int fault_list_size() const;
  void clear_fault_list();
  ::IBUS::FaultProcInfo* mutable_fault_list(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::IBUS::FaultProcInfo >*
      mutable_fault_list();
  const ::IBUS::FaultProcInfo& fault_list(int index) const;
  ::IBUS::FaultProcInfo* add_fault_list();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::IBUS::FaultProcInfo >&
      fault_list() const;

  // .IBUS.FaultProcInfo max_level_fault = 2;
  bool has_max_level_fault() const;
  void clear_max_level_fault();
  const ::IBUS::FaultProcInfo& max_level_fault() const;
  ::IBUS::FaultProcInfo* release_max_level_fault();
  ::IBUS::FaultProcInfo* mutable_max_level_fault();
  void set_allocated_max_level_fault(::IBUS::FaultProcInfo* max_level_fault);

  // bool has_fault = 1;
  void clear_has_fault();
  bool has_fault() const;
  void set_has_fault(bool value);

  // @@protoc_insertion_point(class_scope:IBUS.FaultProcMsg)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::IBUS::FaultProcInfo > fault_list_;
  ::IBUS::FaultProcInfo* max_level_fault_;
  bool has_fault_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_fault_5fproc_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FaultProcInfo

// string fault_name = 1;
inline void FaultProcInfo::clear_fault_name() {
  fault_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& FaultProcInfo::fault_name() const {
  // @@protoc_insertion_point(field_get:IBUS.FaultProcInfo.fault_name)
  return fault_name_.GetNoArena();
}
inline void FaultProcInfo::set_fault_name(const std::string& value) {
  
  fault_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:IBUS.FaultProcInfo.fault_name)
}
inline void FaultProcInfo::set_fault_name(std::string&& value) {
  
  fault_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:IBUS.FaultProcInfo.fault_name)
}
inline void FaultProcInfo::set_fault_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  fault_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:IBUS.FaultProcInfo.fault_name)
}
inline void FaultProcInfo::set_fault_name(const char* value, size_t size) {
  
  fault_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:IBUS.FaultProcInfo.fault_name)
}
inline std::string* FaultProcInfo::mutable_fault_name() {
  
  // @@protoc_insertion_point(field_mutable:IBUS.FaultProcInfo.fault_name)
  return fault_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* FaultProcInfo::release_fault_name() {
  // @@protoc_insertion_point(field_release:IBUS.FaultProcInfo.fault_name)
  
  return fault_name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void FaultProcInfo::set_allocated_fault_name(std::string* fault_name) {
  if (fault_name != nullptr) {
    
  } else {
    
  }
  fault_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), fault_name);
  // @@protoc_insertion_point(field_set_allocated:IBUS.FaultProcInfo.fault_name)
}

// int32 fault_level = 2;
inline void FaultProcInfo::clear_fault_level() {
  fault_level_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FaultProcInfo::fault_level() const {
  // @@protoc_insertion_point(field_get:IBUS.FaultProcInfo.fault_level)
  return fault_level_;
}
inline void FaultProcInfo::set_fault_level(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  fault_level_ = value;
  // @@protoc_insertion_point(field_set:IBUS.FaultProcInfo.fault_level)
}

// -------------------------------------------------------------------

// FaultProcMsg

// bool has_fault = 1;
inline void FaultProcMsg::clear_has_fault() {
  has_fault_ = false;
}
inline bool FaultProcMsg::has_fault() const {
  // @@protoc_insertion_point(field_get:IBUS.FaultProcMsg.has_fault)
  return has_fault_;
}
inline void FaultProcMsg::set_has_fault(bool value) {
  
  has_fault_ = value;
  // @@protoc_insertion_point(field_set:IBUS.FaultProcMsg.has_fault)
}

// .IBUS.FaultProcInfo max_level_fault = 2;
inline bool FaultProcMsg::has_max_level_fault() const {
  return this != internal_default_instance() && max_level_fault_ != nullptr;
}
inline void FaultProcMsg::clear_max_level_fault() {
  if (GetArenaNoVirtual() == nullptr && max_level_fault_ != nullptr) {
    delete max_level_fault_;
  }
  max_level_fault_ = nullptr;
}
inline const ::IBUS::FaultProcInfo& FaultProcMsg::max_level_fault() const {
  const ::IBUS::FaultProcInfo* p = max_level_fault_;
  // @@protoc_insertion_point(field_get:IBUS.FaultProcMsg.max_level_fault)
  return p != nullptr ? *p : *reinterpret_cast<const ::IBUS::FaultProcInfo*>(
      &::IBUS::_FaultProcInfo_default_instance_);
}
inline ::IBUS::FaultProcInfo* FaultProcMsg::release_max_level_fault() {
  // @@protoc_insertion_point(field_release:IBUS.FaultProcMsg.max_level_fault)
  
  ::IBUS::FaultProcInfo* temp = max_level_fault_;
  max_level_fault_ = nullptr;
  return temp;
}
inline ::IBUS::FaultProcInfo* FaultProcMsg::mutable_max_level_fault() {
  
  if (max_level_fault_ == nullptr) {
    auto* p = CreateMaybeMessage<::IBUS::FaultProcInfo>(GetArenaNoVirtual());
    max_level_fault_ = p;
  }
  // @@protoc_insertion_point(field_mutable:IBUS.FaultProcMsg.max_level_fault)
  return max_level_fault_;
}
inline void FaultProcMsg::set_allocated_max_level_fault(::IBUS::FaultProcInfo* max_level_fault) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete max_level_fault_;
  }
  if (max_level_fault) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      max_level_fault = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, max_level_fault, submessage_arena);
    }
    
  } else {
    
  }
  max_level_fault_ = max_level_fault;
  // @@protoc_insertion_point(field_set_allocated:IBUS.FaultProcMsg.max_level_fault)
}

// repeated .IBUS.FaultProcInfo fault_list = 3;
inline int FaultProcMsg::fault_list_size() const {
  return fault_list_.size();
}
inline void FaultProcMsg::clear_fault_list() {
  fault_list_.Clear();
}
inline ::IBUS::FaultProcInfo* FaultProcMsg::mutable_fault_list(int index) {
  // @@protoc_insertion_point(field_mutable:IBUS.FaultProcMsg.fault_list)
  return fault_list_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::IBUS::FaultProcInfo >*
FaultProcMsg::mutable_fault_list() {
  // @@protoc_insertion_point(field_mutable_list:IBUS.FaultProcMsg.fault_list)
  return &fault_list_;
}
inline const ::IBUS::FaultProcInfo& FaultProcMsg::fault_list(int index) const {
  // @@protoc_insertion_point(field_get:IBUS.FaultProcMsg.fault_list)
  return fault_list_.Get(index);
}
inline ::IBUS::FaultProcInfo* FaultProcMsg::add_fault_list() {
  // @@protoc_insertion_point(field_add:IBUS.FaultProcMsg.fault_list)
  return fault_list_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::IBUS::FaultProcInfo >&
FaultProcMsg::fault_list() const {
  // @@protoc_insertion_point(field_list:IBUS.FaultProcMsg.fault_list)
  return fault_list_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace IBUS

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_fault_5fproc_2eproto
