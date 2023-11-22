/**
 * @file    Gpt.c
 * @brief   **GPT driver configuration**
 * @author  Rodrigo Lopez
 *
 * The GPT driver provides services for starting and stopping timer channels (logical timer
 * instances assigned to a timer hardware), individual for each channel.
 *
 * The tick duration of a timer channel depends on channel specific settings (part of GPT driver)
 * as well as on system clock and settings of the clock tree controlled by the MCU module.
 */
#include "Bfx.h"
#include "Std_Types.h"
#include "Registers.h"
#include "Gpt.h"
#include "Gpt_Arch.h"

/**
 * @brief Initialize the GPT registers to the configuration stored on ConfigPtr.
 *
 * The function Gpt_Init shall initialize the hardware timer module according to a configuration
 * set referenced by ConfigPtr. The functions disables all interrupt notifications.
 *
 * Resources that are not configured in the configuration file are not touched.
 *
 * @param ConfigPtr       Pointer to ConfigPtr struct array.
 *
 * @reqs   SWS_Gpt_00280
 */
void Gpt_Init( const Gpt_ConfigType *ConfigPtr )
{
    for( uint8 ChannelsToInit = 0; ChannelsToInit < GPT_NUMBER_OF_CHANNELS; ChannelsToInit++ )
    {
        Gpt_Arch_Init( &ConfigPtr[ ChannelsToInit ] );
    }
}

/**
 * @brief Deinitializes the GPT driver.
 *
 * The function deinitializes the hardware used by the GPT driver (depending on configuration) to
 * the power on reset state. Values of registers which are not writeable are excluded.
 *
 * @reqs   SWS_Gpt_00281
 */
#if GPT_DEINIT_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
void Gpt_DeInit( void )
{
    Gpt_Arch_DeInit( );
}
#endif

/**
 * @brief Returns the time already elapsed.
 *
 * The function returns the time already elapsed. When the channel is in mode “one-shot mode”,
 * this is the value relative to the point in time, the channel has been started.
 *
 * @param Channel       Numeric identifier of the GPT channel.
 *
 * @retval  Returns the current number of ticks already elapsed.
 *
 * @reqs   SWS_Gpt_00282
 */
#if GPT_TIME_ELAPSED_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel )
{
    Gpt_Arch_GetTimeElapsed( Channel );
}
#endif

/**
 * @brief Returns the time remaining until the target time is reached.
 *
 * The function returns the timer value remaining until the target time will be reached next time.
 * he remaining time is the "target time" minus the time already elapsed.
 *
 * @param Channel       Numeric identifier of the GPT channel.
 *
 * @retval  Returns the remaining number of ticks before the timer overflows.
 *
 * @reqs   SWS_Gpt_00283
 */
#if GPT_TIME_REMAINING_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )
{
    Gpt_Arch_GetTimeRemaining( Channel );
}
#endif

/**
 * @brief Starts a timer channel.
 *
 * The function starts the selected timer channel with a defined target time. If configured and
 * enabled, an interrupt notification or a wakeup interrupt occurs, when the target time is reached.
 *
 * @param Channel       Numeric identifier of the GPT channel.
 * @param Value         Target time in number of ticks.
 *
 * @reqs   SWS_Gpt_00284
 */
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
    Gpt_Arch_StartTimer( Channel, Value );
}

/**
 * @brief Stops a timer channel.
 *
 * The function stops the selected timer channel.
 *
 * @param Channel       Numeric identifier of the GPT channel.
 *
 * @reqs   SWS_Gpt_00285
 */
void Gpt_StopTimer( Gpt_ChannelType Channel )
{
    Gpt_Arch_StopTimer( Channel );
}

/**
 * @brief Gets the current version.
 *
 * The function gives the versioninfo struct the values of the current version. to eneable this
 * function change the value of GPT_VERSION_INFO_API to STD_ON on the Gpt_Cfg file.
 *
 * @param versioninfo             Pointer to Std_VersionInfoType struct.
 *
 * @reqs   SWS_Gpt_00279
 */
#if GPT_VERSION_INFO_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
void Gpt_GetVersionInfo( Std_VersionInfoType *versioninfo )
{
    versioninfo->moduleID         = 0;
    versioninfo->sw_major_version = 0;
    versioninfo->sw_minor_version = 0;
    versioninfo->sw_patch_version = 0;
    versioninfo->vendorID         = 0;
}
#endif

/**
 * @brief Enables the interrupt notification for a channel.
 *
 * The function enables the interrupt notification of the referenced channel configured for
 * notification.
 *
 * @param Channel       Numeric identifier of the GPT channel.
 *
 * @reqs   SWS_Gpt_00286
 */
#if GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
void Gpt_EnableNotification( Gpt_ChannelType Channel )
{
    Gpt_Arch_EnableNotification( Channel );
}
#endif

/**
 * @brief Disables the interrupt notification for a channel.
 *
 * The function disables the interrupt notification of the referenced channel configured for
 * notification.
 *
 * @param Channel       Numeric identifier of the GPT channel.
 *
 * @reqs   SWS_Gpt_00287
 */
#if GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
void Gpt_DisableNotification( Gpt_ChannelType Channel )
{
    Gpt_Arch_DisableNotification( Channel );
}
#endif

/**
 * @brief Executes the callback function defined by the user on the GPT_CHANNEL_0,
 * validating the interrupt flag and turning it off afterwards.
 *
 * The notification prototype Gpt_Notification_Channel0 is for the notification callback function
 * and shall be implemented by the user. The callback notifications Gpt_Notification_<channel> shall
 * be configurable as pointers to user defined functions within the configuration structure.
 *
 * @reqs   SWS_Gpt_00292
 */
#if GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
void Gpt_Notification_Channel0( void )
{
    Gpt_Arch_Notification_Channel0( );
}
#endif

/**
 * @brief Executes the callback function defined by the user on the GPT_CHANNEL_1,
 * validating the interrupt flag and turning it off afterwards.
 *
 * The notification prototype Gpt_Notification_Channel1 is for the notification callback function
 * and shall be implemented by the user. The callback notifications Gpt_Notification_<channel> shall
 * be configurable as pointers to user defined functions within the configuration structure.
 *
 * @reqs   SWS_Gpt_00292
 */
#if GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON /* cppcheck-suppress misra-c2012-20.9 ; it is necesary to use a define for this function */
void Gpt_Notification_Channel1( void )
{
    Gpt_Arch_Notification_Channel1( );
}
#endif
