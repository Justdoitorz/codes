#include <stdio.h>

typedef unsigned char   U8;
typedef unsigned short U16;
typedef unsigned long  U32;

typedef signed char   S8;
typedef signed short S16;
typedef signed long  S32;

#define IMAGE_STATUS_CONVERT_MAX_COUNT 56
#define CTRL_MAX_BITMAP_COUNT  20
#define CTRL_MAX_TEXT_COUNT 64
//ctrl parameter end
#define CTRL_LOGIC_TEXT_LEN 32
#define ATTR_BUF_MAX_LEN  32
#define LOGIC_INDEX_BUF_MAX_LEN 128
#define J1939INDEX_MULTI_MAX_COUNT 20
#define PROGBAR_COLOR_LIST_COUNT 3
#define CTRL_LOGIC_MAX_COUNT 10
#define DYNAMIC_CREATE_CTRL_EDIT_MAX_CHAR_LEN 20
#define DATA_SWITCH_LOGIC_COUNT 8

#define UI_MAX_COUNT 40
#define UI_MAX_CTRL_COUNT 800//384//800
#define MAX_LOGIC_INFO  1200//512//600
#define PIC_MAX_COUNT  800//256//800
#if defined(USE_IS25LP_64M_FLASH)
#define PIC_DATA_MAX_LEN  8*1024*1024
#else
#define PIC_DATA_MAX_LEN  (8*1024*1024)//12*1024*1024//2*1024*1024//11*1024*1024
#endif
#define MAX_CTRL_COUNT_PER_UI  100
#define LOGO_PIC_DATA_MAX_LEN (1124*1024)//512*1024
#define SUPPORT_FONT_COUNT 15//4
#define BIT_VALUE_J1939_COUNT 1024
#define BIT_VALUE_SENSOR_32_COUNT 50
#define BIT_VALUE_SENSOR_COUNT 510
#define AUDIO_MAX_COUNT  10
#define AUDIO_MAX_DATA_LEN  1024*1024//512*1024
#define DATA_UNIT_COUNT 128
#define DATA_UNIT_BUF_MAX_LEN 64
#define FAULT_QUERY_BUF_MAX_LEN 64
#define FAULT_QUERY_COUNT 200
#define TYRE_PRESS_STATUS_COUNT 3
#define TYPR_PRESS_STATUS_VALUE_LEN 2
#define STATUS_MAX_COUNT 4
#define STATUS_VALUE_LEN 2
#define LOGIC_INDEX_STR_LEN 4
#define MENU_ITEM_LINK_CTRL_MAX_COUNT  16
#define MENU_ITEM_LINK_CTRL_STR_INDEX_LEN  2
#define PROGRESS_RANGE_STR_FIX_LEN 5
#define FONT_TEXT_SIZE_FIX_LEN 5
#define FONT_TEXT_INDEX_FIX_LEN  5
#define CAMERA_CH_MAX   4
#define METER_DIAG_CONFIG_MAX_BUF_LEN  256
#define FRONT_DIAG_CONFIG_MAX_BUF_LEN  256
#define BACK_DIAG_CONFIG_MAX_BUF_LEN  256
#define TOP_DIAG_CONFIG_MAX_BUF_LEN  256
#define POWER_DIAG_CONFIG_MAX_BUF_LEN  256
#define POWER_CONTROL_DIAG_CONFIG_MAX_BUF_LEN  256
#define TPMS_SENSOR_COUNT  6  //????????????????????????
#define TPMS_TIME_OUT  20*1000  //?????????????????????????????????0s  1s=200ms
#define TRANSPARENT_COLOR  30  //????????????????????????????????????
#define MULTI_PERPAG_COUNT  5  //????????????????????????
#define DISPLAY_FLOAT_MAX_LEN  32 //????????????????????????

