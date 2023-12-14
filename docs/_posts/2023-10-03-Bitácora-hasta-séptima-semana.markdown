---
layout: post
title:  "Bitácora hasta séptima semana"
date:   2023-10-03 19:26:00 -0300
categories: posts
---

# Bitácora hasta séptima semana

`Planificación de tareas`

![Gantt 5 6 y 7](proyecto-plant-o-matic/assets/Gantt 5 6 y 7.jpg)

- Entregamos la documentación del Anteproyecto y obtuvimos buen resultado.

- Recibimos pocos materiales de los solicitados. Volvimos a realizar el pedido pero esta vez teniendo la certeza de que el proveedor tiene en stock. 

- @nJavo y @martin229101 estuvieron a mil investigando codigos

 `Código humedad`

```c++
#include <iostream>
#include <array>
#include <cmath>
#include <fstream>
#include <thread>
#include <random>
#include <chrono>

class HumiditySystem {
private:
    float recommendedHumidity;
    std::array<float, 5> currentHumidities;

public:
    // Inicializa la humedad recomendada y la actual a 0.
    HumiditySystem() : recommendedHumidity(0.0), currentHumidities({0.0, 0.0, 0.0, 0.0, 0.0}) {}

    // Cambiar la humedad recomendada
    void setRecommendedHumidity(float newHumidity) {
        recommendedHumidity = newHumidity;
        std::cout << "Recommended humidity changed to: " << recommendedHumidity << std::endl;
    }

    // Cambiar la humedad de una determinada zona
    void setCurrentHumidity(int zone, float newHumidity) {
        if (zone >= 0 && zone < 5) {
            currentHumidities[zone] = newHumidity;
        } else {
            std::cerr << "Invalid zone index. Zone index should be between 0 and 4." << std::endl;
        }
    }

    // Cambiar la humedad de todas las zonas
    void setCurrentHumidities(const std::array<float, 5>& newHumidities) {
        currentHumidities = newHumidities;
    }

    // Comparar la humedad actual y la recomendada. 
    void compareHumidities() {
        for (int i = 0; i < 5; ++i) {
            float diff = currentHumidities[i] - recommendedHumidity;
            std::string flag = (diff == 0) ? "EQUAL" : (diff > 0) ? "HIGHER" : "LOWER";
            std::cout << "Zone " << i << ": Flag = " << flag << ", Humidity Difference = " << std::abs(diff) << std::endl;
        }
    }
    void saveDataToFile(const std::string& filePath) {
        std::ofstream file(filePath);  // Create an output file stream
        if (file.is_open()) {  // Check if the file is open
            for (float humidity : currentHumidities) {  // Loop through the currentHumidities array
                file << humidity << std::endl;  // Write each humidity value to the file
            }
            file << recommendedHumidity << std::endl;  // Write the recommendedHumidity value to the file
            file.close();  // Close the file
            std::cout << "Data saved to " << filePath << std::endl;
        } else {
            std::cerr << "Unable to open file " << filePath << std::endl;
        }
    }
};


void updateHumidities(HumiditySystem& system, std::default_random_engine& generator, std::uniform_real_distribution<float>& distribution) {
    for (int i = 0; i < 5; ++i) {
        system.setCurrentHumidity(i, distribution(generator));
    }
}

void updateRecommendedHumidity(HumiditySystem& system, std::default_random_engine& generator, std::uniform_real_distribution<float>& distribution) {
    system.setRecommendedHumidity(distribution(generator));
}

int main() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<float> distribution(0.0, 100.0);

    HumiditySystem humidSystem;

    while (true) {  // Simulate 10 iterations
        updateHumidities(humidSystem, generator, distribution);
        updateRecommendedHumidity(humidSystem, generator, distribution);
        humidSystem.compareHumidities();


        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

```

 `Código temperatura`

```c++
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

```

`Código conexión Wifi`

![159Wifi0](/proyecto-plant-o-matic/assets/159Wifi0.jpeg)

![159Wifi1](/proyecto-plant-o-matic/assets/159Wifi1.jpeg)

![159Wifi2](/proyecto-plant-o-matic/assets/159Wifi2.jpeg)


