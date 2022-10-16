#pragma once

/// <summary>
/// Подсчёт квадратного корня.
/// </summary>
/// <param name="x">Число, корень которого необходимо извлечь.</param>
/// <returns>Квадратный корень заданного числа.</returns>
float fastSqrt(const float x)
{
    union
    {
        int i;
        float x;
    } u;

    u.x = x;
    u.i = (1 << 29) + (u.i >> 1) - (1 << 22);

    u.x = u.x + x / u.x;
    u.x = 0.25f * u.x + x / u.x;

    return u.x;
}
