#define img_width 64
#define img_height 64
static unsigned char img_bits[] = {
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFC,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X03,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFE,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X03,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFE,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X0F,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0X99,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0X1F,0XFF,
		0XFF,0XFF,0XFF,0X80,0X01,0XFF,0X0F,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X3F,0X87,0XFF,
		0XFF,0XFF,0XF8,0X00,0X00,0X1F,0XC3,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X07,0XE1,0XFF,
		0XFF,0XFF,0XC0,0X00,0X00,0X03,0XF0,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X01,0XF8,0X7F,
		0XFF,0XFF,0X00,0X00,0X00,0X01,0XFC,0X1F,0XFF,0XFE,0X00,0X00,0X00,0X00,0XFE,0X0F,
		0XFF,0XFE,0X00,0X00,0X00,0X00,0XFF,0X0F,0XFF,0XFC,0X00,0X00,0X00,0X00,0XFF,0X87,
		0XFF,0XF8,0X00,0X00,0X00,0X01,0XFF,0XCF,0XFF,0XF0,0X00,0X00,0X00,0X0F,0XFF,0XFF,
		0XFF,0XF0,0X00,0X00,0X00,0XF8,0XFF,0XFF,0XFF,0XE0,0X00,0X00,0X1F,0XC0,0X7F,0XFF,
		0XFF,0XE0,0X00,0X01,0XF8,0X00,0X3F,0XFF,0XFF,0XC0,0X00,0X3F,0XC0,0X00,0X3F,0XFF,
		0XFF,0XC0,0X03,0XFF,0X00,0X00,0X3F,0XFF,0XFF,0X80,0X1F,0XFC,0X00,0X00,0X3F,0XFF,
		0XFF,0X80,0X3F,0XE0,0X00,0X00,0X3F,0XFF,0XFF,0X00,0X7F,0X80,0X00,0X00,0X3F,0XFF,
		0XFF,0X00,0X7E,0X00,0X00,0X00,0X3F,0XFF,0XFE,0X00,0X30,0X00,0X00,0X00,0X3F,0XFF,
		0XFC,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,
		0XF0,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,
		0XE0,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,
		0XE0,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,
		0XF9,0X80,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X07,0XFF,0XFF,
		0XFF,0XFF,0X80,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XC0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
		};
