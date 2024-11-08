//
// Created by DELL on 2024/11/1.
//
#include "temperature.h"
#include <float.h>
#include <math.h>
#include "stdint.h"
#include "main.h"
#include "lcd.h"
#define MIN_TARGET_TEMP 22.0     // 最低目标温度
#define MAX_TARGET_TEMP 30.0     // 最高目标温度
#define TEMP_INCREASE 10.0        // 环境温度加温增量
#define DEAD_ZONE 0.5      // 死区范围，用于避免在目标附近频繁开关

float envTemp = 25 ;

const  SWITCH switchs[SWITCH_NUMS]={

        {SWITCH1_GPIO_Port,SWITCH1_Pin},
        {SWITCH2_GPIO_Port,SWITCH2_Pin},
        {SWITCH3_GPIO_Port,SWITCH3_Pin},
        {SWITCH4_GPIO_Port,SWITCH4_Pin},
};

const SWITCH switch_leds[5]={
        {LED1_GPIO_Port,LED1_Pin},
        {LED2_GPIO_Port,LED2_Pin},
        {LED3_GPIO_Port,LED3_Pin},
        {LED4_GPIO_Port,LED4_Pin},
        {LED5_GPIO_Port,LED5_Pin},
};

// 控制加热器
void controlHeater(int turnOn) {
    if (turnOn) {

        // 这里添加开启加热器的代码
    } else {
   }
}

void UpdateSwitch(float* temps ,int size){
    float targetTemperature =MIN_TARGET_TEMP;

    float nowNTCTemp ;
    int  HeartOn ;
    for(int i=0; i<size; i++){
        nowNTCTemp=temps[i];
        if (nowNTCTemp<MIN_TARGET_TEMP && envTemp< MIN_TARGET_TEMP){
            //温室内外都低于设定温度 需要开启加热
            targetTemperature = envTemp+ TEMP_INCREASE;
            while( targetTemperature< MIN_TARGET_TEMP){
                //确认加温到设置温度内
                targetTemperature+=TEMP_INCREASE;
            }
            // 限制目标温度在最大范围内
            if (targetTemperature > MAX_TARGET_TEMP) {
                targetTemperature = MAX_TARGET_TEMP;
            }
        } else if (nowNTCTemp> MAX_TARGET_TEMP) {
            // 如果环境温度在22到30之间，保持目标温度不变
            targetTemperature = envTemp; // 可以选择不加热
        };
        if (targetTemperature<envTemp){
            //目标温度小于外环境温度 没必要加热
            continue;
        }
        if (nowNTCTemp>targetTemperature-DEAD_ZONE && nowNTCTemp<= MAX_TARGET_TEMP  ){
            //在这区间内不做操作
            continue;
        }
        // if 
        if (nowNTCTemp<targetTemperature){
            HeartOn=1;
        }else{
            HeartOn=0;
        }

        if (HeartOn){

            HAL_GPIO_WritePin(switch_leds[i].port,switch_leds[i].pin,GPIO_PIN_SET);
            Lcd_print( 150,  140,  BLUE, "> N %.2f In %d  %.2f",nowNTCTemp,i,targetTemperature);

        }else{
            HAL_GPIO_WritePin(switch_leds[i].port,switch_leds[i].pin,GPIO_PIN_RESET);

        }


    }
};


float GetEnvTemp(){

    return envTemp;
}






const float B3950Temp[241]={
        -40, -39, -38, -37, -36, -35, -34, -33, -32, -31,
        -30, -29, -28, -27, -26, -25, -24, -23, -22, -21,
        -20, -19, -18, -17, -16, -15, -14, -13, -12, -11,
        -10, -9,  -8,  -7,  -6,  -5,  -4,  -3,  -2,  -1,
        0,    1,   2,   3,   4,   5,   6,   7,   8,   9,
        10,  11,  12,  13,  14,  15,  16,  17,  18,  19,
        20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
        30,  31,  32,  33,  34,  35,  36,  37,  38,  39,
        40,  41,  42,  43,  44,  45,  46,  47,  48,  49,
        50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
        60,  61,  62,  63,  64,  65,  66,  67,  68,  69,
        70,  71,  72,  73,  74,  75,  76,  77,  78,  79,
        80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
        90,  91,  92,  93,  94,  95,  96,  97,  98,  99,
        100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
        110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
        120, 121, 122, 123, 124, 125, 126, 127, 128, 129,
        130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
        140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
        150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
        160, 161, 162, 163, 164, 165, 166, 167, 168, 169,
        170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
        180, 181, 182, 183, 184, 185, 186, 187, 188, 189,
        190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200
};

