#include <iostream>
#include <array>
#include <cmath> 

class TemperatureSystem {
private:
    float recommendedTemperature;
    std::array<float, 5> currentTemperatures;

public:
    // Inicializa la temperatura recomendada y la actual a 0.
    TemperatureSystem() : recommendedTemperature(0.0), currentTemperatures({0.0, 0.0, 0.0, 0.0, 0.0}) {}

    // Cambiar la temperatura recomendada
    void setRecommendedTemperature(float newTemperature) {
        recommendedTemperature = newTemperature;
        std::cout << "Recommended temperature changed to: " << recommendedTemperature << std::endl;
    }

    // Cambiar la temperatura de una determinada zona
    void setCurrentTemperature(int zone, float newTemperature) {
        if (zone >= 0 && zone < 5) {
            currentTemperatures[zone] = newTemperature;
        } else {
            std::cerr << "Invalid zone index. Zone index should be between 0 and 4." << std::endl;
        }
    }

    // Cambiar la temperatura de todas las zonas
    void setCurrentTemperatures(const std::array<float, 5>& newTemperatures) {
        currentTemperatures = newTemperatures;
    }

    // Comparar la temperatura actual y la recomendada. 
    void compareTemperatures() {
        for (int i = 0; i < 5; ++i) {
            float diff = currentTemperatures[i] - recommendedTemperature;
            std::string flag = (diff == 0) ? "EQUAL" : (diff > 0) ? "HIGHER" : "LOWER";
            std::cout << "Zone " << i << ": Flag = " << flag << ", Temperature Difference = " << std::abs(diff) << std::endl;
        }
    }
};

int main() {
    TemperatureSystem tempSystem;
    tempSystem.setRecommendedTemperature(25.0);
    tempSystem.setCurrentTemperature(0, 20.0);
    tempSystem.setCurrentTemperature(1, 25.0);
    tempSystem.setCurrentTemperature(2, 30.0);
    tempSystem.setCurrentTemperature(3, 35.0);
    tempSystem.setCurrentTemperature(4, 40.0);
    tempSystem.compareTemperatures();
    return 0;
}
