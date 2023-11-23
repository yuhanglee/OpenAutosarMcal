/**
 * @file    Port_Cfg.c
 * @brief   **Port driver configuration file**
 * @author  Daniel Byuerly, Diego Perez
 *
 * Configuration for Port driver, this file as per AUTOSAR indication is not application dependant
 * and shall be generated by a configuration tool. for the moent the files shall be written manually
 * by the user according its application. Also the user is responsible for setting the paramter in
 * the right way
 */
#include "Std_Types.h"
#include "Port_Types.h"
#include "Port_Cfg.h"


/**
 * @brief   **Port array with settings to configure**
 *
 * Array with the settings to configure the ports, this array shall be set by the user according to
 * the application needs, the user shall set the number of elements in the array in the
 * PORT_PIN_NUMBER_OF_PORTS macro, each index is not limited  to a scpecific port, the user can
 * configure the pins in any order, the only restriction is that the index shall be unique for each
 * pin, the user can use the PORTS_<pin_name>_PORT_<n>_PIN_<n> macros to set the index, the MSB
 * indicates the port index from the PortConfig array and the LSB indicates the pin number
 */
/* clang-format off */
const Port_ConfigType PortConfig[ PORT_PIN_NUMBER_OF_PORTS ] =
{
    {
        .Port        = PORTS_C,
        .Pins        = PORTS_PIN_00 | PORTS_PIN_01 | PORTS_PIN_02 | PORTS_PIN_03 | PORTS_PIN_04 | PORTS_PIN_05 | PORTS_PIN_06 | PORTS_PIN_07,
        .Pull        = PORTS_NOPULL,
        .OutputDrive = PORTS_PUSH_PULL,
        .Speed       = PORTS_LOW_SPEED,
        .Mode        = PORTS_MODE_OUTPUT
    }
    /*add more elements as needed but this shall match with PORT_PIN_NUMBER_OF_PORTS macro*/ 
};
/* clang-format on */