#include "../includes/Boid.hpp"

void Boid::seek(const glm::vec3 &target) {
  glm::vec3 desired = target - _position;
  desired = glm::normalize(desired) * MAX_SPEED;
  glm::vec3 steer = desired - _velocity;

  if (glm::length(_acceleration + steer) < MAX_ACCEL)
    _acceleration += steer;
}

void Boid::flee(const glm::vec3 &target) {
  glm::vec3 desired = target - _position;
  desired = glm::normalize(desired) * MAX_SPEED;
  glm::vec3 steer = -desired - _velocity;

  if (glm::length(_acceleration + steer) < MAX_ACCEL)
    _acceleration += steer;
}

void Boid::flock(const std::vector<Boid *> &nearest, const float &dT) {
  int i = 0;
  glm::vec3 total_velocity(0);
  for (auto &n : nearest) {
    total_velocity += n->_velocity;
    if (length(n->_position - _position) < _view_range * 0.75) {
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

  glm::vec3 dist = boid._position - _position;

  float vec_dot = glm::dot(_velocity, dist);
  float angle = abs((vec_dot / (glm::length(_velocity) * glm::length(dist))) *
                    180 / 3.141592f);

  if ((angle < (360 - _view_angle)) && (glm::length(dist) < _view_range)) {
    return true;
  }
  return false;
}

void Boid::update(const float &dT, const std::vector<Boid *> &nearests) {

  glm::vec3 target = update_behaviour(nearests);

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

  if (glm::length(_velocity + _acceleration * dT) < MAX_SPEED) {
    _velocity.x += _acceleration.x * dT;
    _velocity.y += _acceleration.y * dT;
  }

  _position += (_velocity * BASE_SPEED) * dT;
  _acceleration -= _acceleration * 0.15f;
}

const glm::vec3 Boid::update_behaviour(std::vector<Boid *> nearests) {

  glm::vec3 target = _position + 2.f * _velocity;
  _current_behaviour = BEHAVIOUR::SEEK;

  if (nearests.size() > 0) {
    _current_behaviour = BEHAVIOUR::FLOCK;
  }

  if (_position.x < 50 && _velocity.x <= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;
    target.x -= glm::abs(_position.x);
  } else if (_position.x > 950 && _velocity.x >= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;
    target.x += _position.x;
  }
  if (_position.y < 50 && _velocity.y <= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;
    target.y -= glm::abs(_position.y);
  } else if (_position.y > 950 && _velocity.y >= 0) {
    _current_behaviour = BEHAVIOUR::FLEE;
    target.y += _position.y;
  }

  return target;
}

void Boid::render() const { display_sheep(_position, _velocity, 8.f); }