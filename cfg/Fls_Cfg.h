/**
 * @file    Fls_Cgf.h
 * @brief   **Flash Driver Configuration Header**
 * @author  Christopher Bogarin
 *
 * Configuration for the FLASH driver. This file, as per AUTOSAR guidelines, is not
 * application-dependent and should be generated by a configuration tool. For the moment,
 * the files shall be written manually by the user according to their application. Also,
 * the user is responsible for setting the parameter in the right way.
 *
 */
#ifndef FLASH_CFG_H__
#define FLASH_CFG_H__

#include "Fls_Types.h"

/**
 * @brief Enable / disable the Fls_Cancel() function.
 * @typedef EcucBooleanParamDef
 */
#define FLS_CANCEL_API         STD_ON

/**
 * @brief Enable / disable the Fls_GetStatus() function.
 * @typedef EcucBooleanParamDef
 */
#define FLS_GET_STATUS_API     STD_ON

/**
 * @brief Enable / disable the Fls_GetJobResult() function.
 * @typedef EcucBooleanParamDef
 */
#define FLS_GET_JOB_RESULT_API STD_ON

/**
 * @brief Enable / disable the Fls_Compare() function.
 * @typedef EcucBooleanParamDef
 */
#define FLS_COMPARE_API        STD_ON

/**
 * @brief Enable / disable the Fls_SetMode() function.
 * @typedef EcucBooleanParamDef
 */
#define FLS_SET_MODE_API       STD_ON

/**
 * @brief Enable / disable the Fls_BlankCheck() function.
 * @typedef EcucBooleanParamDef
 */
#define FLS_BLANK_CHECK_API    STD_ON

extern const Flash_ConfigType FlashConfig;

#endif