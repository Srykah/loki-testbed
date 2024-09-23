#pragma once

#include <SFML/System/Time.hpp>

#include <loki/system/ecs/Component.hpp>
#include <loki/system/scheduler/UpdateTraits.hpp>

namespace loki {
namespace system {
class InputModule;
}
namespace physics {
class PhysicsBodyComponent;
}

namespace testbed {

class CharacterControllerComponent : public loki::system::Component {
 public:
  void onFinalizeInit() override;
  void onPrePhysics(sf::Time dt);

 private:
  loki::physics::PhysicsBodyComponent* physicsBodyComponent = nullptr;
  loki::system::InputModule* inputModule = nullptr;

  LOKI_RTTI_CLASS_DECLARE(CharacterControllerComponent)
};

}  // namespace testbed
}  // namespace loki

LOKI_REFLECTION_CLASS_BEGIN_CHILD(loki::system::Component, loki::testbed::CharacterControllerComponent)
LOKI_REFLECTION_CLASS_END()
LOKI_RTTI_CLASS_DEFINE(loki::testbed::CharacterControllerComponent)

LOKI_UPDATE_TRAITS_BEGIN(loki::testbed::CharacterControllerComponent)
LOKI_UPDATE_TRAITS_METHOD(PrePhysics, onPrePhysics)
LOKI_UPDATE_TRAITS_END()
