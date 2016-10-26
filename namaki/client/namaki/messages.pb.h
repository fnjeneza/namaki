// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages.proto

#ifndef PROTOBUF_messages_2eproto__INCLUDED
#define PROTOBUF_messages_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace messages {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_messages_2eproto();
void protobuf_AssignDesc_messages_2eproto();
void protobuf_ShutdownFile_messages_2eproto();

class MediaMessage;
class Message;
class TextMessage;

// ===================================================================

class TextMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:messages.TextMessage) */ {
 public:
  TextMessage();
  virtual ~TextMessage();

  TextMessage(const TextMessage& from);

  inline TextMessage& operator=(const TextMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TextMessage& default_instance();

  void Swap(TextMessage* other);

  // implements Message ----------------------------------------------

  inline TextMessage* New() const { return New(NULL); }

  TextMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TextMessage& from);
  void MergeFrom(const TextMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(TextMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string body = 1;
  void clear_body();
  static const int kBodyFieldNumber = 1;
  const ::std::string& body() const;
  void set_body(const ::std::string& value);
  void set_body(const char* value);
  void set_body(const char* value, size_t size);
  ::std::string* mutable_body();
  ::std::string* release_body();
  void set_allocated_body(::std::string* body);

  // @@protoc_insertion_point(class_scope:messages.TextMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_messages_2eproto();
  friend void protobuf_AssignDesc_messages_2eproto();
  friend void protobuf_ShutdownFile_messages_2eproto();

  void InitAsDefaultInstance();
  static TextMessage* default_instance_;
};
// -------------------------------------------------------------------

class MediaMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:messages.MediaMessage) */ {
 public:
  MediaMessage();
  virtual ~MediaMessage();

  MediaMessage(const MediaMessage& from);

  inline MediaMessage& operator=(const MediaMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MediaMessage& default_instance();

  void Swap(MediaMessage* other);

  // implements Message ----------------------------------------------

  inline MediaMessage* New() const { return New(NULL); }

  MediaMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MediaMessage& from);
  void MergeFrom(const MediaMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MediaMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes data = 1;
  void clear_data();
  static const int kDataFieldNumber = 1;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // @@protoc_insertion_point(class_scope:messages.MediaMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_messages_2eproto();
  friend void protobuf_AssignDesc_messages_2eproto();
  friend void protobuf_ShutdownFile_messages_2eproto();

  void InitAsDefaultInstance();
  static MediaMessage* default_instance_;
};
// -------------------------------------------------------------------

class Message : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:messages.Message) */ {
 public:
  Message();
  virtual ~Message();

  Message(const Message& from);

