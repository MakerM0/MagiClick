#define img_width 64
#define img_height 64
static unsigned char img_bits[] = {
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X1F,0XFF,0XFF,
        0XFF,0XFF,0XF8,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X1F,0XFF,0XFF,
        0XFF,0XFF,0XF8,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X1F,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X03,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFE,0X00,0X00,0X7F,0XDF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X1F,0X8F,0XFF,
        0XFF,0XFF,0XE0,0X00,0X00,0X07,0X07,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X02,0X03,0XFF,
        0XFF,0XFF,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X07,0XFF,
        0XFF,0XFC,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0X1F,0XFF,
        0XFF,0XF8,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X00,0X03,0XC0,0X00,0X0F,0XFF,
        0XFF,0XE0,0X00,0X07,0XE0,0X00,0X07,0XFF,0XFF,0XE0,0X00,0X07,0XE0,0X00,0X07,0XFF,
        0XFF,0XC0,0X00,0X07,0XE0,0X00,0X03,0XFF,0XFF,0XC0,0X00,0X07,0XE0,0X00,0X03,0XFF,
        0XFF,0X80,0X00,0X07,0XE0,0X00,0X01,0XFF,0XFF,0X80,0X00,0X07,0XE0,0X00,0X01,0XFF,
        0XFF,0X80,0X00,0X07,0XE0,0X00,0X01,0XFF,0XFF,0X80,0X00,0X07,0XE0,0X00,0X01,0XFF,
        0XFF,0X00,0X00,0X07,0XE0,0X00,0X00,0XFF,0XFF,0X00,0X00,0X07,0XE0,0X00,0X00,0XFF,
        0XFF,0X00,0X00,0X07,0XE0,0X00,0X00,0XFF,0XFF,0X00,0X00,0X07,0XE0,0X00,0X00,0XFF,
        0XFF,0X00,0X00,0X07,0XE0,0X00,0X00,0XFF,0XFF,0X00,0X00,0X07,0XE0,0X00,0X00,0XFF,
        0XFF,0X00,0X00,0X07,0XE0,0X00,0X00,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,
        0XFF,0X80,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X01,0XFF,
        0XFF,0X80,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0X03,0XFF,
        0XFF,0XC0,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X07,0XFF,
        0XFF,0XE0,0X00,0X00,0X00,0X00,0X07,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X0F,0XFF,
        0XFF,0XF0,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0X1F,0XFF,
        0XFF,0XFC,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X7F,0XFF,
        0XFF,0XFF,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X01,0XFF,0XFF,
        0XFF,0XFF,0XE0,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XFF,0XFF,
        0XFF,0XFF,0XFC,0X00,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X01,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XF8,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        };
