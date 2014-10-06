#ifndef __RA_ESW_REG_H__
#define __RA_ESW_REG_H__

#include <asm/rt2880/rt_mmap.h>

/* ESW Registers Access */
#define _ESW_REG(x)			(*((volatile u32 *)(RALINK_ETH_SW_BASE + x)))

#if defined (CONFIG_RALINK_MT7620) && !defined (CONFIG_MT7530_GSW)
#define ESW_PORT_PPE			7
#define ESW_PORT_ID_MAX			7
#else
#undef  ESW_PORT_PPE
#define ESW_PORT_ID_MAX			6
#endif

#if defined (CONFIG_RALINK_MT7620) || defined (CONFIG_MT7530_GSW)

#define REG_ESW_PFC			0x04
#define REG_ESW_AISR			0x08
#define REG_ESW_AGC			0x0C
#define REG_ESW_MFC			0x10
#define REG_ESW_VTC			0x14
#define REG_ESW_ISC			0x18
#define REG_ESW_IMC			0x1C
#define REG_ESW_APC			0x20
#define REG_ESW_BPC			0x24

#define REG_ESW_WT_MAC_ATA1		0x74
#define REG_ESW_WT_MAC_ATA2		0x78
#define REG_ESW_WT_MAC_ATWD		0x7C
#define REG_ESW_WT_MAC_ATC		0x80
#define REG_ESW_TABLE_TSRA1		0x84
#define REG_ESW_TABLE_TSRA2		0x88
#define REG_ESW_TABLE_ATRD		0x8C

#define REG_ESW_VLAN_VTCR		0x90
#define REG_ESW_VLAN_VAWD1		0x94
#define REG_ESW_VLAN_VAWD2		0x98

#if !defined (CONFIG_MT7530_GSW)
#define REG_ESW_VLAN_ID_BASE		0x100
#endif

#define REG_ESW_PORT_SSC_P0		0x2000
#define REG_ESW_PORT_PCR_P0		0x2004
#define REG_ESW_PORT_PIC_P0		0x2008
#define REG_ESW_PORT_PSC_P0		0x200C
#define REG_ESW_PORT_PVC_P0		0x2010
#define REG_ESW_PORT_PPBV1_P0		0x2014
#define REG_ESW_PORT_PPBV2_P0		0x2018
#define REG_ESW_PORT_BSR_P0		0x201C
#define REG_ESW_PORT_TPF_P0		0x2030

#define REG_ESW_MAC_PMCR_P0		0x3000
#define REG_ESW_MAC_PMEEECR_P0		0x3004
#define REG_ESW_MAC_PMSR_P0		0x3008

#define REG_ESW_MAC_GMACCR		0x3FE0
#define REG_ESW_MAC_SMACCR0		0x3FE4
#define REG_ESW_MAC_SMACCR1		0x3FE8
#define REG_ESW_MAC_CKGCR		0x3FF0

#if defined (CONFIG_MT7530_GSW)
	// todo
#else
#define REG_ESW_MIB_ESR_P0		0x4000
#define REG_ESW_MIB_INTS_P0		0x4004
#define REG_ESW_MIB_INTM_P0		0x4008
#define REG_ESW_MIB_TGPC_P0		0x4010
#define REG_ESW_MIB_TBOC_P0		0x4014
#define REG_ESW_MIB_TGOC_P0		0x4018
#define REG_ESW_MIB_TEPC_P0		0x401C
#define REG_ESW_MIB_RGPC_P0		0x4020
#define REG_ESW_MIB_RBOC_P0		0x4024
#define REG_ESW_MIB_RGOC_P0		0x4028
#define REG_ESW_MIB_REPC1_P0		0x402C
#define REG_ESW_MIB_REPC2_P0		0x4030
#endif
#define REG_ESW_MIB_MIBCNTEN		0x4800

#define REG_ESW_IMR			0x7008
#define REG_ESW_ISR			0x700C
#define REG_ESW_CPC			0x7010
#define REG_ESW_GPC1			0x7014
#define REG_ESW_GPC2			0x701C

#define REG_ESW_MAX			0x7FFFF

