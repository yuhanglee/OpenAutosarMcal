/**
 * @file    Can_Lcfg.c
 * @brief   **Can Driver**
 * @author  Diego Perez
 *
 * This file contains the configuration structures for the CAN driver, this file as per AUTOSAR indication
 * is not application dependant and shall be generated by a configuration tool. for the moment the files
 * shall be written manually by the user according its application. Also the user is responsible for setting
 * the paramter in the right way.
 */
#include "Std_Types.h"
#include "Can_Cfg.h"
#include "Can_Arch.h"


/**
 * @brief Array with the configuration for each controller.
 */
/* clang-format off */
const Can_Controller Controllers[ CAN_NUMBER_OF_CONTROLLERS ] =
{
    {
        .FrameFormat = CAN_FRAME_CLASSIC,
        .BaudrateConfigsCount = CAN_NUMBER_OF_BAUDRATES_CTRL0
    },
    {
        .FrameFormat = CAN_FRAME_FD, 
        .BaudrateConfigsCount = CAN_NUMBER_OF_BAUDRATES_CTRL1
    } 
};
/* clang-format on */

/**
 * @brief Array with the configuration for each hardware object.
 */
/* clang-format off */
const Can_HardwareObject Hohs[ CAN_NUMBER_OF_HOHS ] =
{
    { 
        .ObjectType = CAN_HOH_TYPE_TRANSMIT,
        .ControllerRef = &Controllers[ CAN_CONTROLLER_0 ]
    },
    { 
        .ObjectType = CAN_HOH_TYPE_RECEIVE,
        .ControllerRef = &Controllers[ CAN_CONTROLLER_0 ]
    }, 
    { 
        .ObjectType = CAN_HOH_TYPE_TRANSMIT,
        .ControllerRef = &Controllers[ CAN_CONTROLLER_1 ]
    } 
};
/* clang-format on */

/**
 * @brief Can driver configuration.
 */
/* clang-format off */
const Can_ConfigType CanConfig =
{
    .Controllers = Controllers,
    .Hohs         = Hohs 
};
/* clang-format on */

/* clang-format off */
const Can_ControllerBaudrateConfig ArchBaudrates[ CANARCH_NUMBER_OF_BAUDRATES ] =
{
    {
        .BaudRateConfigID = CANARCH_BAUDRATE_100k_CLASSIC,
        .Seg1             = 13,
        .Seg2             = 2,
        .SyncJumpWidth    = 1,
        .Prescaler        = 4,
        .FdTxBitRateSwitch = STD_OFF,
    },
    {
        .BaudRateConfigID = CANARCH_BAUDRATE_100k_FD,
        .Seg1             = 13,
        .Seg2             = 2,
        .SyncJumpWidth    = 1,
        .Prescaler        = 4,
        .FdSeg1         = 13,
        .FdSeg2         = 2,
        .FdSyncJumpWidth = 1,
        .FdPrescaler     = 4,
        .FdTxBitRateSwitch = STD_ON,
    }

};
/* clang-format on */

