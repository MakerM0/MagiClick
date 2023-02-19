const unsigned char gImage_shutter[512] = { /* 0X10,0X01,0X00,0X40,0X00,0X40, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XE0,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XE0,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XE0,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,
0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,
0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,
0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XF8,0X1F,0XE0,0X00,0X00,0X00,0X00,0X1F,
0XF8,0X1F,0XE0,0X00,0X00,0X00,0X00,0X1F,0XF8,0X1F,0XE0,0X00,0X0E,0X00,0X00,0X1F,
0XF8,0X1F,0XE0,0X00,0XFF,0XE0,0X00,0X1F,0XF8,0X1F,0XE0,0X03,0XFF,0XF8,0X00,0X1F,
0XF8,0X00,0X00,0X07,0XFF,0XFC,0X00,0X1F,0XF8,0X00,0X00,0X0F,0XFF,0XFE,0X00,0X1F,
0XF8,0X00,0X00,0X1F,0XFF,0XFF,0X00,0X1F,0XF8,0X00,0X00,0X3F,0XFF,0XFF,0X80,0X1F,
0XF8,0X00,0X00,0X3F,0XFF,0XFF,0X80,0X1F,0XF8,0X00,0X00,0X7F,0XFF,0XFF,0XC0,0X1F,
0XF8,0X00,0X00,0X7F,0XFF,0XFF,0XC0,0X1F,0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XC0,0X1F,
0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XC0,0X1F,0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XE0,0X1F,
0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XE0,0X1F,0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XE0,0X1F,
0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XE0,0X1F,0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XC0,0X1F,
0XF8,0X00,0X00,0X7F,0XFF,0XFF,0XC0,0X1F,0XF8,0X00,0X00,0X7F,0XFF,0XFF,0XC0,0X1F,
0XF8,0X00,0X00,0X7F,0XFF,0XFF,0X80,0X1F,0XF8,0X00,0X00,0X3F,0XFF,0XFF,0X80,0X1F,
0XF8,0X00,0X00,0X1F,0XFF,0XFF,0X00,0X1F,0XF8,0X00,0X00,0X1F,0XFF,0XFE,0X00,0X1F,
0XF8,0X00,0X00,0X0F,0XFF,0XFC,0X00,0X1F,0XF8,0X00,0X00,0X03,0XFF,0XF8,0X00,0X1F,
0XF8,0X00,0X00,0X01,0XFF,0XE0,0X00,0X1F,0XF8,0X00,0X00,0X00,0X3F,0X80,0X00,0X1F,
0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,
0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,
0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,
0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
};
