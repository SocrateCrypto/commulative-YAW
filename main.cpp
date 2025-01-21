#include <iostream>

// Функция для нормализации угла в диапазоне [−180, 180] градусов
double normalizeAngle(double angle) {
    while (angle > 180) angle -= 360;
    while (angle < -180) angle += 360;
    return angle;
}

int main() {
    double previousYaw = 0; // Предыдущее значение yaw
    double cumulativeYaw = 0; // Кумулятивное значение yaw
    double currentYaw = 0; // Текущее значение yaw с датчика IMU

    while (true) {
        std::cout << "Input current YAW: "; // Вывод приглашения для ввода 
        std::cin >>  currentYaw; // Чтение значения из консоли и сохранение его в переменную urrentYaw
        

        // Расчет изменения yaw
        double deltaYaw = normalizeAngle(currentYaw - previousYaw);

        // Обновление кумулятивного значения yaw
        cumulativeYaw += deltaYaw;

        // Обновление предыдущего значения yaw
        previousYaw = currentYaw;

        // Вывод кумулятивного значения yaw
        std::cout << "Cumulative Yaw: " << cumulativeYaw << std::endl;
    }

    return 0;
}
