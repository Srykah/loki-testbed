#include "CharacterControllerComponent.hpp"

#include <loki/system/input/InputModule.hpp>
#include <loki/physics/bodies/PhysicsBodyComponent.hpp>

namespace loki::testbed {

void CharacterControllerComponent::onFinalizeInit() {
  physicsBodyComponent = getActor().getComponent<loki::physics::PhysicsBodyComponent>();
  inputModule = &loki::getService<loki::system::InputModule>();
}

void CharacterControllerComponent::update(sf::Time dt, loki::UpdateSteps::PrePhysics) {
  static const sf::Vector2f JUMP_IMPULSE{0.f, -1000.f};
  static const sf::Vector2f MOVE_FORCE{1000.f, 0.f};

  if (!physicsBodyComponent)
    return;

  if (inputModule->getInputState("jump").status == loki::system::InputState::TRIGGERED) {
    physicsBodyComponent->getBody().applyLinearImpulse(JUMP_IMPULSE);
  }
  if ((inputModule->getInputState("left").status & loki::system::InputState::ACTIVE) != 0) {
    physicsBodyComponent->getBody().applyForce(-MOVE_FORCE);
  }
  if ((inputModule->getInputState("right").status & loki::system::InputState::ACTIVE) != 0) {
    physicsBodyComponent->getBody().applyForce(MOVE_FORCE);
  }
}

}  // namespace loki::testbed