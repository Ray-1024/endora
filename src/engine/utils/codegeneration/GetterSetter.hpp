//
// Created by Ray_1024 on 22.06.2025.
//

#ifndef GETTERSETTER_HPP
#define GETTERSETTER_HPP

namespace endora::utils {
#define GETTER(type, fieldName, methodName) \
    public: \
type get##methodName() const { return fieldName; } \
private:

#define GETTER_PTR(type, fieldName, methodName) \
public: \
type* get##methodName() const { return fieldName; } \
private:

#define SETTER(type, fieldName, methodName) \
    public: \
void set##methodName(const type& value) { fieldName = value;} \
private:

#define SETTER_PTR(type, fieldName, methodName) \
public: \
void set##methodName(const type* value) { fieldName = value;} \
private:

#define GETSET_FIELD(type, fieldName, methodName) \
    private: \
    type fieldName{};\
GETTER(type, fieldName, methodName) \
SETTER(type, fieldName, methodName)

#define GETSET_FIELD_PTR(type, fieldName, methodName) \
private: \
type* fieldName{nullptr};\
GETTER_PTR(type, fieldName, methodName) \
SETTER_PTR(type, fieldName, methodName)


#define GETSET(type, fieldName, methodName) \
GETTER(type, fieldName, methodName) \
SETTER(type, fieldName, methodName)


#define GETSET_PTR(type, fieldName, methodName) \
GETTER_PTR(type, fieldName, methodName) \
SETTER_PTR(type, fieldName, methodName)
}

#endif //GETTERSETTER_HPP
