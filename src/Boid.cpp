#include "../lib/Boid.hpp"

void Boid::seek(const glm::vec2 &target) {
  glm::vec2 desired = target - _position;
  desired = glm::normalize(desired) * _max_speed;
  glm::vec2 steer = desired - _velocity;

  if (glm::length(_acceleration + steer) < _max_speed * 2)
    _acceleration += steer;
}

void Boid::flee(const glm::vec2 &target) {
  glm::vec2 desired = target - _position;
  desired = glm::normalize(desired) * _max_speed;
  glm::vec2 steer = -desired - _velocity;

  if (glm::length(_acceleration + steer) <= _max_speed * 2)
    _acceleration += steer;
}

void Boid::flock(const std::vector<Boid *> &nearest, const float &dT) {
  int i = 0;
  glm::vec2 total_velocity(0);
  for (auto &n : nearest) {
    total_velocity += n->_velocity;
    if (length(n->_position - _position) < _view_range * 0.4) {
      flee(n->_position);
    } else {
      seek(n->_position);
    }
    ++i;
  }
  total_velocity /= i;

  seek(_position + total_velocity * dT);
}

bool Boid::sees(const Boid &boid) const {
  glm::vec2 dist = boid._position - _position;
  if (length(dist) < length(glm::vec2(_view_range)) &&
      (length(dist) > length(glm::vec2(0.01f)))) {
    float vec_dot = glm::dot(_velocity, dist);
    float angle = abs((vec_dot / (glm::length(_velocity) * glm::length(dist))) *
                      180 / 3.141592f);

    if ((angle < (_view_angle))) {
      return true;
    }
    return false;
  }
  return 0;
}

void Boid::update(const float &dT, const std::vector<Boid *> &nearests) {

  glm::vec2 target = update_behaviour(nearests);

  switch (_current_behaviour) {
  case BEHAVIOUR::SEEK:
    seek(target);
    break;
  case BEHAVIOUR::FLEE:
    flee(target);
    break;
  case BEHAVIOUR::FLOCK:
    flock(nearests, dT);
    break;
  }

  if (glm::length(_velocity + _acceleration * dT) < _max_speed) {
    _velocity.x += _acceleration.x * dT * 0.1f;
    _velocity.y += _acceleration.y * dT * 0.1f;
  }

  _position += (_velocity * BASE_SPEED) * dT;
  _acceleration -= _acceleration * 0.01f; // ARBITRAIRE
}

const glm::vec2 Boid::update_behaviour(std::vector<Boid *> nearests) {

  glm::vec2 target = _position + 1.f * _velocity;
  _current_behaviour = BEHAVIOUR::SEEK;

  if (nearests.size() > 1) {
    _current_behaviour = BEHAVIOUR::FLOCK;
  }

  if (_position.x < -0.9 && _velocity.x <= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;

    target.x -= glm::abs(_position.x);
  }

  else if (_position.x > 0.9 && _velocity.x >= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;
    target.x += glm::abs(_position.x);
  }

  if (_position.y < -0.9 && _velocity.y <= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;

    target.y -= glm::abs(_position.y);
  } else if (_position.y > 0.9 && _velocity.y >= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;

    target.y += _position.y;
  }

  return target;
}

void Boid::render(p6::Context &ctx, float &radius) {
  display_sheep(ctx, _position, _velocity, radius, _max_speed);
}