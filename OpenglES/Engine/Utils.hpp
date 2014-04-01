//
//  Utils.h
//  OpenglES
//
//  Created by Radaev Mikhail on 20.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#pragma once
#include "Vector2.hpp"
#include "Define.h"
#include <random>

using namespace std;

using namespace Math;

namespace Random {
    template<typename T>
    class Utils
    {
    public:
        static T GenerateRandomAngleAtRadians()
        {
            float grad = Utils::GenerateRandomRealValue(0.0, 360.0);
            return grad * (M_PI/180);
        }
        static T GenerateRandomRealValue(T min,T max)
        {
            uniform_real_distribution<T> distribution(min, max);
            random_device rd;
            default_random_engine generator( rd() );
            return distribution(generator);

        }
        static T GenerateRandomIntValue(T min,T max)
        {
            uniform_int_distribution<T> distribution(min, max);
            random_device rd;
            default_random_engine generator( rd() );
            return distribution(generator);
        }
    };
}