  inline Message& operator=(const Message& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Message& default_instance();

  void Swap(Message* other);

  // implements Message ----------------------------------------------

  inline Message* New() const { return New(NULL); }

  Message* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message& from);
  void MergeFrom(const Message& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Message* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  const ::std::string& id() const;
  void set_id(const ::std::string& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  ::std::string* mutable_id();
  ::std::string* release_id();
  void set_allocated_id(::std::string* id);

  // optional string src = 2;
  void clear_src();
  static const int kSrcFieldNumber = 2;
  const ::std::string& src() const;
  void set_src(const ::std::string& value);
  void set_src(const char* value);
  void set_src(const char* value, size_t size);
  ::std::string* mutable_src();
  ::std::string* release_src();
  void set_allocated_src(::std::string* src);

  // optional string dest = 3;
  void clear_dest();
  static const int kDestFieldNumber = 3;
  const ::std::string& dest() const;
  void set_dest(const ::std::string& value);
  void set_dest(const char* value);
  void set_dest(const char* value, size_t size);
  ::std::string* mutable_dest();
  ::std::string* release_dest();
  void set_allocated_dest(::std::string* dest);

  // optional uint32 timestamp = 4;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 4;
  ::google::protobuf::uint32 timestamp() const;
  void set_timestamp(::google::protobuf::uint32 value);

  // optional .messages.TextMessage text = 5;
  bool has_text() const;
  void clear_text();
  static const int kTextFieldNumber = 5;
  const ::messages::TextMessage& text() const;
  ::messages::TextMessage* mutable_text();
  ::messages::TextMessage* release_text();
  void set_allocated_text(::messages::TextMessage* text);

  // optional .messages.MediaMessage media = 6;
  bool has_media() const;
  void clear_media();
  static const int kMediaFieldNumber = 6;
  const ::messages::MediaMessage& media() const;
  ::messages::MediaMessage* mutable_media();
  ::messages::MediaMessage* release_media();
  void set_allocated_media(::messages::MediaMessage* media);

  // @@protoc_insertion_point(class_scope:messages.Message)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr id_;
  ::google::protobuf::internal::ArenaStringPtr src_;
  ::google::protobuf::internal::ArenaStringPtr dest_;
  ::messages::TextMessage* text_;
  ::messages::MediaMessage* media_;
  ::google::protobuf::uint32 timestamp_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_messages_2eproto();
  friend void protobuf_AssignDesc_messages_2eproto();
  friend void protobuf_ShutdownFile_messages_2eproto();

  void InitAsDefaultInstance();
  static Message* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TextMessage

// optional string body = 1;
inline void TextMessage::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TextMessage::body() const {
  // @@protoc_insertion_point(field_get:messages.TextMessage.body)
  return body_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextMessage::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.TextMessage.body)
}
inline void TextMessage::set_body(const char* value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.TextMessage.body)
}
inline void TextMessage::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.TextMessage.body)
}
inline ::std::string* TextMessage::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:messages.TextMessage.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TextMessage::release_body() {
  // @@protoc_insertion_point(field_release:messages.TextMessage.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextMessage::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:messages.TextMessage.body)
}

// -------------------------------------------------------------------

// MediaMessage

// optional bytes data = 1;
inline void MediaMessage::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MediaMessage::data() const {
  // @@protoc_insertion_point(field_get:messages.MediaMessage.data)
  return data_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MediaMessage::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.MediaMessage.data)
}
inline void MediaMessage::set_data(const char* value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.MediaMessage.data)
}
inline void MediaMessage::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.MediaMessage.data)
}
inline ::std::string* MediaMessage::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:messages.MediaMessage.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MediaMessage::release_data() {
  // @@protoc_insertion_point(field_release:messages.MediaMessage.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MediaMessage::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:messages.MediaMessage.data)
}

// -------------------------------------------------------------------

// Message

// optional string id = 1;
inline void Message::clear_id() {
  id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Message::id() const {
  // @@protoc_insertion_point(field_get:messages.Message.id)
  return id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Message::set_id(const ::std::string& value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.Message.id)
}
inline void Message::set_id(const char* value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.Message.id)
}
inline void Message::set_id(const char* value, size_t size) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.Message.id)
}
inline ::std::string* Message::mutable_id() {
  
  // @@protoc_insertion_point(field_mutable:messages.Message.id)
  return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Message::release_id() {
  // @@protoc_insertion_point(field_release:messages.Message.id)
  
  return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Message::set_allocated_id(::std::string* id) {
  if (id != NULL) {
    
  } else {
    
  }
  id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
  // @@protoc_insertion_point(field_set_allocated:messages.Message.id)
}

// optional string src = 2;
inline void Message::clear_src() {
  src_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Message::src() const {
  // @@protoc_insertion_point(field_get:messages.Message.src)
  return src_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Message::set_src(const ::std::string& value) {
  
  src_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.Message.src)
}
inline void Message::set_src(const char* value) {
  
  src_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.Message.src)
}
inline void Message::set_src(const char* value, size_t size) {
  
  src_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.Message.src)
}
inline ::std::string* Message::mutable_src() {
  
  // @@protoc_insertion_point(field_mutable:messages.Message.src)
  return src_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Message::release_src() {
  // @@protoc_insertion_point(field_release:messages.Message.src)
  
  return src_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Message::set_allocated_src(::std::string* src) {
  if (src != NULL) {
    
  } else {
    
  }
  src_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), src);
  // @@protoc_insertion_point(field_set_allocated:messages.Message.src)
}

// optional string dest = 3;
inline void Message::clear_dest() {
  dest_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Message::dest() const {
  // @@protoc_insertion_point(field_get:messages.Message.dest)
  return dest_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Message::set_dest(const ::std::string& value) {
  
  dest_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.Message.dest)
}
inline void Message::set_dest(const char* value) {
  
  dest_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.Message.dest)
}
inline void Message::set_dest(const char* value, size_t size) {
  
  dest_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.Message.dest)
}
inline ::std::string* Message::mutable_dest() {
  
  // @@protoc_insertion_point(field_mutable:messages.Message.dest)
  return dest_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Message::release_dest() {
  // @@protoc_insertion_point(field_release:messages.Message.dest)
  
  return dest_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Message::set_allocated_dest(::std::string* dest) {
  if (dest != NULL) {
    
  } else {
    
  }
  dest_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), dest);
  // @@protoc_insertion_point(field_set_allocated:messages.Message.dest)
}