const float temp[241]={
        277.2, 263.6, 250.1, 236.8, 224.0, 211.5, 199.6, 188.1, 177.3, 167.0,
        157.2, 148.1, 139.4, 131.3, 123.7, 116.6, 110.0, 103.7, 97.9,  92.50,
        87.43, 82.79, 78.44, 74.36, 70.53, 66.92, 63.54, 60.34, 57.33, 54.50,
        51.82, 49.28, 46.89, 44.62, 42.48, 40.45, 38.53, 36.70, 34.97, 33.33,
        31.77, 30.25, 28.82, 27.45, 26.16, 24.94, 23.77, 22.67, 21.62, 20.63,
        19.68, 18.78, 17.93, 17.12, 16.35, 15.62, 14.93, 14.26, 13.63, 13.04,
        12.47, 11.92, 11.41, 10.91, 10.45, 10.00, 9.575, 9.170, 8.784, 8.416,
        8.064, 7.730, 7.410, 7.106, 6.815, 6.538, 6.273, 6.020, 5.778, 5.548,
        5.327, 5.117, 4.915, 4.723, 4.539, 4.363, 4.195, 4.034, 3.880, 3.733,
        3.592, 3.457, 3.328, 3.204, 3.086, 2.972, 2.863, 2.759, 2.659, 2.564,
        2.472, 2.384, 2.299, 2.218, 2.141, 2.066, 1.994, 1.926, 1.860, 1.796,
        1.735, 1.677, 1.621, 1.567, 1.515, 1.465, 1.417, 1.371, 1.326, 1.284,
        1.243, 1.203, 1.165, 1.128, 1.093, 1.059, 1.027, 0.9955, 0.9654, 0.9363,
        0.9083, 0.8812, 0.8550, 0.8297, 0.8052, 0.7816, 0.7587, 0.7366, 0.7152, 0.6945,
        0.6744, 0.6558, 0.6376, 0.6199, 0.6026, 0.5858, 0.5694, 0.5535, 0.5380, 0.5229,
        0.5083, 0.4941, 0.4803, 0.4669, 0.4539, 0.4412, 0.4290, 0.4171, 0.4055, 0.3944,
        0.3835, 0.3730, 0.3628, 0.3530, 0.3434, 0.3341, 0.3253, 0.3167, 0.3083, 0.3002,
        0.2924, 0.2848, 0.2774, 0.2702, 0.2633, 0.2565, 0.2500, 0.2437, 0.2375, 0.2316,
        0.2258, 0.2202, 0.2148, 0.2095, 0.2044, 0.1994, 0.1946, 0.1900, 0.1855, 0.1811,
        0.1769, 0.1728, 0.1688, 0.1650, 0.1612, 0.1576, 0.1541, 0.1507, 0.1474, 0.1441,
        0.1410, 0.1379, 0.1350, 0.1321, 0.1293, 0.1265, 0.1239, 0.1213, 0.1187, 0.1163,
        0.1139, 0.1115, 0.1092, 0.1070, 0.1048, 0.1027, 0.1006, 0.0986, 0.0966, 0.0947,
        0.0928, 0.0909, 0.0891, 0.0873, 0.0856, 0.0839, 0.0822, 0.0806, 0.0790, 0.0774,
        0.0759, 0.0743, 0.0729, 0.0714, 0.0700, 0.0686, 0.0672, 0.0658, 0.0645, 0.0631, 0.0619
};
int findClosest(float target) {
    int index = 0;
    float minDiff = 1.0e37;

    for (int i = 0; i < 241; ++i) {
        float diff = fabs(temp[i] - target);
        if (diff < minDiff) {
            minDiff = diff;
            index = i;
        }
    }

    return index; // ????
}

float GetTemperature(float vol){
    float res= (3.3f-vol)/vol;

    int index=findClosest(res);
    return  B3950Temp[index];

};