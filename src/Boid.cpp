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

void Boid::flock(const std::vector<Boid*> &nearests) {}

const bool Boid::sees(const Boid &boid) const {
  glm::vec3 dist = boid._position - _position;
  float vec_dot  = glm::dot(_velocity, dist) ;
  float angle    = vec_dot / (glm::length(_velocity)*glm::length(dist));
  return ((angle > 360 - _view_angle) && (glm::length(dist) < _view_range)) ? true : false; 
}

void Boid::update(const double &dT) {

  float dTf = static_cast<float>(dT);
  glm::vec3 target = update_behaviour();

  switch (_current_behaviour) {
  case BEHAVIOUR::SEEK:
    seek(target);
    break;
  case BEHAVIOUR::FLEE:
    flee(target);
    break;
  case BEHAVIOUR::FLOCK:
    // flock();
    break;
  }

  if (glm::length(_velocity + _acceleration * dTf) < MAX_SPEED) {
    _velocity.x += _acceleration.x * dTf;
    _velocity.y += _acceleration.y * dTf;
  }

  _position += (_velocity * BASE_SPEED) * dTf;

  _acceleration -= _acceleration * 0.15f;
}

const glm::vec3 Boid::update_behaviour() {

  glm::vec3 target = _position + 2.f * _velocity;
  _current_behaviour = BEHAVIOUR::SEEK;

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

void Boid::render() const { render_triangle(_position, _velocity, 10.f); }