typedef enum{
	//rt1050
	CTRL_LOGIC_TYPE_BG_LOGIC_NONE = 0, //?????????
	CTRL_LOGIC_TYPE_BG_IMG_DISPLAY , //????????????
	CTRL_LOGIC_TYPE_MENU_SEL,   //????????????
	CTRL_LOGIC_TYPE_BG_TURN_PAGE, //??????
	CTRL_LOGIC_TYPE_FAULT_QUERY, //????????????
	CTRL_LOGIC_TYPE_PROGRESS,  //?????????
	CTRL_LOGIC_TYPE_SWITCH_CONVERT, //????????????
	CTRL_LOGIC_TYPE_IMAGE_STATUS_CONVERT,  //??????????????????
	CTRL_LOGIC_TYPE_SYS_PARA, //????????????
	CTRL_LOGIC_TYPE_VER_INFO, //????????????
	CTRL_LOGIC_TYPE_STATUS_CONVERT_TEXT_DISPLAY, //????????????????????????
	CTRL_LOGIC_TYPE_DATE_DISPLAY, //????????????
	CTRL_LOGIC_TYPE_TIME_DISPLAY, //????????????
	CTRL_LOGIC_TYPE_MULTI_PACKAGE_CONTENT, //????????????
	CTRL_LOGIC_TYPE_IMAGE_SETTING_PIC, //??????????????????
	CTRL_LOGIC_TYPE_PSW_SET, //????????????
	CTRL_LOGIC_TYPE_TPMS_STUDY_LOGIC, //??????????????????
	CTRL_LOGIC_TYPE_PILLOR, //??????
	CTRL_LOGIC_TYPE_DIGIT_DISPLAY, //????????????
	CTRL_LOGIC_TYPE_DATETIME_SETTING_SHOW, //????????????????????????
	CTRL_LOGIC_TYPE_J1939_DISPLAY, //J1939??????
	CTRL_LOGIC_TYPE_INTERNAL_DATA_DISPLAY, //??????????????????
	CTRL_LOGIC_TYPE_INTERNAL_32BIT_DISPLAY, //32?????????????????????
	CTRL_LOGIC_TYPE_CAMERA_IMG_DISPLAY, //?????????????????????
	CTRL_LOGIC_TYPE_DATA_SWITCH_DISPLAY, //???????????? ??????
	//RT1050 Define
	CTRL_LOGIC_TYPE_FIX_BMP_DISPLAY, //??????????????????
	CTRL_LOGIC_TYPE_PARA_INPUT_SETTING, //??????????????????
	CTRL_LOGIC_TYPE_FAULT_QUERY_TEXT_DISPLAY,//????????????????????????
	CTRL_LOGIC_TYPE_GIF_DISPLAY,//GIF????????????
}CTRL_LOGIC_TYPE;
typedef enum {
	CTRL_TYPE_UNKNOWN = 0,
	CTRL_TYPE_WINDOW,
	CTRL_TYPE_IMAGE,
	CTRL_TYPE_TEXT,
	CTRL_TYPE_PROGRESS,
	CTRL_TYPE_BUTTON,
    CTRL_TYPE_EDIT,
	CTRL_TYPE_LIST,
}CTRL_TYPE;
typedef enum{
	EMWIN_BUTTON_ADD = 0,
	EMWIN_TEXT_ADD,
	EMWIN_WINDOW_ADD,
	EMWIN_IMAGE_ADD,
	EMWIN_PROGBAR_ADD,
	EMWIN_LISBOX_ADD,
	EMWIN_LISTVIEW_ADD,
	EMWIN_SCROLLBAR_ADD,
	EMWIN_EDIT_ADD,
	EMWIN_SPIN_BOX_ADD,
	CTRL_NAME_ADD,
	CTRL_PRIVATE_DATA_ADD,
}DATA_FUNC_TYPE_ENUM;
typedef enum{
    LOGO_TYPE_GIF = 0,
    LOGO_TYPE_BMP,
}LOGO_TYPE_ENUM;

typedef enum{
	TURN_PAGE_INTERNAL = 0, //???????????????
	TRUN_PAGE_EXTERNAL = 1, //????????????
}TURN_PAGE_TYPE_ENUM;
typedef enum{
	TURN_PAGE_MODEL_METER = 1,
	TURN_PAGE_MODEL_FRONT = 2,
	TURN_PAGE_MODEL_BACK = 3,
	TURN_PAGE_MODEL_TOP = 4,
	TURN_PAGE_MODEL_POWER=5,
	TURN_PAGE_MODEL_POWER_MANATER = 9,
	TURN_PAGE_MODEL_HELP = 10,
}TURN_PAGE_MODEL_ENUM;


