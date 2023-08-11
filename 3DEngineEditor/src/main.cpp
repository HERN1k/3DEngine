#include <iostream>
#include <memory>
#include <3DEngineCore/Application.hpp>

class MyApp : public Engine3D::Application {
	
	virtual void on_update() override {
		
		std::cout << "Update frame: " << frame++ << std::endl;

	}

	int frame = 0;

};

int main() {
	
	auto myApp = std::make_unique<MyApp>();

	int returnCode = myApp->start(800, 600, "3D image!");

	std::cin.get();

	return returnCode;
}