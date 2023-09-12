/********************** Author: Bassant Mohy Eldeen ******************************/
/********************** date: 29 aug 2023           ******************************/
/********************** version: 0.1                ******************************/
/*********************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLCK  RCC_HSE

/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */

#if RCC_SYSCLCK == RCC_HSE
#define RCC_CLCK_BYPASS   RCC_CRYSTAL_CLK_


/**
 * @brief Configure the number multiplied to RCC_SYSCLK when using RCC_PLL.
 * @note Choose one of the available options:
 * 
 *  PLL_BY2_     multiply the freq of RCC_SYSCLCK by 2
 *  PLL_BY3_     multiply the freq of RCC_SYSCLCK by 3
 *  PLL_BY4_     multiply the freq of RCC_SYSCLCK by 4
 *  PLL_BY5_     multiply the freq of RCC_SYSCLCK by 5
 *  PLL_BY6_     multiply the freq of RCC_SYSCLCK by 6
 *  PLL_BY7_     multiply the freq of RCC_SYSCLCK by 7
 *  PLL_BY8_     multiply the freq of RCC_SYSCLCK by 8
 *  PLL_BY9_     multiply the freq of RCC_SYSCLCK by 9
 *  PLL_BY10_    multiply the freq of RCC_SYSCLCK by 10
 *  PLL_BY11_    multiply the freq of RCC_SYSCLCK by112
 *  PLL_BY12_    multiply the freq of RCC_SYSCLCK by 12
 *  PLL_BY13_    multiply the freq of RCC_SYSCLCK by132
 *  PLL_BY14_    multiply the freq of RCC_SYSCLCK by142
 *  PLL_BY15_    multiply the freq of RCC_SYSCLCK by152
 *  PLL_BY16_    multiply the freq of RCC_SYSCLCK by162
 */

#elif RCC_SYSCLCK == RCC_PLL

#define PLL_MUL   PLL_BY2_
   
#endif 











#endif