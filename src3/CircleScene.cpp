#include <iostream>
#include "CircleScene.h"
#include "Loop.h"

using namespace std;

extern Loop loop;

CircleScene::CircleScene() { 
	circles.push_back(Circle(&wave1));
	circles.push_back(Circle(&wave2));
	circles.push_back(Circle(&wave3));
	circles.push_back(Circle(&wave4));
	circles.push_back(Circle(&wave5));
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
	for (int i = 0; i < circles.size(); ++i) {
		loop.addObject(&circles[i]);
	}
}

void CircleScene::deactivate() {
	for (int i = 0; i < circles.size(); ++i) {
		loop.removeObject(&circles[i]);
	}
}