typedef enum{ //????????????
    MENU_ITEM_TYPE_UI = 0,
    MENU_ITEM_TYPE_CTRL,
    MENU_ITEM_TYPE_UNKNOWN,
}MENU_ITEM_TYPE_ENUM;
typedef enum{
	PARA_INPUT_TYPE_PICTURE = 0,
	PARA_INPUT_TYPE_CHANNEL,
	PARA_INPUT_TYPE_WIPER,
	PARA_INPUT_TYPE_VOLUME,
	PARA_INPUT_TYPE_BACKLIGHT,
	PARA_INPUT_TYPE_LIGHTSENSE,
	PARA_INPUT_TYPE_YEAR,
	PARA_INPUT_TYPE_MONTH,
	PARA_INPUT_TYPE_DAY,
	PARA_INPUT_TYPE_HOUR,
	PARA_INPUT_TYPE_MINUTE,
	PARA_INPUT_TYPE_SECOND,
	PARA_INPUT_TYPE_CAMERA_CONTRAST,
	PARA_INPUT_TYPE_CAMERA_BRIGHTNESS,
	PARA_INPUT_TYPE_CAMERA_CHROMA,
	PARA_INPUT_TYPE_CAMERA_CLARITY,
}PARA_INPUT_TYPE_ENUM;
typedef enum{
	VER_TYPE_METER = 1,
	VER_TYPE_FRONTDRIVER = 2,
	VER_TYPE_BACKDRIVER = 3,
	VER_TYPE_TOPDRIVER = 4,
	VER_TYPE_POWER = 5,
	VER_TYPE_CONFIG_SOFT_VER = 6,
	VER_TYPE_POWER_MANAGER_MODEL = 9,
    VER_TYPE_BOARD_SOFTWARE=10,//????????????????????????
    VER_TYPE_BOARD_SYSTEM=11,//?????????????????????
    VER_REMINDER_ONE=12,//??????1
    VER_REMINDER_TWO=13,//??????2
    VER_REMINDER_THREE=14,//??????3
}VER_TYPE_ENUM;
typedef enum {
	TEXT_DISPLAY_FORMAT_DEC = 0,
	TEXT_DISPLAY_FORMAT_BIN = 1,
	TEXT_DISPLAY_FORMAT_HEX = 2,
}TEXT_DISPLAY_FORMAT_ENUM;


typedef struct{
    LOGO_TYPE_ENUM logo_type;
    U16 picIndex;
    U32 offset;
    U32 picLen;
}LOGO_CONFIG_STRUCT;
/*CTRL_LOGIC_TYPE_BG_LOGIC_NONE ?????????*/

typedef struct {
	CTRL_LOGIC_TYPE type;
}CTRL_LOGIC_TYPE_BG_LOGIC_NONE_STRUCT;

typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 imgIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_BG_IMG_DISPLAY_STRUCT;
/*CTRL_LOGIC_TYPE_MENU_SEL ????????????*/
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 menuItemIndex;
	U32 menuItemPicIndex;
	U32 menuItemLinkType;//0,UI,1,Ctrl
	U32 menuItemLinkUIIndex;
	U32 menuItemLinkCtrlCount;
	U32 menuItemLinkCtrlIndex[MENU_ITEM_LINK_CTRL_MAX_COUNT];
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_MENU_SEL_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 totalTurnPages;
	TURN_PAGE_MODEL_ENUM turnPageModel;
	U32 totalLogicCount;
	U32 bgStartPicIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_BG_TURN_PAGE_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	//U32 dispMode;
	U32 totalLines;
	U32 picStartIndex;
	U16 page;
    U8 isLoop; //?????????????????? 0????????????
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_FAULT_QUERY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 DataIndex0;
	U16 DataMask0;
	U8  VH;
	U16 min;
	U16 max;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
	U32 bgColorIndex;
	U32 fgColorIndex;
	U32 alarmLow;
	U32 alarmHigh;
	U32 alarmFGColorIndex;
	//????????????????????????????????????
	U8 colorModeCount;
    U32 rangeMin[PROGBAR_COLOR_LIST_COUNT];
    U32 rangeMax[PROGBAR_COLOR_LIST_COUNT];
    U32 fgColorIndexList[PROGBAR_COLOR_LIST_COUNT];
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_PROGRESS_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 DataIndex0;
	U32 DataSrc1;
	U32 DataIndex1;
	U8  valueCount;
	U8  value[IMAGE_STATUS_CONVERT_MAX_COUNT];
	U32 bmpIndex[IMAGE_STATUS_CONVERT_MAX_COUNT];
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_SWITCH_CONVERT_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 DataIndex0;
	U16 DataMask0;
	U32 dispMode;
	U8  valueCount;
	U16  value[IMAGE_STATUS_CONVERT_MAX_COUNT];//modify U8 -->U16  wwb
	U32 bmpIndex[IMAGE_STATUS_CONVERT_MAX_COUNT];
    U32 picStartIndex;//??????????????????
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_IMAGE_STATUS_CONVERT_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U8 sysParaIndex;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
	U32 bgColorIndex;
	U8 textAlignModeIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_SYS_PARA_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	VER_TYPE_ENUM modeIndex;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
	U32 bgColorIndex;
	U32 textAlignModeIndex;
	U8 VerInfo[ATTR_BUF_MAX_LEN];
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_VER_INFO_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 DataIndex0;
	U16 DataMask0;
	U8 statusCount;
	U16 statusValue[STATUS_MAX_COUNT];//modify U8 -->u16 wwb
	U8 statusText[STATUS_MAX_COUNT][ATTR_BUF_MAX_LEN];
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
    U32 textAlignModeIndex;
	U32 bgColorIndex;
	U32 unitIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_STATUS_CONVERT_TEXT_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
    U32 textAlignModeIndex;
	U32 bgColorIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_DATE_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
    U32 textAlignModeIndex;
	U32 bgColorIndex;
	U8 timeFormat;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_TIME_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 multiPackageType;
	U8 currline;
	U8 displayContent;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
    U32 textAlignModeIndex;
	U32 bgColorIndex;
	U32 unitIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_MULTI_PACKAGE_CONTENT_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;

}CTRL_LOGIC_TYPE_IMAGE_SETTING_PIC_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U8 pswTextIndex;
	U16 page;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
    U32 textAlignModeIndex;
	U32 bgColorIndex;
	U16 x;
	U16 y;
	U16 w;
	U16 h;

}CTRL_LOGIC_TYPE_PSW_SET_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 DataIndex0;
	U8 tyreIndex;
	U8 tyreStatusCount;
	U16 tyreStatusValue[TYRE_PRESS_STATUS_COUNT];
	U16 tyreStatusPicIndex[TYRE_PRESS_STATUS_COUNT];
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_TPMS_STUDY_LOGIC_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 DataIndex0;
	U32 picTotalCount;
	U32 lowThreshold;
	U32 highThreshold;
	U32 picStartIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_PILLOR_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;

}CTRL_LOGIC_TYPE_DIGIT_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U8 dataTimeSelIndex;
	U16 fontSize;
        U16 fontIndex;
	U8 bgColorIndex;
	U8 textColorIndex;
    U32 textAlignModeIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_DATETIME_SETTING_SHOW_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataIndex0;
	U8 startBit0;
	U8 bitLen0;
	U32 DataIndex1;
	U8 startBit1;
	U8 bitLen1;
	TEXT_DISPLAY_FORMAT_ENUM dispMode;
	U32 valueMode;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
    U32 textAlignModeIndex;
	U32 bgColorIndex;
	U32 unitIndex;
	U32 DecimalFraction;
	U8 dataIndexMultiCount; //???????????????
	U32 DataIndexMulti[J1939INDEX_MULTI_MAX_COUNT];//???????????????
	U32 startBitMulti[J1939INDEX_MULTI_MAX_COUNT];//???????????????
	U32 bitLenMulti[J1939INDEX_MULTI_MAX_COUNT];//???????????????
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_J1939_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataIndex0;
	U32 dispMode;
	U16 fontSize;
        U16 fontIndex;
	U32 textColorIndex;
    U32 textAlignModeIndex;
	U32 bgColorIndex;
	U32 unitIndex;
	U32 DecimalFraction;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_INTERNAL_DATA_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U32 DataIndex0;
	U32 dispMode;
	U16 fontSize;
        U16 fontIndex;
	U8 textColorIndex;
    U32 textAlignModeIndex;
	U8 bgColorIndex;
	U32 unitIndex;
	U32 DecimalFraction;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_INTERNAL_32BIT_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_CAMERA_IMG_DISPLAY_STRUCT;
