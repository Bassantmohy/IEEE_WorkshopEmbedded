/********************** Author: Bassant Mohy Eldeen ******************************/
/********************** date: 29 aug 2023           ******************************/
/********************** version: 0.1                ******************************/
/*********************************************************************************/

/***************************************< LIB*************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************************< MCAL************************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Std_ReturnType Mcal_Rcc_InitSysClck(void)
{
    Std_ReturnType LocalFunctionStatus = E_Not_Ok;
    #if RCC_SYSCLCK == RCC_HSE 
    #if RCC_CLCK_BYPASS == RCC_RC_CLCK_
    SET_BIT(RCC_CR,RCC_CR_HSEBYP); /**< choose RC as SYSCLCK*/
    #elif RCC_CLCK_BYPASS == RCC_CRYSTAL_CLK_
    CLR_BIT(RCC_CR,RCC_CR_HSEBYP); /**< Choose the crystal as SYSCLCK*/
    #else
    #error "Wrong Choice!"
    #endif
    /**
     * @brief Enable external high speed clock
     * 
     */

      SET_BIT(RCC_CR,RCC_CR_HSEON);

      /**
       * @brief wait for stability
       * 
       */

      while (!(GET_BIT(RCC_CR,RCC_CR_HSERDY)));
    
      RCC_CFGR = 0x00000002;
      LocalFunctionStatus = E_Ok;

      #elif RCC_SYSCLCK == RCC_HSI
    SET_BIT(RCC_CR,RCC_CR_HSION); /**< Enable internal clock*/
    while (!(GET_BIT(RCC_CR,RCC_CR_HSIRDY))); /**wait for stabilit*/
     RCC_CFGR = 0x00000000;
     LocalFunctionStatus = E_Ok;

     #elif RCC_SYSCLCK == RCC_PLL
     SET_BIT(RCC_CR,RCC_CR_PLLON);
     while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY));
     switch (PLL_MU)
     {
     case PLL_BY2_:
        RCC_CFGR = 0x00000004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY3_:
        RCC_CFGR = 0x00040004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY4_:
        RCC_CFGR = 0x00080004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY5_:
        RCC_CFGR = 0x000C0004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY6_:
        RCC_CFGR = 0x00010004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY7_:
        RCC_CFGR = 0x00140004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY8_:
        RCC_CFGR = 0x00180004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY9_:
        RCC_CFGR = 0x001C0004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY10_:
        RCC_CFGR = 0x00200004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY11_:
        RCC_CFGR = 0x00240004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY12_:
        RCC_CFGR = 0x00280004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY13_:
        RCC_CFGR = 0x002C0004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY14_:
        RCC_CFGR = 0x00300004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY15_:
        RCC_CFGR = 0x00340004;
        LocalFunctionStatus = E_Ok;
        break;
    case PLL_BY16_:
        RCC_CFGR = 0x00380004;
        LocalFunctionStatus = E_Ok;
        break;
     default:
     #error "wrong cjoice!!"
     LocalFunctionStatus = E_Not_Ok;
        break;
     }
    


      #endif
    


    return LocalFunctionStatus;
}

Std_ReturnType Mcal_Rcc_EnablePeriphu8 (Copy_BusId, u8 Copy_PeripheralId)
{
 Std_ReturnType LocalFunctionStatus = E_Not_Ok;
 switch (Copy_BusId)
 {
 case RCC_AHB:
 SET_BIT(RCC_AHBENR, Copy_PeripheralId);
     LocalFunctionStatus = E_Ok;
     break;
     case RCC_APB1:
         SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
     LocalFunctionStatus = E_Ok;
     break;
     case RCC_APB2:
         SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
     LocalFunctionStatus = E_Ok;
     break;

     default:
     LocalFunctionStatus = E_Not_Ok;
     break;
 }
    return LocalFunctionStatus;  
}

Std_ReturnType Mcal_Rcc_DisablePeriph(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType LocalFunctionStatus = E_Not_Ok;
    switch (Copy_BusId)
 {
 case RCC_AHB:
 CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
     LocalFunctionStatus = E_Ok;
     break;
     case RCC_APB1:
         CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
     LocalFunctionStatus = E_Ok;
     break;
     case RCC_APB2:
         CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
     LocalFunctionStatus = E_Ok;
     break;

     default:
     LocalFunctionStatus = E_Not_Ok;
     break;
 }
    return LocalFunctionStatus;
}