// optional uint32 timestamp = 4;
inline void Message::clear_timestamp() {
  timestamp_ = 0u;
}
inline ::google::protobuf::uint32 Message::timestamp() const {
  // @@protoc_insertion_point(field_get:messages.Message.timestamp)
  return timestamp_;
}
inline void Message::set_timestamp(::google::protobuf::uint32 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:messages.Message.timestamp)
}

// optional .messages.TextMessage text = 5;
inline bool Message::has_text() const {
  return !_is_default_instance_ && text_ != NULL;
}
inline void Message::clear_text() {
  if (GetArenaNoVirtual() == NULL && text_ != NULL) delete text_;
  text_ = NULL;
}
inline const ::messages::TextMessage& Message::text() const {
  // @@protoc_insertion_point(field_get:messages.Message.text)
  return text_ != NULL ? *text_ : *default_instance_->text_;
}
inline ::messages::TextMessage* Message::mutable_text() {
  
  if (text_ == NULL) {
    text_ = new ::messages::TextMessage;
  }
  // @@protoc_insertion_point(field_mutable:messages.Message.text)
  return text_;
}
inline ::messages::TextMessage* Message::release_text() {
  // @@protoc_insertion_point(field_release:messages.Message.text)
  
  ::messages::TextMessage* temp = text_;
  text_ = NULL;
  return temp;
}
inline void Message::set_allocated_text(::messages::TextMessage* text) {
  delete text_;
  text_ = text;
  if (text) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:messages.Message.text)
}

// optional .messages.MediaMessage media = 6;
inline bool Message::has_media() const {
  return !_is_default_instance_ && media_ != NULL;
}
inline void Message::clear_media() {
  if (GetArenaNoVirtual() == NULL && media_ != NULL) delete media_;
  media_ = NULL;
}
inline const ::messages::MediaMessage& Message::media() const {
  // @@protoc_insertion_point(field_get:messages.Message.media)
  return media_ != NULL ? *media_ : *default_instance_->media_;
}
inline ::messages::MediaMessage* Message::mutable_media() {
  
  if (media_ == NULL) {
    media_ = new ::messages::MediaMessage;
  }
  // @@protoc_insertion_point(field_mutable:messages.Message.media)
  return media_;
}
inline ::messages::MediaMessage* Message::release_media() {
  // @@protoc_insertion_point(field_release:messages.Message.media)
  
  ::messages::MediaMessage* temp = media_;
  media_ = NULL;
  return temp;
}
inline void Message::set_allocated_media(::messages::MediaMessage* media) {
  delete media_;
  media_ = media;
  if (media) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:messages.Message.media)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace messages

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messages_2eproto__INCLUDED
