#include "shutter.h"
#include "img_shutter.h"
#include "img_shutter_96.h"
#include "hidconsumer.h"

static uint8_t img_cnt = 0;
static uint16_t img_color;
#define IMG_NUM (img_shutter_96_height/img_shutter_96_width)
static void init(void *data) {
    img_cnt = 0;
}

static void enter(void *data) {
    // insert code
    UG_FillScreen(C_BLACK);
    img_color = tmos_rand() >> 8;
    LCD_DrawMonoXBMFast(16, 16, img_shutter_96_width, img_shutter_96_width, img_shutter_96_bits, img_color, BLACK);

    //
    manager_setBusy(false);
}

static void loop(void *data) {
    KEY_TYPE key;
    key = HAL_KeyGet();
    switch (key) {

    case KEY1_SHORT:
        hidEmuSendConsumerReport(VOL_DOWN, 0x00);
        hidEmuSendConsumerReport(0, 0);
        img_cnt = 0;
        img_color = tmos_rand() >> 8;
        manager_startEventOnce(10);
        break;

    case KEY1_LONG:

        manager_switchToParent();
        break;

    default:
        break;
    }
}

static void event(void *data) {
    if (img_cnt < IMG_NUM) {
        LCD_DrawMonoXBMFast(16, 16, img_shutter_96_width, img_shutter_96_width, &img_shutter_96_bits[1152 * img_cnt],
                img_color, BLACK);
        manager_startEventOnce(30);
        img_cnt++;
    }
}
static void quit(void *data) {
    // insert code

    manager_stopEvent();

    //
    manager_setBusy(true);
}

#include "img.h"
page_t page_shutter = { .init = init, .enter = enter, .exit = quit,
        .loop = loop, .event = event, .title_en = "shutter", .title_cn = "¿ìÃÅ",
        .icon = img_bits, .icon_width = img_width, .icon_height = img_height,
        .sleep_enable = false, .wakeup_btn_effect_enable = false, .acc_enable =
                false,

};