/* ESW interrupt mask */
#define MIB_INT				BIT(25)
#define ACL_INT				BIT(24)
#define P6_LINK_CHG			BIT(6)
#define P5_LINK_CHG			BIT(5)
#define P4_LINK_CHG			BIT(4)
#define P3_LINK_CHG			BIT(3)
#define P2_LINK_CHG			BIT(2)
#define P1_LINK_CHG			BIT(1)
#define P0_LINK_CHG			BIT(0)
#if defined (CONFIG_MT7530_GSW)
#define ESW_INT_ALL			(P0_LINK_CHG | P1_LINK_CHG | P2_LINK_CHG | P3_LINK_CHG | P4_LINK_CHG)
#else
#define ESW_INT_ALL			(P0_LINK_CHG | P1_LINK_CHG | P2_LINK_CHG | P3_LINK_CHG | P4_LINK_CHG | \
					 ACL_INT | MIB_INT)
#endif

#define MSK_RX_FILTER_CNT		BIT(0)
#define MSK_RX_ARL_DROP_CNT		BIT(1)
#define MSK_RX_ING_DROP_CNT		BIT(2)
#define MSK_RX_CTRL_DROP_CNT		BIT(3)
#define MSK_RX_GOCT_CNT			BIT(4)
#define MSK_RX_GOOD_CNT			BIT(6)
#define MSK_RX_BAD_CNT			BIT(7)
#define MSK_TX_DROP_CNT			BIT(16)
#define MSK_TX_GOCT_CNT			BIT(17)
#define MSK_TX_GOOD_CNT			BIT(19)
#define MSK_TX_BAD_CNT			BIT(20)
#define ESW_MIB_INT_ALL			(MSK_RX_FILTER_CNT | MSK_RX_ARL_DROP_CNT | MSK_RX_CTRL_DROP_CNT | \
					 MSK_RX_GOCT_CNT | MSK_RX_GOOD_CNT | MSK_RX_BAD_CNT | \
					 MSK_TX_GOCT_CNT | MSK_TX_GOOD_CNT | MSK_TX_BAD_CNT | \
					 MSK_TX_DROP_CNT)

#elif defined (CONFIG_RALINK_RT3052) || defined (CONFIG_RALINK_RT3352) || \
      defined (CONFIG_RALINK_RT5350) || defined (CONFIG_RALINK_MT7628)

#define REG_ESW_ISR			0x00
#define REG_ESW_IMR			0x04
#define REG_ESW_TABLE_SEARCH		0x24
#define REG_ESW_TABLE_STATUS0		0x28
#define REG_ESW_TABLE_STATUS1		0x2C
#define REG_ESW_TABLE_STATUS2		0x30
#define REG_ESW_WT_MAC_AD0		0x34
#define REG_ESW_WT_MAC_AD1		0x38
#define REG_ESW_WT_MAC_AD2		0x3C
#define REG_ESW_VLAN_ID_BASE		0x50
#define REG_ESW_VLAN_MEMB_BASE		0x70
#define REG_ESW_POA			0x80
#define REG_ESW_STRT			0xA0

#if defined (CONFIG_RALINK_RT3052)
#define REG_ESW_MAX			0xFC
#else
#define REG_ESW_MAX			0x16C
#endif

/* ESW interrupt mask */
#define PORT0_QUEUE_FULL		BIT(14) //port0 queue full
#define PORT1_QUEUE_FULL		BIT(15) //port1 queue full
#define PORT2_QUEUE_FULL		BIT(16) //port2 queue full
#define PORT3_QUEUE_FULL		BIT(17) //port3 queue full
#define PORT4_QUEUE_FULL		BIT(18) //port4 queue full
#define PORT5_QUEUE_FULL		BIT(19) //port5 queue full
#define PORT6_QUEUE_FULL		BIT(20) //port6 queue full
#define SHARED_QUEUE_FULL		BIT(23) //shared queue full
#define QUEUE_EXHAUSTED			BIT(24) //global queue is used up and all packets are dropped
#define BC_STROM			BIT(25) //the device is undergoing broadcast storm
#define PORT_ST_CHG			BIT(26) //Port status change
#define UNSECURED_ALERT			BIT(27) //Intruder alert
#define ABNORMAL_ALERT			BIT(28) //Abnormal
#define ESW_INT_ALL			(PORT_ST_CHG)

#endif

#ifdef __KERNEL__
typedef union _ULARGE_INTEGER {
	struct {
		uint32_t LowPart;
		uint32_t HighPart;
	} u;
	uint64_t QuadPart;
} ULARGE_INTEGER;
#endif


#endif