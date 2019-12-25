//
//  MathUtil.cpp
//  3dmath
//
//  Created by xiaoxiangzi on 2019/12/15.
//  Copyright © 2019 xiaoxiangzi. All rights reserved.
//

#include <math.h>
#include "MathUtil.h"
#include "Vector3.hpp"

const Vector3 kZeroVector(0.0f, 0.0f, 0.0f);

// 通过加上适当的2pi倍数，将角度限制在-pi到pi的区间
float wrapPi(float theta) {
    theta += kPi;
    theta -= floor(theta * k1Over2Pi) * k2Pi;
    theta -= kPi;
    return theta;
}

// 和acos(x)相同，但如果x超出范围将返回最为接近的有效值
// 返回值在0-pi之间，和c语言中的标准acos函数相同
float safeAcos(float x) {
    if (x <= -1.0f) {
        return kPi;
    }
    
    if (x >= 1.0f) {
        return 0.0f;
    }
    
    return acos(x);
}
