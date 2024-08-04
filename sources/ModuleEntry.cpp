#include <loki/core/rtti/RuntimeObjectRegistry.hpp>
#include <loki/system/ecs/ComponentRegistry.hpp>

#include "CharacterControllerComponent.hpp"

#if defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__
#ifdef __GNUC__
#define LOKI_TESTBED_EXPORT __attribute__((dllexport))
#else
#define LOKI_TESTBED_EXPORT __declspec(dllexport)
#endif
#else
#if __GNUC__ >= 4
#define LOKI_TESTBED_EXPORT __attribute__((visibility("default")))
#else
#define LOKI_TESTBED_EXPORT
#endif
#endif

#if __cplusplus
extern "C" {
#endif

LOKI_TESTBED_EXPORT void registerServiceRegistry(const void* serviceRegistry) {
  loki::core::ServiceRegistry::setInstance(static_cast<const loki::core::ServiceRegistry*>(serviceRegistry));
}

LOKI_TESTBED_EXPORT void registerCustomRuntimeTypes(void* _runtimeObjectRegistry) {
  auto& runtimeObjectRegistry = *static_cast<loki::core::RuntimeObjectRegistry*>(_runtimeObjectRegistry);
  // todo
}

LOKI_TESTBED_EXPORT void registerCustomModules(void* _runtimeObjectRegistry) {
  auto& runtimeObjectRegistry = *static_cast<loki::core::RuntimeObjectRegistry*>(_runtimeObjectRegistry);
  // todo
}

LOKI_TESTBED_EXPORT void registerCustomComponents(void* _runtimeObjectRegistry, void* _componentRegistry) {
  auto& runtimeObjectRegistry = *static_cast<loki::core::RuntimeObjectRegistry*>(_runtimeObjectRegistry);
  auto& componentRegistry = *static_cast<loki::system::ComponentRegistry*>(_componentRegistry);

#define LOKI_TESTBED_REGISTER_COMP(Comp)       \
  runtimeObjectRegistry.registerClass<Comp>(); \
  componentRegistry.registerComponent<Comp>()

  //- begin
  LOKI_TESTBED_REGISTER_COMP(loki::testbed::CharacterControllerComponent);
  //- end

#undef LOKI_TESTBED_REGISTER_COMP
}

#if __cplusplus
}
#endif