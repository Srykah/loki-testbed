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
  void onEndInit() override;
  void onPrePhysics(sf::Time dt) override;

 private:
  loki::physics::PhysicsBodyComponent* physicsBodyComponent = nullptr;
  loki::system::InputModule* inputModule = nullptr;

  LOKI_RTTI_CLASS_DECLARE(CharacterControllerComponent)
};

}  // namespace testbed
}  // namespace loki

LOKI_REFLECTION_COMPONENT_BEGIN(loki::testbed::CharacterControllerComponent)
LOKI_REFLECTION_CLASS_END()
LOKI_RTTI_CLASS_DEFINE(loki::testbed::CharacterControllerComponent)