typedef struct {
	CTRL_LOGIC_TYPE type;
	U16 page;
	U16 fontSize;
        U16 fontIndex;
	U8 textColorIndex;
	U8 bgColorIndex;
	U8 logicCount;
	U16 logicIndex[DATA_SWITCH_LOGIC_COUNT];
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_DATA_SWITCH_DISPLAY_STRUCT;
typedef struct{
	CTRL_LOGIC_TYPE type;
	U32 bmpIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_FIX_BMP_DISPLAY_STRUCT;
typedef struct{
	CTRL_LOGIC_TYPE type;
	U32 paraTypeIndex;
	U32 cameraIndex;
	U16 fontSize;
        U16 fontIndex;
	U8 bgColorIndex;
	U8 textColorIndex;
    U32 textAlignModeIndex;
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_PARA_INPUT_SETTING_STRUCT;
typedef struct{
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 currLines;
	U32 textStartIndex;
	U16 fontSize;
        U16 fontIndex;
	U8 bgColorIndex;
	U8 textColorIndex;
    U32 textAlignModeIndex;
    U8 isLoop; //?????????????????? 0???????????????
	U16 page;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_FAULT_QUERY_TEXT_DISPLAY_STRUCT;
typedef struct{
	CTRL_LOGIC_TYPE type;
	U32 DataSrc0;
	U32 DataIndex0;
	U32 gifIndex;
	U16 max;
	U16 min;
	U16 gifDislayMode;//???????????? 0-??????????????????1-????????????
	U16 page;
	U16 gifSeqIndex;//??????????????????????????????
	U16 stillImageSlect; //?????????????????? 0-??????????????????1-??????GIF???????????????
	U16 bmpIndex;
	U16 x;
	U16 y;
	U16 w;
	U16 h;
}CTRL_LOGIC_TYPE_GIF_DISPLAY_STRUCT;



typedef union {
	CTRL_LOGIC_TYPE_BG_LOGIC_NONE_STRUCT logic_none;
	CTRL_LOGIC_TYPE_BG_IMG_DISPLAY_STRUCT bg_img_display;
	CTRL_LOGIC_TYPE_MENU_SEL_STRUCT menu_sel;
	CTRL_LOGIC_TYPE_BG_TURN_PAGE_STRUCT turn_page;
	CTRL_LOGIC_TYPE_FAULT_QUERY_STRUCT fault_query;
	CTRL_LOGIC_TYPE_PROGRESS_STRUCT progress;
	CTRL_LOGIC_TYPE_SWITCH_CONVERT_STRUCT switch_convert;
	CTRL_LOGIC_TYPE_IMAGE_STATUS_CONVERT_STRUCT image_status_convert;
	CTRL_LOGIC_TYPE_SYS_PARA_STRUCT sys_para;
	CTRL_LOGIC_TYPE_VER_INFO_STRUCT ver_info;
	CTRL_LOGIC_TYPE_STATUS_CONVERT_TEXT_DISPLAY_STRUCT status_convert_text_display;
	CTRL_LOGIC_TYPE_DATE_DISPLAY_STRUCT date_display;
	CTRL_LOGIC_TYPE_TIME_DISPLAY_STRUCT time_display;
	CTRL_LOGIC_TYPE_MULTI_PACKAGE_CONTENT_STRUCT multi_pkg_content;
	CTRL_LOGIC_TYPE_IMAGE_SETTING_PIC_STRUCT image_setting_pic;
	CTRL_LOGIC_TYPE_PSW_SET_STRUCT psw_set;
	CTRL_LOGIC_TYPE_TPMS_STUDY_LOGIC_STRUCT tpms_study_logic;
	CTRL_LOGIC_TYPE_PILLOR_STRUCT pillor;
	CTRL_LOGIC_TYPE_DIGIT_DISPLAY_STRUCT digit_display;
	CTRL_LOGIC_TYPE_DATETIME_SETTING_SHOW_STRUCT datetime_setting_show;
	CTRL_LOGIC_TYPE_J1939_DISPLAY_STRUCT j1939_display;
	CTRL_LOGIC_TYPE_INTERNAL_DATA_DISPLAY_STRUCT internal_data_display;
	CTRL_LOGIC_TYPE_INTERNAL_32BIT_DISPLAY_STRUCT internal_32bit_display;
	CTRL_LOGIC_TYPE_CAMERA_IMG_DISPLAY_STRUCT camera_img_display;
	CTRL_LOGIC_TYPE_DATA_SWITCH_DISPLAY_STRUCT data_switch_display;
	CTRL_LOGIC_TYPE_FIX_BMP_DISPLAY_STRUCT fix_bmp_display;
	CTRL_LOGIC_TYPE_PARA_INPUT_SETTING_STRUCT param_input_setting;
	CTRL_LOGIC_TYPE_FAULT_QUERY_TEXT_DISPLAY_STRUCT fault_query_text_display;
	CTRL_LOGIC_TYPE_GIF_DISPLAY_STRUCT gif_display;
}CTRL_LOGIC_TYPE_UNION;


typedef struct{
	CTRL_LOGIC_TYPE type;
	CTRL_LOGIC_TYPE_UNION type_union;
}CTRL_LOGIC_PARSE;

int main()
{

    printf("sizeof(CTRL_LOGIC_PARSE) = %d\r\n", sizeof(CTRL_LOGIC_PARSE));

    return 0;
}
