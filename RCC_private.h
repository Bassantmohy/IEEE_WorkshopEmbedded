/********************** Author: Bassant Mohy Eldeen ******************************/
/********************** date: 29 aug 2023           ******************************/
/********************** version: 0.1                ******************************/
/*********************************************************************************/

/*******************************RCC_Regs******************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
#define RCC_BASE_ADDRESS  0x40021000
#define RCC_CR           (*(volatile u32 *)RCC_BASE_ADDRESS+0x00)
#define RCC_CFGR         (*(volatile u32 *)RCC_BASE_ADDRESS+0x04)
#define RCC_CIR          (*(volatile u32 *)RCC_BASE_ADDRESS+0x08)
#define RCC_APB2RSTR     (*(volatile u32 *)RCC_BASE_ADDRESS+0x0C)
#define RCC_APB1RSTR     (*(volatile u32 *)RCC_BASE_ADDRESS+0x010)
#define RCC_AHBENR       (*(volatile u32 *)RCC_BASE_ADDRESS+0x14)
#define RCC_APB2ENR      (*(volatile u32 *)RCC_BASE_ADDRESS+0x18)
#define RCC_APB1ENR      (*(volatile u32 *)RCC_BASE_ADDRESS+0x1C)
#define RCC_BDCR         (*(volatile u32 *)RCC_BASE_ADDRESS+0x20)
#define RCC_CSR          (*(volatile u32 *)RCC_BASE_ADDRESS+0x24)


/******************************<RCC_CR_BITs*************************************/

#define RCC_CR_HSION             0         /***<Internal High Speed clock enable***/
#define RCC_CR_HSIRDY            1         /***<Internal high-speed clock ready flag***/
#define RCC_CR_HSEON             16        /***<External high speed clock enable***/
#define RCC_CR_HSERDY            17        /***<External high-speed clock ready flag***/
#define RCC_CR_HSEBYP            18        /***<External high-speed clock bypass***/
#define RCC_CR_CSSON             19        /***<Clock security system enable***/
#define RCC_CR_PLLON             24        /***<PLL enable***/
#define RCC_CR_PLLRDY            25        /***<PLL clock ready flag***/
#define RCC_HSI                  0   /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE                  1   /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL                  2   /**< Phase-Locked Loop Clock Source (PLL) */

/** @} */ // end of RCC_Clock_Source

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK_    0   /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_         1   /**< RC Oscillator Clock Type */

/**
 * @defgroup PLL_MUL Values
 * 
 */

#define PLL_BY2_      2
#define PLL_BY3_      3
#define PLL_BY4_      4
#define PLL_BY5_      5
#define PLL_BY6_      6
#define PLL_BY7_      7
#define PLL_BY8_      8
#define PLL_BY9_      9
#define PLL_BY10_     10
#define PLL_BY11_     11
#define PLL_BY12_     12
#define PLL_BY13_     13
#define PLL_BY14_     14
#define PLL_BY15_     15
#define PLL_BY16_     16

/** @} */ // end of RCC_Clock_Type



#endif /* RCC_PRIVATE_H_ */






#endif