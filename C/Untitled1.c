#include <stdio.h>

#define  CAN0_PC_SOURCE_ID                0x01
#define  CAN0_METER_SOURCE_ID             0x02
#define  CAN0_FRONT_SOURCE_ID             0x03
#define  CAN0_BACK_SOURCE_ID              0x04
#define  CAN0_TOP_SOURCE_ID               0x05
#define  CAN0_POWER_SOURCE_ID             0x07
#define  CAN0_POWER_CONTOROL_ID           0X0A

#define  CAN0_SWITCH_PANEL_SOURCE_ID      0x08

#define  CAN0_360_VIDEO_ID                0x80
#define  CAN0_BOARDCAST_INT_ID            0x00
#define  CAN0_BOARDCAST_EXT_ID            0xFF


// Enumerate func code
#define FUNC_DOWNLOAD_CODE					0x01
#define FUNC_ACTUAL_SW_CODE					0x02
#define FUNC_VIRTUAL_SW_CODE				0x03
#define FUNC_LOAD_CODE						0x04
#define FUNC_SENSOR_CODE					0x05
#define FUNC_SYS_CFG_CODE					0x07
#define FUNC_MOD_VER_CODE					0x08
#define FUNC_PARA_SET_CODE					0x0A







// Enumerate sub code :FUNC_DOWNLOAD_CODE
#define SUB_DL_PREPARE					0x01
#define SUB_DL_REBOOT    				0x02
#define SUB_DL_FINISH   				0x07
#define SUB_DL_QUERY_CFGINFO_START		0x0A












#define CAN_NET_DST_MASK    0xFF
#define CAN_NET_DST_SHIFT	21
#define CAN_NET_DST_GEN(x)	((x & CAN_NET_DST_MASK) << CAN_NET_DST_SHIFT)

#define CAN_NET_FUNC_MASK    0x1FF
#define CAN_NET_FUNC_SHIFT	12
#define CAN_NET_FUNC_GEN(x)	((x & CAN_NET_FUNC_MASK) << CAN_NET_FUNC_SHIFT)

#define CAN_NET_SUB_MASK    0x0F
#define CAN_NET_SUB_SHIFT	8
#define CAN_NET_SUB_GEN(x)	((x & CAN_NET_SUB_MASK) << CAN_NET_SUB_SHIFT)

#define CAN_NET_SRC_MASK    0xFF
#define CAN_NET_SRC_SHIFT	0
#define CAN_NET_SRC_GEN(x)	((x & CAN_NET_SRC_MASK) << CAN_NET_SRC_SHIFT)


#define MAKE_CAN_ID(dst, func, sub, src)	(CAN_NET_DST_GEN(dst) |\
											 CAN_NET_FUNC_GEN(func) |\
											 CAN_NET_SUB_GEN(sub) |\
											 CAN_NET_SRC_GEN(src) )

#define GET_SEPARATION(id, start, mask)		(id >> start & mask)
#define GET_DST_ID(id)					GET_SEPARATION(id, CAN_NET_DST_SHIFT, CAN_NET_DST_MASK)
#define GET_FUNC_CODE(id)				GET_SEPARATION(id, CAN_NET_FUNC_SHIFT, CAN_NET_FUNC_MASK)
#define GET_SUB_CODE(id)				GET_SEPARATION(id, CAN_NET_SUB_SHIFT, CAN_NET_SUB_MASK)
#define GET_SRC_ID(id)					GET_SEPARATION(id, CAN_NET_SRC_SHIFT, CAN_NET_SRC_MASK)


int main()
{

    printf("0x%08X\n", MAKE_CAN_ID(CAN0_PC_SOURCE_ID, FUNC_DOWNLOAD_CODE, SUB_DL_QUERY_CFGINFO_START, CAN0_SWITCH_PANEL_SOURCE_ID));

    return 0;
}
