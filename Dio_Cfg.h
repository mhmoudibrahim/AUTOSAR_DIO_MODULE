/*
 * Dio_Cfg.h
 *
 *  Created on: Aug 4, 2019
 *      Author: lenovo
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)


/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES             (4U)
#define DIO_CONFIGURED_PORTS                (3U)
#define DIO_CONFIGURED_GROUPS               (1U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_LED2_CHANNEL_ID_INDEX        (uint8)0x01
#define DioConf_BUTTON1_CHANNEL_ID_INDEX     (uint8)0x02
#define DioConf_BUTTON2_CHANNEL_ID_INDEX     (uint8)0x03

/* ChannelGroup Index in the array of structures in Dio_PBcfg.c */
#define DioConf_RGP_CHANNEL_GROUP_INDEX     (uint8)0x00
/* ChannelGroup macros in Dio_PBcfg.c */
#define DioConf_RGB_CHANNEL_GROUP           &Dio_Configuration.Groups[0]

/* DIO Configured Port channel group Mask */
#define DioConf_RGB_CHANNEL_GROUP_MASK       (uint8)0b11100000

/* DIO Configured Port channel group offset */
#define DioConf_RGB_CHANNEL_GROUP_OFFSET       (uint8)0x05

/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                (Dio_PortType)2 /* PORTC */
#define DioConf_LED2_PORT_NUM                (Dio_PortType)3 /* PORTD */
#define DioConf_BUTTON1_PORT_NUM             (Dio_PortType)0 /* PORTA */
#define DioConf_BUTTON2_PORT_NUM             (Dio_PortType)1 /* PORTB */
#define DioConf_RGB_PORT_NUM                 (Dio_PortType)0 /* PORTA */

/* DIO Configured Channel ID's */
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)3 /* Pin 3 in PORTC */
#define DioConf_LED2_CHANNEL_NUM             (Dio_ChannelType)6 /* Pin 6 in PORTD */
#define DioConf_BUTTON1_CHANNEL_NUM          (Dio_ChannelType)2 /* Pin 2 in PORTA */
#define DioConf_BUTTON2_CHANNEL_NUM          (Dio_ChannelType)4 /* Pin 4 in PORTB */
#endif /* DIO_CFG_H_ */
