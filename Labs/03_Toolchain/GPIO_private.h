#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*Contains Magic Numbers in GPIO Module*/


#define GPIO_PERIPHERAL_NUM  		8U 			/* Number of GPIO PORT in Nucleo-f446 */

#define MODER_PIN_MASK 			0b11   		/* GPIO Mode Register 2 Bits MASK  	  */
#define MODER_PIN_ACCESS 			2U   		/* GPIO Mode Register 2 Bits Access   */

#define PUPDR_PIN_MASK 			0b11   		/* GPIO PUPD Register 2 Bits MASK     */
#define PUPDR_PIN_ACCESS 			2U   		/* GPIO PUPD Register 2 Bits Access	  */

#define OTYPER_PIN_MASK             0b1

#define OSPEEDR_PIN_MASK 			0b11   		/* GPIO OTYPE Register 2 Bits MASK     */
#define OSPEEDR_PIN_ACCESS 		2U   		/* GPIO OTYPE Register 2 Bits Access	  */

#define AFR_PIN_MASK 			0b1111   		/* GPIO AF Register 4 Bits MASK     */
#define AFR_PIN_ACCESS 			4U   		/* GPIO AF Register 4 Bits Access	  */


#endif /* GPIO_PRIVATE_H_ */
