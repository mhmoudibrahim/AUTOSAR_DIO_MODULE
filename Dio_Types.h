
#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

#include "Std_Types.h"
#include "Dio_Cfg.h"

/*
 * Module Version 1.0.0
 */
#define DIO_TYPES_SW_MAJOR_VERSION              (1U)
#define DIO_TYPES_SW_MINOR_VERSION              (0U)
#define DIO_TYPES_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_TYPES_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_TYPES_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_TYPES_AR_RELEASE_PATCH_VERSION     (3U)


/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/* Structure for Dio_ChannelGroup */
typedef struct
{
  /* Mask which defines the positions of the channel group */
  uint8 mask;
  /* Position of the group from LSB */
  uint8 offset;
  /* This shall be the port on which the Channel group is defined. */
  Dio_PortType PortIndex;
} Dio_ChannelGroupType;

typedef struct
{
	uint8 Port_Num;
	uint8 Ch_Num;
}Dio_ConfigChannel;

typedef struct {

	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
	Dio_PortType Ports[DIO_CONFIGURED_PORTS];
    Dio_ChannelGroupType Groups[DIO_CONFIGURED_GROUPS];
} Dio_ConfigType ;


#endif /* DIO_TYPES_H_ */