/* clang-format off */
const Can_Controller ArchControllers[ CANARCH_NUMBER_OF_CONTROLLERS ] =
{
    {
        .ControllerId         = CANARCH_CONTROLLER_0, 
        .Mode                 = CAN_MODE_NORMAL,
        .FrameFormat          = CAN_FRAME_CLASSIC,
        .ClockDivider         = CAN_CLOCK_DIV10,
        .AutoRetransmission   = STD_OFF,
        .TransmitPause        = STD_ON,
        .ProtocolException    = STD_OFF,
        .TxFifoQueueMode      = CAN_TX_FIFO_OPERATION,
        .BaudrateConfigsCount = CAN_NUMBER_OF_BAUDRATES_CTRL0,
        .CanReference         = CAN_FDCAN1,
        .BaudrateConfigs      = ArchBaudrates,
        .DefaultBaudrate    = &ArchBaudrates[ CANARCH_BAUDRATE_100k_CLASSIC ]
    },
    {
        .ControllerId         = CANARCH_RESTRICTED_OPERATION,
        .Mode                 = CAN_MODE_RESTRICTED_OPERATION, 
        .FrameFormat          = CAN_FRAME_CLASSIC,
        .ClockDivider         = CAN_CLOCK_DIV10,
        .AutoRetransmission   = STD_OFF,
        .TransmitPause        = STD_ON,
        .ProtocolException    = STD_OFF,
        .TxFifoQueueMode      = CAN_TX_FIFO_OPERATION,
        .BaudrateConfigsCount = CAN_NUMBER_OF_BAUDRATES_CTRL1,
        .CanReference         = CAN_FDCAN1,
        .BaudrateConfigs      = ArchBaudrates,
        .DefaultBaudrate    = &ArchBaudrates[ CANARCH_BAUDRATE_100k_CLASSIC ]
    },
    {
        .ControllerId         = CANARCH_BUS_MONITORING,
        .Mode                 = CAN_MODE_BUS_MONITORING, 
        .FrameFormat          = CAN_FRAME_CLASSIC,
        .ClockDivider         = CAN_CLOCK_DIV10,
        .AutoRetransmission   = STD_OFF,
        .TransmitPause        = STD_ON,
        .ProtocolException    = STD_OFF,
        .TxFifoQueueMode      = CAN_TX_FIFO_OPERATION,
        .BaudrateConfigsCount = CAN_NUMBER_OF_BAUDRATES_CTRL1,
        .CanReference         = CAN_FDCAN1,
        .BaudrateConfigs      = ArchBaudrates,
        .DefaultBaudrate    = &ArchBaudrates[ CANARCH_BAUDRATE_100k_CLASSIC ]
    },
    {
        .ControllerId         = CANARCH_INTERNAL_LOOPBACK,
        .Mode                 = CAN_MODE_INTERNAL_LOOPBACK, 
        .FrameFormat          = CAN_FRAME_CLASSIC,
        .ClockDivider         = CAN_CLOCK_DIV10,
        .AutoRetransmission   = STD_OFF,
        .TransmitPause        = STD_ON,
        .ProtocolException    = STD_OFF,
        .TxFifoQueueMode      = CAN_TX_FIFO_OPERATION,
        .BaudrateConfigsCount = CAN_NUMBER_OF_BAUDRATES_CTRL1,
        .CanReference         = CAN_FDCAN1,
        .BaudrateConfigs      = ArchBaudrates,
        .DefaultBaudrate    = &ArchBaudrates[ CANARCH_BAUDRATE_100k_CLASSIC ] 
    },
    {
        .ControllerId         = CANARCH_EXTERNAL_LOOPBACK,
        .Mode                 = CAN_MODE_EXTERNAL_LOOPBACK, 
        .FrameFormat          = CAN_FRAME_CLASSIC,
        .ClockDivider         = CAN_CLOCK_DIV10,
        .AutoRetransmission   = STD_OFF,
        .TransmitPause        = STD_ON,
        .ProtocolException    = STD_OFF,
        .TxFifoQueueMode      = CAN_TX_FIFO_OPERATION,
        .BaudrateConfigsCount = CAN_NUMBER_OF_BAUDRATES_CTRL1,
        .CanReference         = CAN_FDCAN1,
        .BaudrateConfigs      = ArchBaudrates,
        .DefaultBaudrate    = &ArchBaudrates[ CANARCH_BAUDRATE_100k_CLASSIC ] 
    }
};
/* clang-format on */

/* clang-format off */
const Can_HwFilter ArchHwFilter[] =
{
    { 
        .HwFilterCode   = 0,
        .HwFilterMask   = 0,
        .HwFilterType   = CAN_FILTER_TYPE_RANGE,
        .HwFilterIdType = CAN_ID_EXTENDED 
    },
    { 
        .HwFilterCode   = 0,
        .HwFilterMask   = 0,
        .HwFilterType   = CAN_FILTER_TYPE_DUAL,
        .HwFilterIdType = CAN_ID_STANDARD 
    } 
};
/* clang-format on */

/* clang-format off */
const Can_HardwareObject ArchHohs[ CANARCH_NUMBER_OF_HOHS ] =
{
    {
        .CanObjectId = CANARCH_HTH_0_CTRL_0,
        .HandleType = CAN_FULL,
        .IdType = CAN_ID_STANDARD,
        .ObjectPayloadLength = 8u,
        .ObjectType = CAN_HOH_TYPE_TRANSMIT,
        .ControllerRef = &Controllers[ CANARCH_CONTROLLER_0 ]
    },
    {
        .CanObjectId = CANARCH_HRH_0_CTRL_0,
        .HandleType = CAN_FULL,
        .IdType = CAN_ID_STANDARD,
        .ObjectPayloadLength = 8u, 
        .ObjectType = CAN_HOH_TYPE_RECEIVE,
        .RxFifo = CAN_RX_FIFO0,
        .HwFilter = NULL_PTR,
        .ControllerRef = &Controllers[ CANARCH_CONTROLLER_0 ]
    },
    {
        .CanObjectId = CANARCH_HRH_1_CTRL_0,
        .HandleType = CAN_FULL,
        .IdType = CAN_ID_STANDARD,
        .ObjectPayloadLength = 8u,
        .ObjectType = CAN_HOH_TYPE_RECEIVE,
        .RxFifo = CAN_RX_FIFO0,
        .HwFilter = ArchHwFilter,
        .HwFilterCount = 2,
        .ObjectType = CAN_HOH_TYPE_RECEIVE,
        .ControllerRef = &Controllers[ CANARCH_CONTROLLER_0 ]
    }
};
/* clang-format on */


/**
 * @brief Can driver configuration.
 */
/* clang-format off */
const Can_ConfigType ArchCanConfig =
{
    .Controllers = ArchControllers,
    .ControllersCount = CANARCH_NUMBER_OF_CONTROLLERS,
    .Hohs         = ArchHohs,
    .HohsCount = CANARCH_NUMBER_OF_HOHS 
};
/* clang-format on */