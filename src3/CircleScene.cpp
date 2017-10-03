#include <iostream>
#include "CircleScene.h"

using namespace std;

CircleScene::CircleScene() { 
	circles.push_back(Circle());
	circles.push_back(Circle());
	circles.push_back(Circle());
	circles.push_back(Circle());
	circles.push_back(Circle());
	circles.push_back(Circle());
}

CircleScene::~CircleScene() {
}

void CircleScene::start() {
	for (int i = 0; i < circles.size(); ++i) {
		circles[i].activate();
	}
}

void CircleScene::stop() {
	for (int i = 0; i < circles.size(); ++i) {
		circles[i].deactivate();
	}
}

void CircleScene::update(double dt) {
}

void CircleScene::mix(double t) {
}

void CircleScene::draw(double t) {
}

void CircleScene::activate() {
}

void CircleScene::deactivate() {
}

