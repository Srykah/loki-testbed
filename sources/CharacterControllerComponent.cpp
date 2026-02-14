#include "CharacterControllerComponent.hpp"

#include <loki/system/input/InputModule.hpp>
#include <loki/physics/bodies/PhysicsBodyComponent.hpp>

namespace loki::testbed {

void CharacterControllerComponent::onEndInit() {
  physicsBodyComponent = getActor().getComponent<loki::physics::PhysicsBodyComponent>();
  inputModule = &loki::getService<loki::system::InputModule>();
}

void CharacterControllerComponent::onPrePhysics(sf::Time delta) {
  static const sf::Vector2f JUMP_IMPULSE{0.f, -1000.f};
  static const sf::Vector2f MOVE_FORCE{1000.f, 0.f};

  if (!physicsBodyComponent)
    return;

  if (auto jumpState = inputModule->getInputState("jump"); jumpState.hasChanged && jumpState.isActive) {
    physicsBodyComponent->getBody().applyLinearImpulse(JUMP_IMPULSE);
  }
  if (inputModule->getInputState("left").isActive) {
    physicsBodyComponent->getBody().applyForce(-MOVE_FORCE);
  }
  if (inputModule->getInputState("right").isActive) {
    physicsBodyComponent->getBody().applyForce(MOVE_FORCE);
  }
}

}  // namespace loki::testbed