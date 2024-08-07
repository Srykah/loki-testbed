#include "CharacterControllerComponent.hpp"

#include <loki/system/input/InputModule.hpp>

namespace loki::testbed {

void CharacterControllerComponent::onFinalizeInit() {
  physicsBodyComponent = getActor().getComponent<physics::PhysicsBodyComponent>();
}

void CharacterControllerComponent::update(sf::Time dt, UpdateSteps::PrePhysics) {
  static const sf::Vector2f JUMP_IMPULSE{0.f, -1000.f};

  if (!physicsBodyComponent)
    return;

  const auto& inputManager = getService<loki::system::InputModule>();

  if (inputManager.getInputState("jump").status == loki::system::InputState::TRIGGERED) {
    physicsBodyComponent->getBody().applyLinearImpulse(JUMP_IMPULSE);
  }
}

}  // namespace loki::testbed