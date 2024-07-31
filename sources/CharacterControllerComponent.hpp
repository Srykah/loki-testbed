#pragma once

#include <loki/system/ecs/Component.hpp>
#include <loki/physics/bodies/PhysicsBodyComponent.hpp>

namespace loki::testbed {

class CharacterControllerComponent : public loki::system::Component {
 public:
  void onFinalizeInit() override;
  void update(sf::Time dt) override;

 private:
  loki::physics::PhysicsBodyComponent* physicsBodyComponent = nullptr;

  LOKI_REFLECTION_CLASS_DECLARE_RTTI(CharacterControllerComponent)
};

}  // namespace loki::testbed

LOKI_REFLECTION_CLASS_BEGIN_CHILD(loki::system::Component, loki::testbed::CharacterControllerComponent)
LOKI_REFLECTION_CLASS_END_RTTI(loki::testbed::CharacterControllerComponent)