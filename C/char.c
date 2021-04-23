#include <stdio.h>

#define QUEUE_SIZE (32)

unsigned char buf[QUEUE_SIZE] = {
   0x00, 0x00, 0x09, 0x00, 0x18, 0x5A, 0,
   0x55, 0x55, 0xAA, 0x00, 0x0D, 0x02, 0x00, 0x00, 0x09, 0x00, 0x18, 0x55,
   0, 0, 0, 0, 0, 0, 0,
   0x55, 0x55, 0xAA, 0x00, 0x0D, 0x02,
};



typedef enum {
	HEAD_0X55 = 1,
	HEAD_0XAA,
	CMD_1,
	CMD_2,
	LEN_L,
	LEN_H,
	FRAME_IDX,
	DATA,
	CRC,
	END_0X5A,
}PARSE_FLOW;

int rd = 7;
int wt = 6;

#define NEXT() 		uf++;
#define RESET()		if (fast != -1) b = fast; uf = HEAD_0X55;


int parse()
{
	static PARSE_FLOW uf = HEAD_0X55;
	static int cmd, len, frame, cnt, crc, fast = -1, begin, end;
	int finish = 0;
	int b = rd;
	printf("rd = %d, wt = %d\n", rd, wt);
	int e = wt;
	while (b != e && !finish) {
        //printf("b = %d\n", b);
		unsigned char ch = buf[b];
		//printf("buf[%d] = 0x%02X\n", b, ch);
        if (uf != HEAD_0X55 && fast == -1 && ch == 0x55) {
            int next = (b+1) % QUEUE_SIZE;
            if (next != e && buf[next] == 0xAA) {
                fast = b;
            }
		}
		b = (b+1) % QUEUE_SIZE;
		//printf("uf = %d\n", uf);
		switch (uf) {
		case HEAD_0X55: if (ch == 0x55) {fast = -1; uf++;}
		break;
		case HEAD_0XAA: if (ch == 0xAA) {crc = 0; uf++;} else {if (fast >= 0) b = fast; uf = HEAD_0X55;}
		break;
		case CMD_1:   crc += ch; cmd = ch; uf++;
		break;
		case CMD_2:	  crc += ch; cmd |= ch << 8; uf++;
		break;
		case LEN_L:   crc += ch;len = ch; uf++;
		break;
		case LEN_H:   crc += ch;len |= ch << 8; uf++; cnt = len;
		break;
		case FRAME_IDX: crc += ch; frame = ch; uf++; begin = b;
		break;
		case DATA:		crc += ch; if (--cnt == 0) uf++;
		break;
		case CRC:		end = b-2; if (crc == ch) {uf++;} else {if (fast >= 0) b = fast, fast = -1; uf = HEAD_0X55;}
		break;
		case END_0X5A:  uf = HEAD_0X55; if (ch == 0x5A) {finish = END_0X5A;} else {if (fast >= 0) b = fast; uf = HEAD_0X55;}
		break;
		default: printf("WTF!!!!!!!!!\n");
		break;
		}

	}
    rd = b;

    if (finish) {
        printf("cmd = 0x%04X\r\n", cmd);
        printf("len = %d\r\n", len);
        printf("frame_idx = 0x%02X\r\n", frame);
        printf("crc = 0x%02X\r\n", crc);
        printf("begin = %d, end = %d\n", begin, end);
    }
	return finish;
}


typedef struct {
	char *pcrc;
	char *pcmdorlen;
	int *pfast;
	int *pb;
}Param_t;

int callback_head_0x55(char ch, void *param,  PARSE_FLOW *pf)
{

    *pf += (0x55 == ch);
	return 0;
}

int callback_head_0xAA(char ch, void *param,  PARSE_FLOW *pf)
{
    Param_t *p = (Param_t *)param;
    if (0xAA == ch) {
        *p->pcrc = 0;
        *pf += 1;
    } else {
        if (*p->pfast != -1) {
            *p->pb = *p->pfast;
        }
        *pf -= 1;
    }
    return 0;
}

int callback_end_0x5A(char ch, void *param,  PARSE_FLOW *pf)
{
     Param_t *p = (Param_t *)param;
	*pf = HEAD_0X55;
	if (0x5A == ch) {
		return 1;
	} else {
		if (*p->pfast >= 0) {
			*p->pb = *p->pfast;
		}
		return 0;
	}
}

int callback_crc(char ch, void *param,  PARSE_FLOW *pf)
{
     Param_t *p = (Param_t *)param;
	if (*p->pcrc == ch) {
		*pf += 1;
	} else {
		if (*p->pfast >= 0) {
			*p->pb = *p->pfast;
		}
	}
	return 0;
}

int foo(char ch, void *param,  PARSE_FLOW *pf)
{
	Param_t *p = (Param_t *)param;
    *p->pcrc += ch;
    *p->pcmdorlen = ch;
    *pf += 1;
    return 0;
}

int main()
{
    rd = 0; wt = 31;
    printf("parse() = %d\n", parse());
    wt = 8;
    printf("parse() = %d\n", parse());
    printf("parse() = %d\n", parse());
}
