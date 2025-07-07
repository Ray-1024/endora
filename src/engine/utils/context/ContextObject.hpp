//
// Created by Ray_1024 on 07.07.2025.
//

#ifndef SMARTCONTRUCT_HPP
#define SMARTCONTRUCT_HPP
#include <memory>

#include "Context.hpp"

namespace endora::utils {
    class ContextObject {
    protected:
        std::shared_ptr<endora::utils::Context> context;

    public:
        explicit ContextObject(const std::shared_ptr<endora::utils::Context> &context) : context(context) {
        }

        virtual void postConstruct() = 0;

        virtual void preDestruct() = 0;

        virtual ~ContextObject() = default;
    };
} // endora

#endif //SMARTCONTRUCT_HPP
