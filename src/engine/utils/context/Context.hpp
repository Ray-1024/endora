//
// Created by Ray_1024 on 22.06.2025.
//

#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <memory>
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <any>
#include <stdexcept>

namespace endora::utils {
    class Context {
    public:
        template<typename T, typename... Dependencies>
        std::shared_ptr<T> createSingleton() {
            if (const auto it = instances.find(typeid(T)); it != instances.end())
                throw std::runtime_error("Type already registered");
            const auto instance = std::make_shared<T>(resolve<Dependencies>()...);
            instances[typeid(T)] = instance;
            return instance;
        }

        template<typename T, typename... Dependencies>
        std::shared_ptr<T> resolveOrCreateSingleton() {
            const auto ptr = resolve<T>();
            return ptr ? ptr : createSingleton<T, Dependencies...>();
        }

        template<typename T>
        std::shared_ptr<T> registerSingleton(std::shared_ptr<T> instance) {
            if (const auto it = instances.find(typeid(T)); it != instances.end())
                throw std::runtime_error("Type already registered");
            instances[typeid(T)] = instance;
            return instance;
        }

        template<typename T>
        void removeSingleton() {
            if (const auto it = instances.find(typeid(T)); it != instances.end())
                throw std::runtime_error("Type doesn't registered");
            instances.erase(typeid(T));
        }

        template<typename T>
        std::shared_ptr<T> resolve() {
            const auto it = instances.find(typeid(T));
            if (it == instances.end())
                return nullptr;
            return std::any_cast<std::shared_ptr<T> >(it->second);
        }

        template<typename T>
        bool isRegistered() const {
            return instances.contains(typeid(T));
        }

        void clear() {
            instances.clear();
        }

    private:
        std::unordered_map<std::type_index, std::any> instances;
    };
} // endora

#endif //CONTEXT_HPP
